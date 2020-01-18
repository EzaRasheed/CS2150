#name:Eza Rasheed
#id: er6qt
#date: 02-28-19
#filename: Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2 -std=c++11
DEBUG=-Wall -g

OFILES = AVLNode.o AVLTree.o AVLPathTest.o \

.SUFFIXES: .o .cpp

AVL: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out
	@echo "Done!"
	
AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp

AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.cpp AVLNode.h
	$(CXX) -c AVLTree.cpp
	
AVLPathTest.o: AVLPathTest.cpp AVLTree.cpp AVLTree.h AVLNode.cpp AVLNode.h
	$(CXX) -c AVLPathTest.cpp
	
clean:
	-rm -f *.o *~ AVL
	
AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
