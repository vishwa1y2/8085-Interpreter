/*
-----------------------------------------------------------------------
(c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
-----------------------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>

#include "defs.h"
#include "libs.h"

struct memorySchema vector[MEMORY_END - MEMORY_ADDR ];		// Initialize memory for program space.

struct dataSchema dataVector[DATA_REGION_END - DATA_REGION_START ];// Initialize memory for data space.

struct stackSchema stackVector[STACK_ADDR_START - STACK_ADDR_END ];	// Initialize memory for stack space.

extern int progInMem;

int main(int argc,char **argv){

system("clear");

printf(_HEADER_STRING_);
  
//Everything is alright, by the way.
char str[20];
progInMem = 0;
printf("Don't give leading or trailing spaces in commands.Type help for more.\n");
while(1){
printf("\nSimulator @ 8085 $ ");
fflush(stdin);
gets(str);

if(strcmp(str,"help")==0)
{
printf(_HELP_);	
}
else if(strcmp(str,"new")==0)
{progInMem = 1;
init();
getUserCodeCmd();
}
else if(strcmp(str,"open")==0 )
{
init();
char filename[100];
printf("\nEnter File name(<100 chars) : ");
gets(filename);
openProgram(filename); 

}
else if(strcmp(str,"goto")==0)
{
if(progInMem==0){
printf("No code entered yet !\n");
}
else
{
initGoto();
takeSingleInstruction(); 
}
}

else if(strcmp(str,"run")==0)
{
if(progInMem==0){
printf("No code entered yet !\n");
}
else
executeProgram(0); 
}
else if(strcmp(str,"run -d")==0)
{
if(progInMem==0){
printf("No code entered yet !\n");
}
else
executeProgram(1);
}
else if(strcmp(str,"clear")==0 ){
system("clear");
}
else if(strcmp(str,"result")==0 ){
if(progInMem==0){
printf("No code entered yet !\n");
}
else
printAllRegisters(0);
}
else if(strcmp(str,"show")==0)
{
if(progInMem == 0){
printf("No code entered yet !\n");

}
else
printProgram();
}
else if(strcmp(str,"open")==0)
{
char filename[100];
printf("\nEnter File name(<100 chars) : ");
gets(filename);
openProgram(filename);

}
else if(strcmp(str,"exit")==0)
{
printf("\nGood Bye!\n");
exit(0);
}
else if(strcmp(str,"save")==0 && progInMem)
{
char filename[100];
printf("\nEnter File name(<100 chars) : ");
gets(filename);
saveProgram(filename);
}
else 
	printf("\nCommand not found. Don't give leading or trailing spaces.\n");
}
return 0;
}

