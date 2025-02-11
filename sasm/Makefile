CXX = g++
CFLAGS = -std=c++11

all: sasm

sasm: sasm.o lexer.o
	$(CXX) $(CFLAGS) sasm.o lexer.o -o sasm

lexer.o: lexer.h lexer.cpp
	$(CXX) $(CFLAGS) -c lexer.cpp -o lexer.o

sasm.o: lexer.h sasm.cpp
	$(CXX) $(CFLAGS) -c sasm.cpp -o sasm.o

clean:
	rm -f sasm *.o *.bin