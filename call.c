/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libs.h"
#include "defs.h"

extern struct sizeInfo instSize[MAX_OPCODES];

void callALU(const struct memorySchema instToExecute){
int i,functionIndex = -1;
char tmp[20];
strcpy(tmp,instToExecute.instruction);

for(i=0;i<MAX_OPCODES;i++)
{
if(strcmp(extractZeroth(tmp),instSize[i].opcode) == 0)
{
functionIndex = i;
break;
}
}

switch (functionIndex){

case 0 : ACI(instToExecute);
		break;

case 1 : ADC(instToExecute);
		break;

case 2 : ADD(instToExecute);
		break;

case 3 : ADI(instToExecute);
		break;

case 4 : ANA(instToExecute);
		break;

case 5 : ANI(instToExecute);
		break;

case 6 : CALL(instToExecute);
		break;

case 7 : CC(instToExecute);
		break;

case 8 : CNC(instToExecute);
		break;

case 9 : CP(instToExecute);
		break;

case 10 : CM(instToExecute);
		break;

case 11 : CPE(instToExecute);
		break;

case 12 : CPO(instToExecute);
		break;

case 13 : CZ(instToExecute);
		break;

case 14 : CNZ(instToExecute);
		break;

case 15 : CMA(instToExecute);
		break;

case 16 : CMC(instToExecute);
		break;

case 17 : CMP(instToExecute);
		break;

case 18 : CPI(instToExecute);
		break;

case 19 : DAA(instToExecute);
		break;

case 20 : DAD(instToExecute);
		break;

case 21 : DCR(instToExecute);
		break;

case 22 : DCX(instToExecute);
		break;

case 23 : DI(instToExecute);
		break;

case 24 : EI(instToExecute);
		break;

case 25 : HLT(instToExecute);
		break;

case 26 : IN(instToExecute);
		break;

case 27 : INR(instToExecute);
		break;

case 28 : INX(instToExecute);
		break;

case 29 : JMP(instToExecute);
		break;

case 30 : JC(instToExecute);
		break;

case 31 : JNC(instToExecute);
		break;

case 32 : JP(instToExecute);
		break;

case 33 : JM(instToExecute);
		break;

case 34 : JPE(instToExecute);
		break;

case 35 : JPO(instToExecute);
		break;

case 36 : JZ(instToExecute);
		break;

case 37 : JNZ(instToExecute);
		break;

case 38 : LDA(instToExecute);
		break;

case 39 : LDAX(instToExecute);
		break;

case 40 : LHLD(instToExecute);
		break;

case 41 : LXI(instToExecute);
		break;

case 42 : MOV(instToExecute);
		break;

case 43 : MVI(instToExecute);
		break;

case 44 : NOP(instToExecute);
		break;

case 45 : ORA(instToExecute);
		break;

case 46 : ORI(instToExecute);
		break;

case 47 : OUT(instToExecute);
		break;

case 48 : PCHL(instToExecute);
		break;

case 49 : POP(instToExecute);
		break;

case 50 : PUSH(instToExecute);
		break;

case 51 : RAL(instToExecute);
		break;

case 52 : RAR(instToExecute);
		break;

case 53 : RLC(instToExecute);
		break;

case 54 : RRC(instToExecute);
		break;

case 55 : RET(instToExecute);
		break;

case 56 : RC(instToExecute);
		break;

case 57 : RNC(instToExecute);
		break;

case 58 : RP(instToExecute);
		break;

case 59 : RM(instToExecute);
		break;

case 60 : RPE(instToExecute);
		break;

case 61 : RPO(instToExecute);
		break;

case 62 : RZ(instToExecute);
		break;

case 63 : RNZ(instToExecute);
		break;

case 64 : RIM(instToExecute);
		break;

case 65 : RST(instToExecute);
		break;

case 66 : SBB(instToExecute);
		break;

case 67 : SBI(instToExecute);
		break;

case 68 : SHLD(instToExecute);
		break;

case 69 : SIM(instToExecute);
		break;

case 70 : SPHL(instToExecute);
		break;

case 71 : STA(instToExecute);
		break;

case 72 : STAX(instToExecute);
		break;

case 73 : STC(instToExecute);
		break;

case 74 : SUB(instToExecute);
		break;

case 75 : SUI(instToExecute);
		break;

case 76 : XCHG(instToExecute);
		break;

case 77 : XRA(instToExecute);
		break;

case 78 : XRI(instToExecute);
		break;

case 79 : XTHL(instToExecute);
		break;
default : printf("bye here");
	exit(0);
}
}

