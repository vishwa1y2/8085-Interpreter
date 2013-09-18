# (c)2013 Vishwamitra Yadvendu <yad.vishu@gmail.com>
#
# This is Makefile for a simulator program.
# Typing 'make' or 'make simulator' will create the executable file.
#

#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
#
default: simulator

# To create the executable file simulator we need the object files
# instructions.o libs.o defs.o  call.o main.o alu.o
#
simulator:  instructions.o libs.o defs.o  call.o main.o alu.o
	$(CC) $(CFLAGS) -o simulator instructions.o libs.o defs.o call.o main.o alu.o

# To create the object file for all .o file, we need the source
# files which have dependency, but i've included all, Sorry for this.:
#
instructions.o:  instructions.c libs.h defs.h libs.c call.c main.c alu.c
	$(CC) $(CFLAGS) -c instructions.c

libs.o:  instructions.c libs.h defs.h libs.c call.c main.c alu.c 
	$(CC) $(CFLAGS) -c libs.c

defs.o:  instructions.c libs.h defs.h libs.c call.c main.c alu.c
	$(CC) $(CFLAGS) -c defs.c

call.o:	instructions.c libs.h defs.h libs.c call.c main.c alu.c
	$(CC) $(CFLAGS) -c call.c

main.o:	instructions.c libs.h defs.h libs.c call.c main.c alu.c
	$(CC) $(CFLAGS) -c main.c

alu.o:	instructions.c libs.h defs.h libs.c call.c main.c alu.c
	$(CC) $(CFLAGS) -c alu.c


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) simulator *.o *~
