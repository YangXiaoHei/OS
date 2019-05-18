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
	
}


~~~





















