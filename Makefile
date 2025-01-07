PROG = main.exe
SRC = main.cpp del1/src/Bank.cpp del1/src/BankAccount.cpp del1/src/UtilityFunctions.cpp del1/src/BinarySearchStorage.cpp del1/src/RunPart1.cpp del2/src/Del2.cpp del3/src/Del3.cpp
CFLAGS = -g -std=c++17
LIBS =
CC = g++

# Define OBJ as a list of object files from the source files
OBJ = $(SRC:.cpp=.o)

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(PROG)

.PHONY: all clean
