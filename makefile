# compiler
CC = gcc

# compilation flags
CFLAGS = -Wall -Wextra -Iplayer -Ienemy -Ibattle

# executable which will be made
TARGET = game

# all source C files
SRC = main.c src/player.c src/enemy.c src/battle.c

# the out file made
OBJ = $(SRC:.c=.o)

# the default target
all: $(TARGET)

# compiling command
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# compile .c into .0
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# make clean to clean up all of the junk
clean:
	rm -rf $(TARGET) $(OBJ)