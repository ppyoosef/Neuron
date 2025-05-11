# Makefile for Tic Tac Toe SDL3 App

# Compiler
CXX = g++

# Paths
INCLUDES = -Iinclude


# Files
SRC = main.cpp
OUT_DIR = build
TARGET = $(OUT_DIR)/Neuron.exe


# Build Rule
$(TARGET): $(SRC)
#	@mkdir -p $(OUT_DIR) #for linux
	mkdir $(OUT_DIR)
	$(CXX) $(SRC) -o $(TARGET) $(INCLUDES)

	
# Clean Rule
clean:
#	@rm -rf $(OUT_DIR)
	del /Q $(OUT_DIR)\*

# Default Target
all: $(TARGET)
