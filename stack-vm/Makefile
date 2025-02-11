CFLAGS=-std=c++11

all: stack-vm

stack-vm: stack-vm.o main.o
	$(CXX) $(CFLAGS) stack-vm.o main.o -o stack-vm  # ← Make sure this starts with a TAB

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp  # ← TAB here

stack-vm.o: stack-vm.h stack-vm.cpp
	$(CXX) $(CFLAGS) -c stack-vm.cpp  # ← TAB here

clean:
	rm -f *.o stack-vm  # ← TAB here
