#Mark Gomes
#Makefile for programming assignment 3
#This Makefile compiles all the files in this project
# To use this Makefile, you type:
#
#        make
#                   
# A binary named [run] will be produced

CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

INCLUDES   = includes.h
HEADERS    = constants.h structs.h
PROTOTYPES = prototypes.h
GLOBALS    = globals.h
OBJS 	   = input.o display.o reshape.o drawAxis.o defineHouse.o drawHouse.o transmat.o

all : run

run: main.o $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS) $(OBJS) 
	$(C++) -o run main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS) 

display.o : display.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c display.cc

reshape.o : reshape.cc $(INCLUDES) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c reshape.cc

drawAxis.o : drawAxis.cc $(INCLUDES) $(PROTOTYPES)
	$(C++) -c drawAxis.cc

defineHouse.o : defineHouse.cc $(INCLUDES) $(PROTOTYPES) $(HEADERS)
	$(C++) -c defineHouse.cc

drawHouse.o : drawHouse.cc $(INCLUDES) $(PROTOTYPES) $(HEADERS)
	$(C++) -c drawHouse.cc

input.o : input.cc $(INCLUDES) $(HEADERS) $(GLOBALS) $(PROTOTYPES)
	$(C++) -c input.cc

transmat.o : transmat.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c transmat.cc

main.o : main.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(OBJS) 
	$(C++) -c main.cc 

clean :
	rm *.o

pristine :
	rm *.o
	rm run
