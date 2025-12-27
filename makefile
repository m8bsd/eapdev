# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -O2

# Program name
TARGET = hello

# Source files
SRCS = main.c

# Default target
all: $(TARGET)

# Build the program
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean build files
clean:
	rm -f $(TARGET)

.PHONY: all clean
