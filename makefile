# Relative path definitions

INCDIR = include
OBJDIR = build
SRCDIR = src
BINDIR = bin


# Compiler and compiler flag definitions

CC = gcc
CFLAGS = -I $(INCDIR) -Wall


# Variables for files located in file directories
# Headers are given together as they can be grouped

_HEADERS = display.h player.h game.h
HEADERS = $(patsubst %,$(INCDIR)/%,$(_HEADERS))

# Object files except main.o  are given together for final executable linking
# As main.h does not exist, compiler cannot create main.o based on main.c 

_OBJECTS = game.o player.o display.o
OBJECTS = $(patsubst %,$(OBJDIR)/%,$(_OBJECTS))


# All object files are grouped in this variable for final executable link 

OBJ = $(OBJDIR)/%.o

# All source files are grouped in this variable for all object file creation

SRC = $(SRCDIR)/%.c



# Final executable has a separate path, so it is also provided a variable

_BIN = TicTacToe
BIN = $(patsubst %,$(BINDIR)/%, $(_BIN))






# phony target: all:  contains the final executable

all: $(BIN)

# Target is final executable: it requires all object files
$(BIN): $(OBJECTS) build/main.o
	@$(CC) $^ -o $@ $(CFLAGS)
	@echo "Build completed!"


# main.o is compiled separately as it requires game.h
build/main.o: src/main.c include/game.h
	@$(CC) -c $< -o $@ $(CFLAGS)


# All object files except main.o are created here
$(OBJ): $(SRC) $(HEADERS)
	@$(CC) -c $< -o $@ $(CFLAGS)


# phony target: clean: removes the generated files
clean: 
	@rm -f $(OBJECTS) $(BIN) build/main.o
	@echo "Clean completed!"
