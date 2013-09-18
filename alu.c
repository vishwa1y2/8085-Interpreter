/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "libs.h"

extern unsigned int B;	

extern unsigned int C;

extern unsigned int D;			

extern unsigned int E;			

extern unsigned int H;			

extern unsigned int L;			

extern unsigned int A;			

extern  int BC;

extern  int DE;			

extern  int HL;			

extern long int callStack[100];
extern int topCallStack;
			

extern unsigned int SP;


extern long  int PC;

extern short int FLAGS[FLAG_SIZE];

extern struct sizeInfo instSize[MAX_OPCODES];

extern struct memorySchema vector[];

extern struct stackSchema stackVector[];

extern struct dataSchema dataVector[];

extern int programSize;


void ACI(struct memorySchema instToExecute){

	char num[4];
	strcpy(num,extractFirst(instToExecute.instruction));

	int n = hexToInt(num);

	A +=  n + FLAGS[CARRY];

	setAFlags();
}

void ADC(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	A = 2*A + FLAGS[CARRY];	
	FLAGS[CARRY] = 0;	
	setAFlags();
	}
	else if(strcmp(num,"B") == 0)
	{
	A = A + B + FLAGS[CARRY];		
	FLAGS[CARRY] = 0;	
	setAFlags();
	}
	else if(strcmp(num,"C") == 0)
	{
	A = A + C + FLAGS[CARRY];		
	FLAGS[CARRY] = 0;
	setAFlags();	
	}
	else if(strcmp(num,"D") == 0)		
	{
	A = A + D + FLAGS[CARRY];		
	FLAGS[CARRY] = 0;
	setAFlags();	}	
	else if(strcmp(num,"E") == 0)
	{
	A = A + E + FLAGS[CARRY];		
	FLAGS[CARRY] = 0;
	setAFlags();
	}
	else if(strcmp(num,"H") == 0)
	{
	A = A + H + FLAGS[CARRY];		
	FLAGS[CARRY] = 0;
	setAFlags();
	}
	else if(strcmp(num,"L") == 0)
	{
	A = A + L + FLAGS[CARRY];		
	FLAGS[CARRY] = 0;
	setAFlags();
	}
	else if(strcmp(num,"M") == 0)
	{
		A = A + dataVector[HL - DATA_REGION_START].dataHex + FLAGS[CARRY];
		FLAGS[CARRY] = 0;
		setAFlags();			
	}
setRegisterPairs();
}

void ADD(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	A = 2*A ;		
	setAFlags();	
	}
	else if(strcmp(num,"B") == 0)
	{
	A = A + B;		
	setAFlags();	
	}
	else if(strcmp(num,"C") == 0)
	{
	A = A + C ;		
	setAFlags();	
	}
	else if(strcmp(num,"D") == 0)		
	{
	A = A + D ;
	setAFlags();	
	}	
	else if(strcmp(num,"E") == 0)
	{
	A = A + E ;		
	setAFlags();
	}
	else if(strcmp(num,"H") == 0)
	{
	A = A + H ;		
	setAFlags();
	}
	else if(strcmp(num,"L") == 0)
	{
	A = A + L ;		
	setAFlags();
	}
	else if(strcmp(num,"M") == 0)
	{
		A = A + dataVector[HL - DATA_REGION_START].dataHex;
		FLAGS[CARRY] = 0;
		setAFlags();		
	}
setRegisterPairs();
}

void ADI(struct memorySchema instToExecute){
	char num[4];
	strcpy(num,extractFirst(instToExecute.instruction));
	int n = hexToInt(num);
	A +=  n ;
	setAFlags();
}

void ANA(struct memorySchema instToExecute){

	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	A = A & A ;		
	setAFlags();	
	}
	else if(strcmp(num,"B") == 0)
	{
	A = A & B;		
	setAFlags();	
	}
	else if(strcmp(num,"C") == 0)
	{
	A = A & C ;		
	setAFlags();	
	}
	else if(strcmp(num,"D") == 0)		
	{
	A = A & D ;
	setAFlags();	
	}	
	else if(strcmp(num,"E") == 0)
	{
	A = A & E ;		
	setAFlags();
	}
	else if(strcmp(num,"H") == 0)
	{
	A = A & H ;		
	setAFlags();
	}
	else if(strcmp(num,"L") == 0)
	{
	A = A & L ;		
	setAFlags();
	}
	else if(strcmp(num,"M") == 0)
	{
		A = A & dataVector[HL - DATA_REGION_START].dataHex;
		setAFlags();		
			
	}

}

void ANI(struct memorySchema instToExecute){

	char num[4];
	strcpy(num,extractFirst(instToExecute.instruction));

	int n = hexToInt(num);
		
	A = A & n ;
	setAFlags();
}

void CALL(struct memorySchema instToExecute){
extern int inCall;
char addr[5];

strcpy(addr,extractFirst(instToExecute.instruction));
int ad;
inCall = 1;
ad = hexToInt(addr);
pushStack();
PC = ad;

}

void CC(struct memorySchema instToExecute){

}

void CNC(struct memorySchema instToExecute){

}

void CP(struct memorySchema instToExecute){

}

void CM(struct memorySchema instToExecute){

}

void CPE(struct memorySchema instToExecute){

}

void CPO(struct memorySchema instToExecute){

}

void CZ(struct memorySchema instToExecute){

}

void CNZ(struct memorySchema instToExecute){

}

void CMA(struct memorySchema instToExecute){
A = ~A;
A = A & 0XFF;
}

void CMC(struct memorySchema instToExecute){
if(FLAGS[CARRY] == 1)FLAGS[CARRY] = 0; else FLAGS[CARRY] = 1;
}

void CMP(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	setFlagsForCMP(&A);
	}
	else if(strcmp(num,"B") == 0)
	{
	setFlagsForCMP(&B);
	}
	else if(strcmp(num,"C") == 0)
	{
	setFlagsForCMP(&C);
	}
	else if(strcmp(num,"D") == 0)		
	{
	setFlagsForCMP(&D);
	}	
	else if(strcmp(num,"E") == 0)
	{
	setFlagsForCMP(&E);
	}
	else if(strcmp(num,"H") == 0)
	{
	setFlagsForCMP(&H);
	}
	else if(strcmp(num,"L") == 0)
	{
	setFlagsForCMP(&L);
	}
	else if(strcmp(num,"M") == 0)
	{
	unsigned int tmp = dataVector[HL - DATA_REGION_START].dataHex;
	setFlagsForCMP(&tmp); 		
	}

}


void CPI(struct memorySchema instToExecute){

int n = hexToInt(extractFirst(instToExecute.instruction));
if(A < n)
{
FLAGS[CARRY] = 1;
FLAGS[ZERO] = 0;				/*SKIPPED FOR OTHER FLAGS */
}
else if(A == n){
FLAGS[ZERO] = 1;
FLAGS[CARRY] = 0;
}
else
{
FLAGS[CARRY] = 0;
FLAGS[ZERO] = 0;
}

}

void DAA(struct memorySchema instToExecute){

}

void DAD(struct memorySchema instToExecute){
int carry = 0x0;
char reg[3];
strcpy(reg,extractFirst(instToExecute.instruction));

if(strcmp(reg,"B")==0)
{
	L = C + L;
	if(L > 0xff)
		{
		L = 0xff;
		carry = 0x1;
		}
	H = B + H + carry;

}
else if(strcmp(reg,"D")==0)
{
	L = E + L;
	if(L > 0xff)
		{
		L = 0xff;
		carry = 0x1;
		}	
	H = D + H + carry;

}
else if(strcmp(reg,"H")==0)
{
	L = L + L;
	if(L > 0xff)
		{
		L = 0xff;
		carry = 0x1;
		}
	H = H + H + carry;

}
else if(strcmp(reg,"SP")==0)
{
printf(" %x " ,SP);
L = L + (SP & 0x00FF);
if(L > 0xff)
	{
		L = 0xff;
		carry = 0x1;
	}
H = H + ((SP & 0xFF00) >> 8) + carry;

}
setRegisterPairs();								// skipped for SP
}

void DCR(struct memorySchema instToExecute){
char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	--A;								/* NOT dONE ,SEE THROUGH NET */
	}								// flag register concept is not clear.
	else if(strcmp(num,"B") == 0)
	{
	--B;
	}
	else if(strcmp(num,"C") == 0)
	{
	--C;	
	}
	else if(strcmp(num,"D") == 0)		
	{
	--D;
	}	
	else if(strcmp(num,"E") == 0)
	{
	--E;
	}
	else if(strcmp(num,"H") == 0)
	{
	--H;
	}
	else if(strcmp(num,"L") == 0)
	{
	--L;
	}
	else if(strcmp(num,"M") == 0)
	{
		--dataVector[HL - DATA_REGION_START].dataHex;
	}
setRegisterPairs();
}

void DCX(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	if(strcmp(num,"B")==0)
	{
		if(C == 0x00)
		{
			C = 0xff;
			--B;
		}
		else
		--C;
	}
	else if(strcmp(num,"D")==0)
	{
		if(E == 0x00)
		{
			E = 0xff;
			--D;	
		}
		else
		--E;
	}
	else if(strcmp(num,"H")==0)
	{
		if(L == 0x00)
		{
			L = 0xFF;
			--H;
		}
		else
		--L;
	}	
	else if(strcmp(num,"SP")==0)
	{
		--SP;
	}
setRegisterPairs();
}

void DI(struct memorySchema instToExecute){

}

void EI(struct memorySchema instToExecute){

}

void HLT(){

extern int stopIt;
stopIt = STOP_LOOP;

}

void IN(struct memorySchema instToExecute){

}

void INR(struct memorySchema instToExecute){

char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	++A;								/* NOT dONE ,SEE THROUGH NET */
	}								// flag register concept is not clear.
	else if(strcmp(num,"B") == 0)
	{
	++B;
	}
	else if(strcmp(num,"C") == 0)
	{
	++C;	
	}
	else if(strcmp(num,"D") == 0)		
	{
	++D;
	}	
	else if(strcmp(num,"E") == 0)
	{
	++E;
	}
	else if(strcmp(num,"H") == 0)
	{
	++H;
	}
	else if(strcmp(num,"L") == 0)
	{
	++L;
	}
	else if(strcmp(num,"M") == 0)
	{
		++dataVector[HL - DATA_REGION_START].dataHex;			
	}
setRegisterPairs();
}

void INX(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	if(strcmp(num,"B")==0)
	{
		if(C == 0xFF)
		{
			C = 0x00;
			++B;
		}
		else
		++C;
	}
	else if(strcmp(num,"D")==0)
	{
		if(E == 0xFF)
		{
			E = 0x00;
			++D;	
		}
		else
		++E;
	}
	else if(strcmp(num,"H")==0)
	{
		if(L == 0xFF)
		{
			L = 0x00;
			++H;
		}
		else
		++L;
	}	
	else if(strcmp(num,"SP")==0)									// Skipped for SP
	{
		++SP;	
	}
setRegisterPairs();
}

void JMP(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));

PC = hexToInt(addr);

jumped = 1;
}

void JC(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[CARRY] == 1){
PC = hexToInt(addr);
jumped = 1;
}

}

void JNC(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[CARRY] == 0){
PC = hexToInt(addr);
jumped = 1;
}

}

void JP(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[SIGN] == 0){
PC = hexToInt(addr);
jumped = 1;
}

}

void JM(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[SIGN] == 1){
PC = hexToInt(addr);
jumped = 1;
}

}

void JPE(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[PARITY] == 1){
PC = hexToInt(addr);
jumped = 1;
}

}

void JPO(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[PARITY] == 0){
PC = hexToInt(addr);
jumped = 1;
}

}

void JZ(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[ZERO] == 1){
PC = hexToInt(addr);
jumped = 1;
}

}

void JNZ(struct memorySchema instToExecute){
char addr[5];
extern int jumped;
strcpy(addr,extractFirst(instToExecute.instruction));
if(FLAGS[ZERO] == 0){
PC = hexToInt(addr);
jumped = 1;
}

}

void LDA(struct memorySchema instToExecute){
char addr[6];
strcpy(addr,extractFirst(instToExecute.instruction));
int ad = hexToInt(addr);

A = dataVector[ad  - DATA_REGION_START].dataHex;

}

void LDAX(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	if(strcmp(num,"B")==0)
	{
		A = dataVector[BC - DATA_REGION_START].dataHex;
	}
	else if(strcmp(num,"D")==0)
	{
		A = dataVector[DE - DATA_REGION_START].dataHex;	
	}
}

void LHLD(struct memorySchema instToExecute){

char addr[6];
strcpy(addr,extractFirst(instToExecute.instruction));
int ad = hexToInt(addr);

L = dataVector[ad - DATA_REGION_START].dataHex;
H = dataVector[ad - DATA_REGION_START + 1].dataHex;

}

void LXI(struct memorySchema instToExecute){

char reg[3];
strcpy(reg,extractFirst(instToExecute.instruction));
char addr[6];

char addrLSB[3];
char addrMSB[3];
int i,j;
strcpy(addr,extractSecond(instToExecute.instruction));
for(i=0;i<2;i++)
	addrLSB[i] = addr[i];
	addrLSB[i] = '\0';
for(i=0,j=2;i<2;i++,j++) 
	addrMSB[i] = addr[j];
	addrMSB[i] = '\0';

if(strcmp(reg,"B")==0)
{
	B = hexToInt(addrLSB);
	C = hexToInt(addrMSB);
}
else if(strcmp(reg,"D")==0){
	D = hexToInt(addrLSB);
	E = hexToInt(addrMSB);
}
else if(strcmp(reg,"H")==0)
{
	H = hexToInt(addrLSB);
	L = hexToInt(addrMSB);
}
else if(strcmp(reg,"SP")==0)
{

	SP = hexToInt(addr);
}
else 
{
printf(CORE_DUMP_ERR);
exit(0);
}
setRegisterPairs();
}

void MOV(struct memorySchema instToExecute){

char first[2],second[2];
strcpy(first,extractFirst(instToExecute.instruction));
strcpy(second,extractSecond(instToExecute.instruction));
 if (strcmp(first,"A")==0){
	 if(strcmp(second,"A")==0)
A = A ;
	else if(strcmp(second,"B")==0)
A = B ;
	else if(strcmp(second,"C")==0)
A = C ;
	else if(strcmp(second,"D")==0)
A = D ;
	else if(strcmp(second,"E")==0)
A = E ;
	else if(strcmp(second,"H")==0)
A = H ;
	else if(strcmp(second,"L")==0)
A = L ;
	else if(strcmp(second,"M")==0)
A = dataVector[HL - DATA_REGION_START].dataHex ;	
}else if (strcmp(first,"B")==0){
	 if(strcmp(second,"A")==0)
B = A ;
	else if(strcmp(second,"B")==0)
B = B ;
	else if(strcmp(second,"C")==0)
B = C ;
	else if(strcmp(second,"D")==0)
B = D ;
	else if(strcmp(second,"E")==0)
B = E ;
	else if(strcmp(second,"H")==0)
B = H ;
	else if(strcmp(second,"L")==0)
B = L ;
	else if(strcmp(second,"M")==0)
B = dataVector[HL - DATA_REGION_START].dataHex ;
}else if (strcmp(first,"C")==0){
	 if(strcmp(second,"A")==0)
C = A ;
	else if(strcmp(second,"B")==0)
C = B ;
	else if(strcmp(second,"C")==0)
C = C ;
	else if(strcmp(second,"D")==0)
C = D ;
	else if(strcmp(second,"E")==0)
C = E ;
	else if(strcmp(second,"H")==0)
C = H ;
	else if(strcmp(second,"L")==0)
C = L ;
	else if(strcmp(second,"M")==0)
C = dataVector[HL - DATA_REGION_START].dataHex ;
}else if (strcmp(first,"D")==0){
	if(strcmp(second,"A")==0)
D = A ;
	else if(strcmp(second,"B")==0)
D = B ;
	else if(strcmp(second,"C")==0)
D = C ;
	else if(strcmp(second,"D")==0)
D = D ;
	else if(strcmp(second,"E")==0)
D = E ;
	else if(strcmp(second,"H")==0)
D = H ;
	else if(strcmp(second,"L")==0)
D = L ;
	else if(strcmp(second,"M")==0)
D = dataVector[HL - DATA_REGION_START].dataHex ;
}else if (strcmp(first,"E")==0){
	 if(strcmp(second,"A")==0)
E = A ;
	else if(strcmp(second,"B")==0)
E = B ;
	else if(strcmp(second,"C")==0)
E = C ;
	else if(strcmp(second,"D")==0)
E = D ;
	else if(strcmp(second,"E")==0)
E = E ;
	else if(strcmp(second,"H")==0)
E = H ;
	else if(strcmp(second,"L")==0)
E = L ;
else if(strcmp(second,"M")==0)
E = dataVector[HL - DATA_REGION_START].dataHex ;
}else if (strcmp(first,"H")==0){
	if(strcmp(second,"A")==0)
H = A ;
	else if(strcmp(second,"B")==0)
H = B ;
	else if(strcmp(second,"C")==0)
H = C ;
	else if(strcmp(second,"D")==0)
H = D ;
	else if(strcmp(second,"E")==0)
H = E ;
	else if(strcmp(second,"H")==0)
H = H ;
	else if(strcmp(second,"L")==0)
H = L ;
else if(strcmp(second,"M")==0)
H = dataVector[HL - DATA_REGION_START].dataHex ;
}else if (strcmp(first,"L")==0){
	 if(strcmp(second,"A")==0)
L = A ;
	else if(strcmp(second,"B")==0)
L = B ;
	else if(strcmp(second,"C")==0)
L = C ;
	else if(strcmp(second,"D")==0)
L = D ;
	else if(strcmp(second,"E")==0)
L = E ;
	else if(strcmp(second,"H")==0)
L = H ;
	else if(strcmp(second,"L")==0)
L = L ;
else if(strcmp(second,"M")==0)
L = dataVector[HL - DATA_REGION_START].dataHex ;
}else if (strcmp(first,"M")==0){
	 if(strcmp(second,"A")==0)
dataVector[HL - DATA_REGION_START].dataHex = A ;
	else if(strcmp(second,"B")==0)
dataVector[HL - DATA_REGION_START].dataHex = B ;
	else if(strcmp(second,"C")==0)
dataVector[HL - DATA_REGION_START].dataHex = C ;
	else if(strcmp(second,"D")==0)
dataVector[HL - DATA_REGION_START].dataHex = D ;
	else if(strcmp(second,"E")==0)
dataVector[HL - DATA_REGION_START].dataHex = E ;
	else if(strcmp(second,"H")==0)
dataVector[HL - DATA_REGION_START].dataHex = H ;
	else if(strcmp(second,"L")==0)
dataVector[HL - DATA_REGION_START].dataHex = L ;
}			
setRegisterPairs();
}

void MVI(struct memorySchema instToExecute){

char first[2],second[2];
strcpy(first,extractFirst(instToExecute.instruction));
strcpy(second,extractSecond(instToExecute.instruction));

if(strcmp(first,"A") == 0)
A = hexToInt(second);
else if(strcmp(first,"B") == 0)
B = hexToInt(second);
else if(strcmp(first,"C") == 0)
C = hexToInt(second);
else if(strcmp(first,"D") == 0)
D = hexToInt(second);
else if(strcmp(first,"E") == 0)
E = hexToInt(second);
else if(strcmp(first,"H") == 0)
H = hexToInt(second);
else if(strcmp(first,"L") == 0)
L = hexToInt(second);
else if(strcmp(first,"M") == 0)
{
dataVector[HL - DATA_REGION_START].dataHex = hexToInt(second);
}
setRegisterPairs();
}
void NOP(struct memorySchema instToExecute){

}

void ORA(struct memorySchema instToExecute){

char first[2],second[2];
strcpy(first,extractFirst(instToExecute.instruction));
strcpy(second,extractSecond(instToExecute.instruction));

if(strcmp(first,"A") == 0)
A = A | A;
else if(strcmp(first,"B") == 0)
A = A | B;
else if(strcmp(first,"C") == 0)
A = A | C;
else if(strcmp(first,"D") == 0)
A = A | D;
else if(strcmp(first,"E") == 0)
A = A | E;
else if(strcmp(first,"H") == 0)
A = A | H;
else if(strcmp(first,"L") == 0)
A = A | L;
else if(strcmp(first,"M") == 0)
{


										/* Skipped */

}


}

void ORI(struct memorySchema instToExecute){

A = A | hexToInt(extractFirst(instToExecute.instruction));

}

void OUT(struct memorySchema instToExecute){

}

void PCHL(struct memorySchema instToExecute){
extern int jumped;
PC = HL;
jumped = 1;
}

void POP(struct memorySchema instToExecute){
char cnum[4];
strcpy(cnum,extractFirst(instToExecute.instruction));

if(strcmp(cnum,"B")==0){

B = stackVector[STACK_ADDR_START - SP].dataHex;
SP++;
C = stackVector[STACK_ADDR_START - SP].dataHex;
SP++;
}
else if(strcmp(cnum,"D")==0){

D = stackVector[STACK_ADDR_START - SP].dataHex ;
SP++;
E = stackVector[STACK_ADDR_START - SP].dataHex;
SP++;
}
else if(strcmp(cnum,"H")==0){

H = stackVector[STACK_ADDR_START - SP].dataHex ;
SP++;
L = stackVector[STACK_ADDR_START - SP].dataHex;
SP++;
}
else if(strcmp(cnum,"PSW")==0){
A = stackVector[STACK_ADDR_START - SP].dataHex;
SP++;
int flag = stackVector[STACK_ADDR_START - SP].dataHex;
setFlags(flag);					
} 
setRegisterPairs();
}

void PUSH(struct memorySchema instToExecute){
char cnum[4];
strcpy(cnum,extractFirst(instToExecute.instruction));

if(strcmp(cnum,"B")==0){
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = C;
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = B;
}
else if(strcmp(cnum,"D")==0){
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = E;
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = D;
}
else if(strcmp(cnum,"H")==0){
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = L;
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = H;
}
else if(strcmp(cnum,"PSW")==0){

SP--;
stackVector[STACK_ADDR_START - SP].dataHex = generateFlagRegister();
SP--;
stackVector[STACK_ADDR_START - SP].dataHex = A;	
} 
}

void RAL(struct memorySchema instToExecute){
	int d8;
	int tmpCarry = FLAGS[CARRY];
	printf("vallue of tmpCarry is %d\n",tmpCarry);
	if(A >= 128)
	d8 = 1;
	else 
	d8 = 0;
	if(d8 == 1)
	{
		FLAGS[CARRY] = 1;
		A = A << 1;
		A = A & 0xff;	
	}
	else
	{
	A = A << 1;
	A = A + tmpCarry;
	}
setAFlags();
}  

void RAR(struct memorySchema instToExecute){
int tmpCarry= FLAGS[CARRY];

if((A & 1) == 1)
FLAGS[CARRY] = 1;
else
FLAGS[CARRY] = 0;

A = A >> 1;

if(tmpCarry == 1)
A = A + 128;
}

void RLC(struct memorySchema instToExecute){
	int d8;
	int tmpCarry = FLAGS[CARRY];
	printf("vallue of tmpCarry is %d\n",tmpCarry);
	if(A >= 128)
	d8 = 1;
	else 
	d8 = 0;
	if(d8 == 1)
	{
		FLAGS[CARRY] = 1;
		A = A << 1;
		A = A & 0xff;
		++A;	
	}
	else
	{
	A = A << 1;
	FLAGS[CARRY] = 1;
	++A;
	}
setAFlags();

}

void RRC(struct memorySchema instToExecute){

if((A & 1) == 1)
{
FLAGS[CARRY] = 1;
A = A >> 1;
A = A + 128;
}
else
{
FLAGS[CARRY] = 0;
A = A >> 1;
}
setAFlags();
}

void RET(){
extern int inCallRet;
inCallRet = 1;
}

void RC(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[CARRY] == 1){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RNC(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[CARRY] == 0){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RP(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[SIGN] == 0){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RM(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[SIGN] == 1){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RPE(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[PARITY] == 1){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RPO(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[PARITY] == 0){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RZ(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[ZERO] == 1){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RNZ(struct memorySchema instToExecute){
extern int stopExecLoop;
if(FLAGS[ZERO] == 0){
popStack();
stopExecLoop = STOP_LOOP;
}
}

void RIM(struct memorySchema instToExecute){

}

void RST(struct memorySchema instToExecute){

}

void SBB(struct memorySchema instToExecute){
extern short int borrow;
char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	A = A - A - borrow ;
	A = A & 0XFF;		
	setAFlags();	
	}
	else if(strcmp(num,"B") == 0)
	{
	A = A - B - borrow ;
	A = A & 0XFF;	
	setAFlags();	
	}
	else if(strcmp(num,"C") == 0)
	{
	A = A - C - borrow ;
	A = A & 0XFF;	setAFlags();	
	}
	else if(strcmp(num,"D") == 0)		
	{
	A = A - D - borrow ;
	A = A & 0XFF;
	setAFlags();	
	}	
	else if(strcmp(num,"E") == 0)
	{
	A = A - E - borrow ;
	A = A & 0XFF;	
	setAFlags();
	}
	else if(strcmp(num,"H") == 0)
	{
	A = A - H - borrow ;
	A = A & 0XFF;	setAFlags();
	}
	else if(strcmp(num,"L") == 0)
	{
	A = A - L - borrow ;
	A = A & 0XFF;		
	setAFlags();
	}
	else if(strcmp(num,"M") == 0)
	{
	A = A - dataVector[HL - DATA_REGION_START].dataHex - borrow;
	A = A & 0XFF;
	setAFlags();											/* Skipped */		
	}
setRegisterPairs();

}

void SBI(struct memorySchema instToExecute){

	extern short int borrow;
	char num[4];
	strcpy(num,extractFirst(instToExecute.instruction));
	int number = hexToInt(num);
	
	A = A - number - borrow ;
	A = A & 0XFF;		
	setAFlags();
	
}

void SHLD(struct memorySchema instToExecute){


char addr[6];
strcpy(addr,extractFirst(instToExecute.instruction));
int ad = hexToInt(addr);

dataVector[ad - DATA_REGION_START].dataHex = L;
dataVector[ad - DATA_REGION_START + 1].dataHex = H;

}

void SIM(struct memorySchema instToExecute){

}

void SPHL(struct memorySchema instToExecute){
SP = HL;
}

void STA(struct memorySchema instToExecute){

char addr[6];
strcpy(addr,extractFirst(instToExecute.instruction));
int addressToStore = hexToInt(addr);

dataVector[addressToStore - DATA_REGION_START].dataHex = A;

}

void STAX(struct memorySchema instToExecute){
	char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	if(strcmp(num,"B")==0)
	{
		dataVector[BC - DATA_REGION_START].dataHex = A;
	}
	else if(strcmp(num,"D")==0)
	{
		dataVector[DE - DATA_REGION_START].dataHex = A;	
	}
}

void STC(struct memorySchema instToExecute){
FLAGS[CARRY] = 1;
}

void SUB(struct memorySchema instToExecute){

char num[2];
	strcpy(num,extractFirst(instToExecute.instruction));
	
	if(strcmp(num,"A") == 0)
	{
	A = 0 ;		
	setAFlags();	
	}
	else if(strcmp(num,"B") == 0)
	{
	A = A - B;		
	setAFlags();	
	}
	else if(strcmp(num,"C") == 0)
	{
	A = A - C ;		
	setAFlags();	
	}
	else if(strcmp(num,"D") == 0)		
	{
	A = A - D ;
	setAFlags();	
	}	
	else if(strcmp(num,"E") == 0)
	{
	A = A - E ;		
	setAFlags();
	}
	else if(strcmp(num,"H") == 0)
	{
	A = A - H ;		
	setAFlags();
	}
	else if(strcmp(num,"L") == 0)
	{
	A = A - L ;		
	setAFlags();
	}
	else if(strcmp(num,"M") == 0)
	{
	A = A - dataVector[HL - DATA_REGION_START].dataHex;	
	}
}

void SUI(struct memorySchema instToExecute){
char immediate[3];
strcpy(immediate,extractFirst(instToExecute.instruction));
int imm = hexToInt(immediate);
A = A - imm;
setAFlags();
}

void XCHG(struct memorySchema instToExecute){
int tmp;
tmp = H;
H = D;
D = tmp;
tmp = L;
L = E;
E = tmp;
setRegisterPairs();
}

void XRA(struct memorySchema instToExecute){


char first[2],second[2];
strcpy(first,extractFirst(instToExecute.instruction));
strcpy(second,extractSecond(instToExecute.instruction));

if(strcmp(first,"A") == 0)
A = A ^ A;
else if(strcmp(first,"B") == 0)
A = A ^ B;
else if(strcmp(first,"C") == 0)
A = A ^ C;
else if(strcmp(first,"D") == 0)
A = A ^ D;
else if(strcmp(first,"E") == 0)
A = A ^ E;
else if(strcmp(first,"H") == 0)
A = A ^ H;
else if(strcmp(first,"L") == 0)
A = A ^ L;
else if(strcmp(first,"M") == 0)
{
A = A ^ dataVector[HL - DATA_REGION_START].dataHex;
}
}

void XRI(struct memorySchema instToExecute){

A = A ^ hexToInt(extractFirst(instToExecute.instruction));

}

void XTHL(struct memorySchema instToExecute){
int tmp;
tmp = stackVector[SP].dataHex;
stackVector[SP].dataHex = L;
L = tmp;
tmp = stackVector[SP + 1].dataHex;
stackVector[SP + 1].dataHex = H;
H = tmp;
setRegisterPairs();
}


