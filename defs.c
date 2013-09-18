/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/

#include "defs.h"
#include "libs.h"

/*
* All registers in 8085
*/
#define FLAG_SIZE 5

unsigned int B = 0x0;			//8-bit registers.
unsigned int C = 0x0;
unsigned int D = 0x0;			
unsigned int E = 0x0;			
unsigned int H = 0x0;			
unsigned int L = 0x0;			

unsigned int A = 0x0;			// Accumulator it is.(8-bit)
int BC = 0x0;
int DE = 0x0;			//16-bit registers. {Pairs}
int HL = 0x0;			

unsigned int SP = 0x0;			//Stack pointer it is.			// Program Status word.
long int PC = 0x0;
unsigned int borrow = 0; 				
/* FLAGS array contain the 8085 flags bits.
*
* Zero flag(z)-It holds 1 if the result is zero else it holds 0.
* Sign flag(s)-It holds 1 if the result has negative value else it holds 0.
* Parity flag(p)-It holds 1 if the result has even parity.It holds 0 if the result has odd parity.
* Carry flag(c)-It holds the value 1 if the result has carry else 0.
* Auxillary carry flag(AC)-It holds 1 if the result has carry from LSB to MSB else it holds 0.
*/
short int FLAGS[FLAG_SIZE];
int programSize = 0;
int stopIt;
int stopExecLoop;
int jumped;
int progInMem = 0;
int inCall = 0;
long int callStack[100];
int topCallStack = 0;
int inCallRet=0;

