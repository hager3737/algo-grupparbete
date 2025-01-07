PROG = main.exe
SRC = main.cpp src/Del2.cpp
OBJ = $(SRC:.cpp=.o)
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
