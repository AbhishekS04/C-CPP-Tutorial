# Makefile for Hello World Programs
# This makefile compiles all the Hello World example programs

# Compiler settings
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
TARGET_DIR = .
SOURCE_DIR = .

# Source files
SOURCES = hello.c hello_enhanced.c hello_interactive.c hello_functions.c

# Executable names (remove .c extension)
TARGETS = $(SOURCES:.c=)

# Default target - build all programs
all: $(TARGETS)
	@echo "All Hello World programs compiled successfully!"
	@echo "Available executables:"
	@echo "  - hello           : Basic Hello World"
	@echo "  - hello_enhanced  : Enhanced with formatting"
	@echo "  - hello_interactive : Interactive with user input"
	@echo "  - hello_functions : Multi-function example"

# Rule to compile individual C files
%: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $< -o $@

# Specific targets for each program
hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

hello_enhanced: hello_enhanced.c
	$(CC) $(CFLAGS) hello_enhanced.c -o hello_enhanced

hello_interactive: hello_interactive.c
	$(CC) $(CFLAGS) hello_interactive.c -o hello_interactive

hello_functions: hello_functions.c
	$(CC) $(CFLAGS) hello_functions.c -o hello_functions

# Run targets
run-hello: hello
	@echo "Running basic Hello World:"
	@echo "=========================="
	./hello

run-enhanced: hello_enhanced
	@echo "Running enhanced Hello World:"
	@echo "=============================="
	./hello_enhanced

run-interactive: hello_interactive
	@echo "Running interactive Hello World:"
	@echo "================================"
	./hello_interactive

run-functions: hello_functions
	@echo "Running multi-function Hello World:"
	@echo "==================================="
	./hello_functions

# Run all programs
run-all: all
	@echo "\n=== Running all Hello World programs ==="
	@echo "\n1. Basic Hello World:"
	@echo "========================"
	@./hello
	@echo "\n2. Enhanced Hello World:"
	@echo "========================="
	@./hello_enhanced
	@echo "\n3. Multi-function Hello World:"
	@echo "==============================="
	@./hello_functions

# Debug builds
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGETS)
	@echo "Debug versions compiled successfully!"

# Release builds with optimization
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGETS)
	@echo "Release versions compiled successfully!"

# Clean up compiled files
clean:
	@echo "Cleaning up compiled files..."
	rm -f $(TARGETS)
	rm -f *.exe  # Windows executables
	rm -f *.o    # Object files
	@echo "Clean completed!"

# Help target
help:
	@echo "Available targets:"
	@echo "  all            - Compile all Hello World programs"
	@echo "  hello          - Compile basic Hello World"
	@echo "  hello_enhanced - Compile enhanced Hello World"
	@echo "  hello_interactive - Compile interactive Hello World"
	@echo "  hello_functions - Compile multi-function Hello World"
	@echo "  run-hello      - Run basic Hello World"
	@echo "  run-enhanced   - Run enhanced Hello World"
	@echo "  run-interactive - Run interactive Hello World"
	@echo "  run-functions  - Run multi-function Hello World"
	@echo "  run-all        - Run all programs sequentially"
	@echo "  debug          - Compile with debug flags"
	@echo "  release        - Compile with optimization"
	@echo "  clean          - Remove compiled files"
	@echo "  help           - Show this help message"

# Test compilation with different standards
test-standards:
	@echo "Testing compilation with different C standards..."
	@echo "C89/C90:"
	$(CC) -std=c90 -Wall hello.c -o hello_c90 && ./hello_c90 && rm hello_c90
	@echo "C99:"
	$(CC) -std=c99 -Wall hello.c -o hello_c99 && ./hello_c99 && rm hello_c99
	@echo "C11:"
	$(CC) -std=c11 -Wall hello.c -o hello_c11 && ./hello_c11 && rm hello_c11
	@echo "All standards test completed!"

# Check for memory leaks (Linux/macOS with Valgrind)
valgrind-check: all
	@echo "Running Valgrind memory check..."
	@command -v valgrind >/dev/null 2>&1 || { echo "Valgrind not installed. Skipping memory check."; exit 0; }
	valgrind --leak-check=full --show-leak-kinds=all ./hello
	valgrind --leak-check=full --show-leak-kinds=all ./hello_enhanced
	valgrind --leak-check=full --show-leak-kinds=all ./hello_functions

# Static analysis with cppcheck (if available)
static-analysis:
	@echo "Running static analysis..."
	@command -v cppcheck >/dev/null 2>&1 || { echo "Cppcheck not installed. Skipping static analysis."; exit 0; }
	cppcheck --enable=all --std=c11 *.c

# Make targets that don't correspond to files
.PHONY: all clean help run-hello run-enhanced run-interactive run-functions run-all debug release test-standards valgrind-check static-analysis
