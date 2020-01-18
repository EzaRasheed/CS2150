#name:Eza Rasheed
#id: er6qt
#date: 04-18-19 
#filename: Makefile


# Makefile for CS 2150 pre-lab 8
# This Makefile shows how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX	= clang++ -m64

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g


# Defines the flags for the assembler
ASFLAGS	= -f elf64 -g

# All of the .o files for our program
OFILES	= huffmanenc.o huffmandec.o heapNode.o heap.o heapTree.o

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# Reference: https://stackoverflow.com/questions/5950395/makefile-to-compile-multiple-c-programs
all: encoder decoder

encoder: huffmanenc.o heap.o heapNode.o heapTree.o
	$(CXX) $(CXXFLAGS) huffmanenc.o heap.o heapNode.o heapTree.o -o encoder
decoder: huffmandec.o heapNode.o
	$(CXX) $(CXXFLAGS) huffmandec.o heapNode.o -o decoder

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program
 
