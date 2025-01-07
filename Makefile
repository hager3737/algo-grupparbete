PROG = main.exe 
SRC = main.cpp Del1/src/Bank.cpp Del1/src/BankAccount.cpp Del1/src/UtilityFunctions.cpp Del1/src/BinarySearchStorage.cpp Del1/src/RunPart1 Del2/src/Del2.cpp
CFLAGS = -g -std=c++17
LIBS = 
CC = g++
all: $(PROG)
$(PROG): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(PROG)
.PHONY: all clean
