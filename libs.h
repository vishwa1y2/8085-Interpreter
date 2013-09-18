/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/


#ifndef _LIBS_H_
#define _LIBS_H_

#include "defs.h"

void getUserCodeCmd(void);


int getLastInstSize(char *inst);

int searchSymbolTable(char *opcode);

void init(void );

int tokenInLastInstruction(int index);

void printAllRegisters(int debug);

void printProgram(void);

int instInInstruction(const char *tmp);

char * extractZeroth(char str[]);

char * extractFirst(char str[]);

char * extractSecond(char str[]);

void callALU(const struct memorySchema);

int hexToInt(const char *);

void executeProgram(int debug);

void execCALL(int );

void takeSingleInstruction(void);

int returnIndex(long int);

int powfunc(int , int );

void popStack();

void initGoto();

void pushStack();

void setAFlags(void );

void setRegisterPairs(void );

int generateFlagRegister(void);

void setFlagsForCMP(unsigned int *);

void setFlags(int);

void saveProgram(char *);

void openProgram(char *);

void ACI(struct memorySchema);

void ADC(struct memorySchema);

void ADD(struct memorySchema);

void ADI(struct memorySchema);

void ANA(struct memorySchema);

void ANI(struct memorySchema);

void CALL(struct memorySchema);

void CC(struct memorySchema);

void CNC(struct memorySchema);

void CP(struct memorySchema);

void CM(struct memorySchema);

void CPE(struct memorySchema);

void CPO(struct memorySchema);

void CZ(struct memorySchema);

void CNZ(struct memorySchema);

void CMA(struct memorySchema);

void CMC(struct memorySchema);

void CMP(struct memorySchema);

void CPI(struct memorySchema);

void DAA(struct memorySchema);

void DAD(struct memorySchema);

void DCR(struct memorySchema);

void DCX(struct memorySchema);

void DI(struct memorySchema);

void EI(struct memorySchema);

void HLT();

void IN(struct memorySchema);

void INR(struct memorySchema);

void INX(struct memorySchema);

void JMP(struct memorySchema);

void JC(struct memorySchema);

void JNC(struct memorySchema);

void JP(struct memorySchema);

void JM(struct memorySchema);

void JPE(struct memorySchema);

void JPO(struct memorySchema);

void JZ(struct memorySchema);

void JNZ(struct memorySchema);

void LDA(struct memorySchema);

void LDAX(struct memorySchema);

void LHLD(struct memorySchema);

void LXI(struct memorySchema);

void MOV(struct memorySchema);

void MVI(struct memorySchema);

void NOP(struct memorySchema);

void ORA(struct memorySchema);

void ORI(struct memorySchema);

void OUT(struct memorySchema);

void PCHL(struct memorySchema);

void POP(struct memorySchema);

void PUSH(struct memorySchema);

void RAL(struct memorySchema);

void RAR(struct memorySchema);

void RLC(struct memorySchema);

void RRC(struct memorySchema);

void RET();

void RC(struct memorySchema);

void RNC(struct memorySchema);

void RP(struct memorySchema);

void RM(struct memorySchema);

void RPE(struct memorySchema);

void RPO(struct memorySchema);

void RZ(struct memorySchema);

void RNZ(struct memorySchema);

void RIM(struct memorySchema);

void RST(struct memorySchema);

void SBB(struct memorySchema);

void SBI(struct memorySchema);

void SHLD(struct memorySchema);

void SIM(struct memorySchema);

void SPHL(struct memorySchema);

void STA(struct memorySchema);

void STAX(struct memorySchema);

void STC(struct memorySchema);

void SUB(struct memorySchema);

void SUI(struct memorySchema);

void XCHG(struct memorySchema);

void XRA(struct memorySchema);

void XRI(struct memorySchema);

void XTHL(struct memorySchema);

int checkParity(int);
#endif
