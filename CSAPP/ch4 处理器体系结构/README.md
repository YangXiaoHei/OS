

# 取指阶段

* `PredictPC` 组合逻辑的输入有 3 个：
   * `word valP` : 取指后自增的下一条指令起始地址
   * `word valC` : 条件分支成立的指令地址，或者 `call` 的目的地址
   * `4bit f_icode` : 取指阶段产生的指令 `icode`

~~~C
word f_predPC = {
	# 对于 if 判断，我们总是选择条件成立的分支
	# 对于 call 指令，我们总是执行跳转
	f_icode in { IJXX, ICALL } : f_valC;
	
	# 否则使用自增 valP
	1 : valP
}
~~~

* `SelectPC` 组合逻辑的输入有 6 个：
   * `4bit M_icode` : 刚刚执行阶段的指令 `icode`
   * `word M_valA` : 这个字是 `ICALL` 或者 `IJXX` 等指令的 `valC`
   * `1bit M_Cnd`  : 这个布尔值是执行阶段条件码是否为真
   * `4bit W_icode` : 刚刚访存阶段的指令 `icode`
   * `word W_valM` : 这个字是 `IRET` 指令从内存中读出来的返回地址
   * `word F_predPC` : 这个字是从 `PredictPC` 组合逻辑中流入的值。

~~~C
word f_pc = {
	# 如果时钟上升沿到来，执行阶段的 e_icode 加载到了 M_icode 中，
	# 执行阶段产生的条件码加载到了 M_Cnd 中，当发现 M_Cnd 为假，说明预测错误。
	# 因为我们总是默认条件成立，所以此时下一条指令的地址应当选择 M_valA, 
	# 即 ICALL、IJXX 指令的自增 valP，即 M_valA
	M_icode == IJXX && !M_Cnd : M_valA;
	
	# 如果经过执行阶段的指令不是 IJXX，或者条件成立，说明一开始我们就蒙对了。
	# 那么我们来看经历过访存阶段的指令是啥，如果是 IRET，此时必定产生了一个
	# 从内存读出的返回地址，即 m_valM，此时 m_valM 已被加载到 W_valM 中，
	# 因此下一条指令的地址应当选择 W_valM
	W_icode == IRET : W_valM;
	
	# 如果即没有分支预测错误，经历过访存阶段的指令也不是 IRET，那么如何取下一条地址呢？
	# 直接使用 f_predPC，即此时已经加载到 F_predPC 的值就好了
	1 : F_predPC;
}
~~~

~~~C
word f_icode = {
	imem_error : INOP;
	1 : imem_icode;
}
~~~

~~~C
word f_ifun = {
	imem_error : FNONE;
	1 : imem_ifun;
}
~~~

~~~C
bool instr_valid = f_icode in { INOP, IHALT, IRRMOVQ, IIRMOVQ, IMRMOVQ, IOPQ, IJXX, ICALL, IRET, IPUSHQ, IPOPQ }
~~~

~~~C
word f_stat = {
	imem_error : SADR;
	!instr_valid : SINS;
	f_icode == IHALT : SHLT;
	1 : SAOK;
}
~~~

* `PC 增加` 模块的输入有 3 个：
    * `1bit need_valC` : 是否需要立即数 
    * `1bit need_regids` : 是否需要寄存器
    * `word f_pc` : 由 `SelectPC` 选出的下一条指令的地址，是 `PC 增加` 模块的基准，在此之上，再判断是否需要立即数，是否需要寄存器。

~~~C
bool need_valC = {
	f_icode in { IIRMOVQ, IRMMOVQ, IMRMOVQ, ICALL, IJXX }
}
~~~

# 译码阶段

~~~C
word d_srcA = {
	D_icode in { IRRMOVQ, IRMMOVQ, IOPQ, IPUSHQ } : D_rA;
	D_icode in { IPOPQ, IRET } : RRSP;
	1 : RNONE;
}
~~~

~~~C
word d_srcB = {
	D_icode in { IOPQ, IRMMOVQ, IMRMOVQ } : D_rB;
	D_icode in { IPUSHQ, IPOPQ, IRETQ, ICALL } : RRSP;
	1 : RNONE;
}
~~~

~~~C
word d_dstE = {
	D_icode in { IOPQ, IRRMOVQ, IIRMOVQ } : D_rB;
	D_icode in { IPUSHQ, ICALL, IRET, IPOPQ } : RRSP;
	1 : RNONE;
}
~~~

~~~C
word d_dstM = {
	D_icode in { IMRMOVQ, IPOPQ } : D_rA;	1 : RNONE;
}
~~~

~~~C
word d_valA = { 
	D_icode in { ICALL, IJXX } : D_valP;
	d_srcA == e_dstE : e_valE;
	d_srcA == M_dstM : m_valM;
	d_srcA == M_dstE : M_valE;
	d_srcA == W_dstM : W_valM;
	d_srcA == W_dstE : W_valE;
	1 : d_rvalA;	
}
~~~

~~~C
word d_valB = {
	d_srcB == e_dstE : e_valE;
	d_srcB == M_dstM : m_valM;
	d_srcB == M_dstE : M_valE;
	d_srcB == W_dstM : W_valM;
	d_srcB == W_dstE : W_valE;
	1 : d_rvalB;
}
~~~

# 执行阶段

~~~C
word aluA = {
	E_icode in { IRRMOVQ, IOPQ } : E_valA;
	E_icode in { IIRMOVQ, IRMMOVQ, IMRMOVQ } : E_valC;
	E_icode in { ICALL, IPUSHQ } : -8;
	E_icode in { IRET, IPOPQ } : 8;
}
~~~

~~~C
word aluB = {
	E_icode in { IRMMOVQ, IMRMOVQ, IOPQ, ICALL, IPUSHQ, IRET, IPOPQ } : E_valB;
	E_icode in { IRRMOVQ, IIRMOVQ } : 0;
}
~~~

~~~C
word alufun = {
	E_icode == IOPQ : E_ifun;
	1 : ALUADD;
}
~~~

~~~C
bool set_cc = E_icode == IOPQ && !m_stat in { SADR, SINS, SHLT } && !W_stat in { SADR, SINS, SHLT }; 
~~~

~~~C
word e_valA = E_valA;
~~~

~~~C
word e_dstE = {
	E_icode == IRRMOVQ && !e_Cnd : RNONE;
	1 : E_dstE;
}
~~~

# 访存阶段 

~~~C
word mem_addr = {
	M_icode in { IRMMOVQ, IMRMOVQ, IPUSHQ, ICALL } : M_valE;
	M_icode in { IPOPQ, IRET } : M_valA;
}
~~~

~~~C
bool mem_read = M_icode in { IMRMOVQ, IRET, IPOPQ };
~~~

~~~C
bool mem_write = M_icode in { IRMMOVQ, ICALL, IPUSHQ };
~~~

~~~C
word m_stat = {
	dmem_error : SADR;
	1 : M_stat;
}
~~~

~~~C
word w_dstE = W_dstE;
word w_valE = W_valE;
word w_dstM = W_dstM;
word w_valM = W_valM;
~~~

~~~C
word Stat = {
	W_stat == SBUB : SAOK;
	1 : W_stat;
}
~~~

# 流水线寄存器控制逻辑 

~~~C
bool F_bubble = 0;
~~~

~~~C
bool F_stall = 

// 加载/使用 冒险
E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB } 
||
// ret 指令
IRET in { D_icode, E_icode, M_icode };
~~~

~~~C
bool D_stall = 

// 加载/使用 冒险
E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB };
~~~
 
~~~C
bool D_bubble = 

// 预测错误
(E_icode == IJXX && !e_Cnd) 
||
// ret 指令
!(E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB }) && IRET IN { D_icode, E_icode, M_icode };
~~~
	
~~~C
bool E_stall = 0;
~~~

~~~C
bool E_bubble =
 
// 预测错误
(E_icode == IJXX && !e_Cnd) 
||
// 加载/使用 冒险
E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB };
~~~

~~~C
bool M_stall = 0;
~~~

~~~C
bool M_bubble = m_stat in { SADR, SINS, SHLT } || W_stat in { SADR, SINS, SHLT };
~~~

~~~C
bool W_stall = W_stat in { SADR, SINS, SHLT };
~~~

~~~C
bool W_bubble = 0;  
~~~





















