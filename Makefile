# Paths
SRC = ./src
INCLUDE = ../include

# Compiler
CC = g++

# Compile Options
CFLAGS = -Wall -Werror -I$(INCLUDE);

# Executable
EXEC = booksim

# Arguments
ARG = 100 20 10 2

# Object files
OBJ = $(SRC)/main.o $(SRC)/classes.o

all: $(EXEC)

$(EXEC): $(OBJ)

	$(CC) $(OBJ) -o $(EXEC) 

run: $(EXEC)
	./$(EXEC) $(ARG)

clean:
	rm -f $(OBJ) $(EXEC) 