# Compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror -g -O2
LDFLAGS = 

# Target executable name
TARGET = writer

# Source files
SRCS = writer.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target: build the writer application
all: $(TARGET)

# Build the writer executable from object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove executable and object files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets (not actual files)
.PHONY: all clean