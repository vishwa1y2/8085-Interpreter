/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/

#include "defs.h"
#include "libs.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern int progInMem;

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

extern unsigned int IP;			

extern unsigned int SP;



extern long int PC;

extern short int FLAGS[FLAG_SIZE];

extern struct sizeInfo instSize[MAX_OPCODES];

extern struct memorySchema vector[];

extern struct stackSchema stackVector[];

extern struct dataSchema dataVector[];

extern int programSize;

void init(void ){
printf("Refreshing Registers Values : DONE\n");
A = 0;
B = 0;
C = 0;
D = 0;
E = 0;
H = 0;
L = 0;
BC = 0;
DE = 0;
HL = 0;
PC = MEMORY_ADDR;

extern int programSize;
extern int stopIt;
extern int stopExecLoop;
extern int jumped;

extern int inCall;

extern int topCallStack ;
extern int inCallRet;
programSize = 0;
topCallStack = 0;
inCallRet=0;
stopIt = 0;
stopExecLoop = 0 ;
jumped = 0 ;
inCall = 0;
FLAGS[SIGN] = 0;
FLAGS[PARITY] = 0;
FLAGS[CARRY] = 0;
FLAGS[AUX_CARRY] = 0;
FLAGS[ZERO] = 0;
char emptyString[20] = "";
int i;
printf("Initializing program space :  DONE\n");
for(i = 0;i< MEMORY_END - MEMORY_ADDR ;i++)
{
	vector[i].memoryAddress = i + MEMORY_ADDR;
	vector[i].memorySize = 0;
	strcpy(vector[i].instruction,emptyString); 
}

for(i = 0;i< DATA_REGION_END - DATA_REGION_START ;i++)
{
	dataVector[i].address = i + DATA_REGION_START;
	dataVector[i].dataHex = 0x0;
}
printf("Memory ready : 		      DONE\n");
for(i = 0;i< STACK_ADDR_START - STACK_ADDR_END  ;i++)
{
	stackVector[i].address = i + STACK_ADDR_END;
	stackVector[i].dataHex = 0x0;
}
SP  = STACK_ADDR_START;
printf("Stack ready : 		      DONE\n");

printf("Memory Starts at address :0x");
printf("%x\n",MEMORY_ADDR);

}
void initGoto(){

A = 0;
B = 0;
C = 0;
D = 0;
E = 0;
H = 0;
L = 0;
BC = 0;
DE = 0;
HL = 0;
PC = MEMORY_ADDR;
extern int stopIt;
extern int stopExecLoop;
extern int jumped;

extern int inCall;

extern int topCallStack ;
extern int inCallRet;
topCallStack = 0;
inCallRet=0;
stopIt = 0;
stopExecLoop = 0 ;
jumped = 0 ;
inCall = 0;

FLAGS[SIGN] = 0;
FLAGS[PARITY] = 0;
FLAGS[CARRY] = 0;
FLAGS[AUX_CARRY] = 0;
FLAGS[ZERO] = 0;

}
extern long int callStack[];
extern int topCallStack;

void pushStack(){

topCallStack++;
callStack[topCallStack] = PC;
}

void popStack(){

if(topCallStack == 0)
{
printf("ERROR : More RET instruction than CALL instruction.\n");
abort();
}

PC = callStack[topCallStack];

--topCallStack;

}

char * extractZeroth(char str[20]){	//Extract zeroth element from the user string.

char *p = str;				//ex - MOV A B

while(INFINITY_IN_LOOP)				// result - MOV
{

if(*p == ' ' || *p == '\n' || *p == '\0')
{
	*p = '\0';
	return str;
}

p++;

}
}

char * extractFirst(char str[20]){	// Extract first element from the user string.

char *p = str;
char *q,*r;
while(INFINITY_IN_LOOP)
{
	if(*p == ' ')	
	{
	q = p+1;
	r = q;
	break;
	}	
p++;
}
while(INFINITY_IN_LOOP){
	if(*r == ' ' || *r == '\0' || *r == '\n')
	{
		*r = '\0';
		return q;
	}
++r;
}					
}
char * extractSecond(char str[20]){	// Extract second element from the user string.			
	
char *p = str;
char *q,*r,*s;
while(INFINITY_IN_LOOP)
{
	if(*p == ' ')	
	{
	q = p+1;
	r = q;
	break;
	}	
p++;
}
while(INFINITY_IN_LOOP){
	if(*q == ' ' || *q == '\n' || *q == '\0')
	{
		r = q+1;
		s = r;
		break;
	}
++q;
}			
while(INFINITY_IN_LOOP){
	if(*s == ' ' || *s == '\n' || *s == '\0')
	{
		*s = '\0';
		return r;
	}
++s;
}

}

int instInInstruction(const char *tmp){ //Check whether the instruction is in list or not.

int i=0;

for(i=0;i<MAX_OPCODES;i++)
{

if(!strcmp(tmp,instSize[i].opcode))

return instSize[i].size;

}

return NOT_FOUND;

}

void getUserCodeCmd(){ 			//Main module to get the user program and if debugging in ON, execute also.

char tmpStr[20];
char tmp[20] = "Something isn't good" ;
int mSVIterator = 0;
int lastInstSize = 0;
int curAddr = MEMORY_ADDR;

while(strcmp(tmp,"DONE") && strcmp(tmp,"done")){

printf("0x%x : ",curAddr);

gets(tmp);

strcpy(tmpStr,tmp);

lastInstSize = instInInstruction(extractZeroth(tmp));


if( lastInstSize != NOT_FOUND){

vector[mSVIterator].memoryAddress =  curAddr;

vector[mSVIterator].memorySize = lastInstSize;

strcpy(vector[mSVIterator].instruction,tmpStr);

curAddr += lastInstSize;

//callALU(vector[mSVIterator]);	
				//Execute last instruction by calling the ALU unit.

++mSVIterator;			//Increment mSVIterator for next storage locatio

}
else if(strcmp(tmp,"DONE")==0 || strcmp(tmp,"done") == 0 ); 
else
	printf("That wasn't in the Op-code List. Please, Re-Enter.\n");

}

programSize = mSVIterator;

}
extern int inCallRet;
void executeProgram(int debug){

int indexToExecute = 0;

extern int stopIt,jumped,inCall;

char str[5];
if(debug){

for( PC = MEMORY_ADDR ; stopIt != STOP_LOOP ;){	//8192 IN HEXADECIMAL IS 2000,AS WHERE THE MEMORY STARTS
//printf("%ld\n",PC);

indexToExecute =  returnIndex(PC);

callALU(vector[indexToExecute]);

printAllRegisters(1);

if(stopIt == STOP_LOOP)
break;
int i;

if(inCall) inCall=0;
else if(inCallRet){

inCallRet = 0;
popStack();

for(i=0;i<programSize;i++)
if(vector[i].memoryAddress == PC)
{
PC = vector[i].memoryAddress + vector[i].memorySize;
break;
}

}
else if(jumped == 1) {
jumped = 0;
} 
else
PC = vector[indexToExecute].memoryAddress + vector[indexToExecute].memorySize ;
printf("Simulator @ 8085 $ ");
while(strcmp(gets(str),"next")!=0);
}

}
else{

for( PC = MEMORY_ADDR ; stopIt != STOP_LOOP ;){	//8192 IN HEXADECIMAL IS 2000,AS WHERE THE MEMORY STARTS

indexToExecute =  returnIndex(PC);
callALU(vector[indexToExecute]);

if(stopIt == STOP_LOOP)
break;
int i;

if(inCall) inCall=0;
else if(inCallRet){

inCallRet = 0;
popStack();

for(i=0;i<programSize;i++)
if(vector[i].memoryAddress == PC)
{
PC = vector[i].memoryAddress + vector[i].memorySize;
break;
}

}
else if(jumped == 1) {
jumped = 0;
} 
else
PC = vector[indexToExecute].memoryAddress + vector[indexToExecute].memorySize ;
}
}
printf("\nExecuting... : 		      DONE\n");
}
int returnIndex(long int val){

int ret;

for(ret = 0;ret < programSize ;++ret)
if(vector[ret].memoryAddress == val)
{	
	return ret;
}

return -1;
}
/*
void execCALL(int addr){
extern int stopExecLoop;
int indexToExecute;
for( PC = addr ; PC >= addr ; ){	//8192 IN HEXADECIMAL IS 2000,AS WHERE THE MEMORY STARTS

indexToExecute =  returnIndex(PC);

callALU(vector[indexToExecute]);

if(stopExecLoop == STOP_LOOP)
continue;
PC = vector[indexToExecute].memoryAddress + vector[indexToExecute].memorySize ;
}


}
*/
void printProgram(){		//To print the memorySchema structure with vector array.

int i;

printf("Your Program is :\n");
for(i=0;i<programSize;i++)
printf("0x%x : %s\n",vector[i].memoryAddress,vector[i].instruction);
}


int hexToInt(const char *tmp){
int len,n,pow,i;
int result = 0;
len = strlen(tmp);


for(i = len-1,pow = 0 ; i >=0; --i,++pow)
{
		
	switch(tmp[i]){
	case '0' : n = 0;
		break;
	case '1' : n = 1;
		break;
	case '2' : n = 2;
		break;
	case '3' : n = 3;
		break;
	case '4' : n = 4;
		break;
	case '5' : n = 5;
		break;
	case '6' : n = 6;
		break;
	case '7' : n = 7;
		break;
	case '8' : n = 8;
		break;
	case '9' : n = 9;
		break;
	case 'a' : n = 10;
	case 'A' : n = 10;
		break;
	case 'b' : n = 11;	
	case 'B' : n = 11;
		break;
	case 'c' : n = 12;
	case 'C' : n = 12;
		break;
	case 'd' : n = 13;
	case 'D' : n = 13;
		break;
	case 'e' : n = 14;
	case 'E' : n = 14;
		break;
	case 'f' : n = 15;
	case 'F' : n = 15;
		break;
	default : printf("Error in syntax....VAL = %c ",tmp[i]);
}
if(pow == 0)
result += n;
else
result += n * powfunc(16,pow);
}

return result;
}
int powfunc(int base, int pow){
if(pow ==1)
	return base;
else if(pow == 2)
	return base * base;
else if(pow ==3)
	return base *base *base ;
return 0;  
}
int checkParity(int reg){

int i,counter = 0,res;

for(i=0;i<7;i++){

res = (reg >> i) & 1;

if(res == 1)
	counter++;
}
if(FLAGS[SIGN] == 1)
counter++;
if(counter % 2 == 0)
return GOT_IT;
return 0;
}
void saveProgram(char *file){
char dirname[106] = "pfiles/";
strcat(dirname,file);

FILE *fp;
int i;
fp = fopen(dirname,"w+");
if(fp == NULL){
printf("\nInvalid File location !\n");
return;
}
else
{

for(i = 0; i<programSize;i++)
{
fprintf(fp,"%s\n",vector[i].instruction);
}
fclose(fp);
}
}
void openProgram(char *file){
char dirname[106] = "pfiles/";
strcat(dirname,file);
FILE *fp;
int i = 0,lastInstSize = 0;
int curAddr = MEMORY_ADDR;

fp = fopen(dirname,"r");
if(fp == NULL){
printf("\nInvalid File location !\n");
return;
}
else
{
char s[20];
char t[20];
programSize = 0;
while(fgets(s,15,fp)!=NULL)
{

strcpy(t,s);

lastInstSize = instInInstruction(extractZeroth(t));

if( lastInstSize != NOT_FOUND){

programSize++;

strcpy(vector[i].instruction,s);

vector[i].memoryAddress =  curAddr;

vector[i].memorySize = lastInstSize;

curAddr += lastInstSize;

i++;
}
else
{
printf("Error getting data. Syntax Error in File on line %d.",i+1);
programSize = 0;
progInMem = 0;
fclose(fp);
return;
}	
}
printf("Getting program in Memory :   DONE");
fclose(fp);
}
progInMem = 1;
}
void takeSingleInstruction(){
int yeah=0,i,size,addr;
char ch[20],t[20],add[5];
printf("Enter Memory Location: ");
gets(add);
addr = hexToInt(add);
printf("\nInstruction at %x :",addr);
gets(ch);
strcpy(t,ch);

for(i=0;i<programSize;i++)
if(addr == vector[i].memoryAddress)
{
	if((size =instInInstruction(extractZeroth(t)))==vector[i].memorySize)
	{
	yeah = 1;
	strcpy(vector[i].instruction,ch);
	break;
	}
	else if(size == NOT_FOUND)
	{
	printf("\nInstruction not in opcode List.\n");	
	}	
}

if(!yeah)
printf("\nSize of the specified instruction doesn't fit previous instruction.\n");
}
void printAllRegisters(int debug){
if(debug){				//If debug mode is ON, instructions execute one by one, or if OFF, then auto sequence.

printf(" *B = %XH ",B);
printf(" *C = %XH ",C);
printf(" *D = %XH ",D);
printf(" *E = %XH ",E);
printf(" *H = %XH ",H);
printf(" *L = %XH \n",L);
printf(" *A = %XH \n",A);
printf("*BC = %XH ",BC);
printf("*DE = %XH ",DE);
printf("*HL = %XH \n",HL);


printf("Flag register : ZERO = %d, SIGN = %d, PARITY = %d, CARRY = %d, AUXILARY CARRY = N/A\n",FLAGS[ZERO],FLAGS[SIGN],FLAGS[PARITY],FLAGS[CARRY]);
}
else{
printf("\nAll Registers values are as follows:\n");
printf(" B = %XH ",B);
printf(" C = %XH ",C);
printf(" D = %XH ",D);
printf(" E = %XH ",E);
printf(" H = %XH ",H);
printf(" L = %XH \n",L);
printf(" A = %XH \n",A);
printf(" BC = %XH ",BC);
printf(" DE = %XH ",DE);
printf(" HL = %XH \n",HL);


printf("Flag register : ZERO = %d, SIGN = %d, PARITY = %d, CARRY = %d, AUXILARY CARRY = N/A\n",FLAGS[ZERO],FLAGS[SIGN],FLAGS[PARITY],FLAGS[CARRY]);

}
}//printAllRegisters() ends here.
void setAFlags(){

	if(A < 0x0)
	FLAGS[SIGN] = 1;
	else if(A > 0xFF){
		A = 0xFF;	
		FLAGS[CARRY] = 1;	
		}	
	else if(A == 0)
		FLAGS[ZERO] = 1;
	if(checkParity(A))
	FLAGS[PARITY] = 1;
	else 
	FLAGS[PARITY] = 0;

}

void setFlagsForCMP(unsigned int *reg){
if(A < *reg)
{
FLAGS[CARRY] = 1;
FLAGS[ZERO] = 0;				/*SKIPPED FOR OTHER FLAGS */
}
else if(A == *reg){
FLAGS[ZERO] = 1;
FLAGS[CARRY] = 0;
}
else
{
FLAGS[CARRY] = 0;
FLAGS[ZERO] = 0;
}
}
void setRegisterPairs(){
unsigned int numLSB;
if(B == 0xff){
numLSB = 0x0000FF00;
}
else{
numLSB = B & 0xff;
numLSB = numLSB << 8;
}
BC = numLSB |  C;

if(D == 0xff){
numLSB = 0x0000FF00;
}
else{
numLSB = D & 0xff;
numLSB = numLSB << 8;
}
DE = numLSB | E;
if(H == 0xff){
numLSB = 0x0000FF00;
}
else{
numLSB = H & 0xff;
numLSB = numLSB << 8;
}
HL = numLSB | L;

}
int generateFlagRegister(){		// S Z - AC - P - CY (ordering of flags in register,- denote empty)
int flag = 0;
if(FLAGS[CARRY])
flag = 1;
if(FLAGS[PARITY])
flag = flag + 4;
if(FLAGS[AUX_CARRY])
flag = flag + 16;
if(FLAGS[ZERO])
flag = flag + 64;
if(FLAGS[SIGN])
flag = flag + 128;

return flag;
}
void setFlags(int flag){

if(flag & 0x1)
FLAGS[CARRY] = 1;
else 
FLAGS[CARRY] = 0;
if(flag & 4)
FLAGS[PARITY] = 1;
else
FLAGS[PARITY] = 0;
if(flag & 0xF)
FLAGS[AUX_CARRY] = 1;
else 
FLAGS[AUX_CARRY] = 0;
if(flag & 64)
FLAGS[ZERO] = 1;
else 
FLAGS[ZERO] = 0;
if(flag & 128)
FLAGS[SIGN] = 1;
else 
FLAGS[SIGN] = 0;
}


