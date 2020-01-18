#name:Eza Rasheed
#id: er6qt
#date: 03-04-19
#filename: Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -std=c++11
DEBUG=-Wall -g

OFILES = wordPuzzle.o timer.o hashTable.o \

.SUFFIXES: .o .cpp

HT: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out
	@echo "Done!"
	
wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

timer.o: timer.cpp timer.h timer_test.cpp
	$(CXX) -c timer.cpp
	
hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp
	
clean:
	-rm -f *.o *~ HT
	
hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h
