~~~C
########### 取指阶段 ################

word f_pc = {
	M_icode == IJXX && !M_Cnd : M_valA;
	W_icode == IRET : W_valM;
	1 : F_predPC;
}

word f_predPC = {
	f_icode in { IJXX, ICALL } : f_valC;
	1 : valP
}

word f_icode = {
	imem_error : INOP;
	1 : imem_icode;
}

word f_ifun = {
	imem_error : FNONE;
	1 : imem_ifun;
}

bool instr_valid = f_icode in { INOP, IHALT, IRRMOVQ, IIRMOVQ, IMRMOVQ, IOPQ, IJXX, ICALL, IRET, IPUSHQ, IPOPQ }

word f_stat = {
	imem_error : SADR;
	!instr_valid : SINS;
	f_icode == IHALT : SHLT;
	1 : SAOK;
}

bool need_valC = {
	f_icode in { IIRMOVQ, IRMMOVQ, IMRMOVQ, ICALL, IJXX }
}

############### 译码阶段 ###############

word d_srcA = {
	D_icode in { IRRMOVQ, IRMMOVQ, IOPQ, IPUSHQ } : D_rA;
	D_icode in { IPOPQ, IRET } : RRSP;
	1 : RNONE;
}

word d_srcB = {
	D_icode in { IOPQ, IRMMOVQ, IMRMOVQ } : D_rB;
	D_icode in { IPUSHQ, IPOPQ, IRETQ, ICALL } : RRSP;
	1 : RNONE;
}

word d_dstE = {
	D_icode in { IOPQ, IRRMOVQ, IIRMOVQ } : D_rB;
	D_icode in { IPUSHQ, ICALL, IRET, IPOPQ } : RRSP;
	1 : RNONE;
}

word d_dstM = {
	D_icode in { IMRMOVQ, IPOPQ } : D_rA;	1 : RNONE;
}

word d_valA = { 
	D_icode in { ICALL, IJXX } : D_valP;
	d_srcA == e_dstE : e_valE;
	d_srcA == M_dstM : m_valM;
	d_srcA == M_dstE : M_valE;
	d_srcA == W_dstM : W_valM;
	d_srcA == W_dstE : W_valE;
	1 : d_rvalA;	
}

word d_valB = {
	d_srcB == e_dstE : e_valE;
	d_srcB == M_dstM : m_valM;
	d_srcB == M_dstE : M_valE;
	d_srcB == W_dstM : W_valM;
	d_srcB == W_dstE : W_valE;
	1 : d_rvalB;
}

############# 执行阶段 ################
word aluA = {
	E_icode in { IRRMOVQ, IOPQ } : E_valA;
	E_icode in { IIRMOVQ, IRMMOVQ, IMRMOVQ } : E_valC;
	E_icode in { ICALL, IPUSHQ } : -8;
	E_icode in { IRET, IPOPQ } : 8;
}

word aluB = {
	E_icode in { IRMMOVQ, IMRMOVQ, IOPQ, ICALL, IPUSHQ, IRET, IPOPQ } : E_valB;
	E_icode in { IRRMOVQ, IIRMOVQ } : 0;
}

word alufun = {
	E_icode == IOPQ : E_ifun;
	1 : ALUADD;
}

bool set_cc = E_icode == IOPQ && !m_stat in { SADR, SINS, SHLT } && !W_stat in { SADR, SINS, SHLT }; 

word e_valA = E_valA;

word e_dstE = {
	E_icode == IRRMOVQ && !e_Cnd : RNONE;
	1 : E_dstE;
}

############# 访存阶段 ##############

word mem_addr = {
	M_icode in { IRMMOVQ, IMRMOVQ, IPUSHQ, ICALL } : M_valE;
	M_icode in { IPOPQ, IRET } : M_valA;
}

bool mem_read = M_icode in { IMRMOVQ, IRET, IPOPQ };

bool mem_write = M_icode in { IRMMOVQ, ICALL, IPUSHQ };

word m_stat = {
	dmem_error : SADR;
	1 : M_stat;
}

word w_dstE = W_dstE;
word w_valE = W_valE;
word w_dstM = W_dstM;
word w_valM = W_valM;

word Stat = {
	W_stat == SBUB : SAOK;
	1 : W_stat;
}

############## 流水线寄存器控制逻辑 ##############

bool F_bubble = 0;
bool F_stall = 

// 加载/使用 冒险
E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB } 
||
// ret 指令
IRET in { D_icode, E_icode, M_icode };

bool D_stall = 

// 加载/使用 冒险
E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB };
 
bool D_bubble = 

// 预测错误
(E_icode == IJXX && !e_Cnd) 
||
// ret 指令
!(E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB }) && IRET IN { D_icode, E_icode, M_icode };
	
bool E_stall = 0;
bool E_bubble =
 
// 预测错误
(E_icode == IJXX && !e_Cnd) 
||
// 加载/使用 冒险
E_icode in { IMRMOVQ, IPOPQ } && E_dstM in { d_srcA, d_srcB };

bool M_stall = 0;
bool M_bubble = m_stat in { SADR, SINS, SHLT } || W_stat in { SADR, SINS, SHLT };

bool W_stall = W_stat in { SADR, SINS, SHLT };
bool W_bubble = 0;  
~~~





















