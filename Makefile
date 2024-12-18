PROG = main.exe 
SRC = main.cpp src/Bank.cpp src/BankAccount.cpp src/DistributedVectorAccountStorage.cpp src/MapStorage.cpp src/VectorAccountStorage.cpp
CFLAGS = -g -std=c++17
LIBS = 
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean