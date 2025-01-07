PROG = main.exe 
SRC = main.cpp src/Bank.cpp src/BankAccount.cpp src/UtilityFunctions.cpp src/BinarySearchStorage.cpp
CFLAGS = -g -std=c++17
LIBS = 
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean