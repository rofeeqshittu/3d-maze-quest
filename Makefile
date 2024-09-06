# Compiler to use
CC = gcc

# Compiler flags: 
# -Wall: show all warnings
# -Wextra: show extra warnings
# -O2: optimize the code
CFLAGS = -Wall -Wextra -O2

# SDL2 library linking flag
LIBS = -lSDL2

# Source files (.c files)
SRC = main.c player.c raycasting.c world.c

# Object files (.o files) - automatically generated from source files
OBJ = $(SRC:.c=.o)

# Output executable name
TARGET = 3dmazequest

# Rule to build the target executable from the object files
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LIBS)

# Rule to clean up the object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

