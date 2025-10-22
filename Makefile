CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

SRC = llrec.cpp llrec-test.cpp
EXE = llrec-test.cpp

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 