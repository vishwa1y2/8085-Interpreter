/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/

#ifndef _DEFS_H_
#define _DEFS_H_

#define _HEADER_STRING_  "\n****************************** 8085 Simulation Scheme ***************************\n\n ***(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>*** \n\n"

#define INFINITY_IN_LOOP  1
#define MAX_OPCODES     80
#define ZERO 		0	//Defines the position of each 
#define SIGN 		1	// flag in the FLAGS[] array
#define PARITY		2
#define CARRY		3
#define AUX_CARRY	4
#define FLAG_SIZE	5
#define MEMORY_ADDR 		0x2000			//Memory layout.
#define MEMORY_END		0x3FFF
#define DATA_REGION_START 	0x4000
#define DATA_REGION_END 	0x5FFF
#define STACK_ADDR_END  	0x6000
#define STACK_ADDR_START 	0x6FFF 

#define DATA_RANGE 0xFF
#define NOT_FOUND 80

#define CALL_ERROR		0xa
#define CORE_DUMP_ERR "\nERROR in your syntax\nAborted (core dumped)\n"

#define GOT_IT 1
#define STOP_LOOP		0xFF

#define _HELP_ "\nAvailable Commands :\nnew - to write a new program using command line. \
\nrun - to run the program\nrun -d  -to run the execution in debug mode \nnext - to execute next instruction in debug mode.\nresult - to see execution results \nshow - to show the program present in memory. \nsave - to save the program in directory pfiles.\nopen - to open a file\nhelp - for this help menu. \nexit - to get out.\n\nWarning : Leading and trailing spaces not allowed.\n"
 struct memorySchema{
int memoryAddress; 
int memorySize;
char instruction[20];
};

struct dataSchema{
int dataHex;
int address;
};

struct stackSchema{
int dataHex;
int address;
};

struct sizeInfo{
char opcode[5];
int size;
};



#endif
