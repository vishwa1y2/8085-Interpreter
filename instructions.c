/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/

#include "defs.h"
#include "libs.h"
extern struct sizeInfo instSize[MAX_OPCODES];
struct sizeInfo instSize[] = 
{
{ "ACI" , 2},
{ "ADC" , 1},
{ "ADD" , 1},
{ "ADI" , 2},
{ "ANA" , 1},
{ "ANI" , 2},
{ "CALL" , 3},
{ "CC" , 3},
{ "CNC" , 3},
{ "CP" , 3},
{ "CM" , 3},
{ "CPE" , 3},
{ "CPO" , 3},
{ "CZ" , 3},
{ "CNZ" , 3},
{ "CMA" , 1},
{ "CMC" , 1},
{ "CMP" , 1},
{ "CPI" , 2},
{ "DAA" , 1},
{ "DAD" , 1},
{ "DCR" , 1},
{ "DCX" , 1},
{ "DI" , 1},
{ "EI" , 1},
{ "HLT" , 1},
{ "IN" , 2},
{ "INR" , 1},
{ "INX" , 1},
{ "JMP" , 3},
{ "JC" , 3},
{ "JNC" , 3},
{ "JP" , 3},
{ "JM" , 3},
{ "JPE" , 3},
{ "JPO" , 3},
{ "JZ" , 3},
{ "JNZ" , 3},
{ "LDA" , 3},
{ "LDAX" , 1},
{ "LHLD" , 3},
{ "LXI" , 3},
{ "MOV" , 1},
{ "MVI" , 2},
{ "NOP" , 1},
{ "ORA" , 1},
{ "ORI" , 2},
{ "OUT" , 2},
{ "PCHL" , 1},
{ "POP" , 1},
{ "PUSH" , 1},
{ "RAL" , 1},
{ "RAR" , 1},
{ "RLC" , 1},
{ "RRC" , 1},
{ "RET" , 1},
{ "RC" , 1},
{ "RNC" , 1},
{ "RP" , 1},
{ "RM" , 1},
{ "RPE" , 1},
{ "RPO" , 1},
{ "RZ" , 1},
{ "RNZ" , 1},
{ "RIM" , 1},
{ "RST" , 1},
{ "SBB" , 1},
{ "SBI" , 2},
{ "SHLD" , 3},
{ "SIM" , 1},
{ "SPHL" , 1},
{ "STA" , 3},
{ "STAX" , 1},
{ "STC" , 1},
{ "SUB" , 1},
{ "SUI" , 2},
{ "XCHG" , 1},
{ "XRA" , 1},
{ "XRI" , 2},
{ "XTHL" , 1}
};

