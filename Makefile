#Mark Gomes
#Makefile for programming assignment 2
#This Makefile compiles all the files in this project
# To use this Makefile, you type:
#
#        make anitran
#                   
#       
# A binary named anitran will be produced

CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

INCLUDES   = includes.h
HEADERS    = constants.h structs.h Graphics.h Shape.h
PROTOTYPES = prototypes.h
GLOBALS    = globals.h
OBJS 	   = Graphics.o input.o display.o Shape.o tessellate.o transmat.o clipping.o

all : run

run: main.o $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS) $(OBJS) 
	$(C++) -o run main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS) 

Graphics.o : Graphics.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c Graphics.cc
 
Shape.o : Shape.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c Shape.cc

display.o : display.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c display.cc

input.o : input.cc $(INCLUDES) $(HEADERS) $(GLOBALS)
	$(C++) -c input.cc

transmat.o : transmat.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c transmat.cc

clipping.o : clipping.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c clipping.cc

tessellate.o : tessellate.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS)
	$(C++) -c tessellate.cc

main.o : main.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(OBJS) 
	$(C++) -c main.cc 

clean :
	rm *.o

reset :
	rm *.o
	rm run
