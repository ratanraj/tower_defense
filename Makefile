# Define the compiler
CXX := g++

# Use pkg-config to get Allegro CFLAGS and LIBS
CFLAGS := $(shell pkg-config --cflags allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5)
LIBS := $(shell pkg-config --libs allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5)

# Define the source files and the target executable
SOURCES := main.cpp game.cpp
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := game

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBS)

# Rule to compile the source files
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean

