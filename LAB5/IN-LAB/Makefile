#name:Eza Rasheed
#id: er6qt
#date: 02-26-19
#filename: Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2 -std=c++11
DEBUG=-Wall -g

OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o \

.SUFFIXES: .o .cpp

BST: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	@echo "Done!"
	
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinarySearchTree.cpp
	
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.cpp BinarySearchTree.h BinaryNode.cpp BinaryNode.h
	$(CXX) -c BSTPathTest.cpp
	
clean:
	-rm -f *.o *~ BST
	
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
