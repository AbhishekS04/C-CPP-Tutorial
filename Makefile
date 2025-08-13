# Master Makefile for C/C++ Tutorial
# This makefile provides commands to build and run examples from all sections

# Compiler settings
CC = gcc
CXX = g++
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color

# Directories
C_BASICS_DIR = 01-C-Basics
C_INTERMEDIATE_DIR = 02-C-Intermediate
C_ADVANCED_DIR = 03-C-Advanced
CPP_BASICS_DIR = 04-CPP-Basics
CPP_INTERMEDIATE_DIR = 05-CPP-Intermediate
CPP_ADVANCED_DIR = 06-CPP-Advanced
PROJECTS_DIR = 07-Projects
EXERCISES_DIR = 08-Exercises

.PHONY: all clean help c-basics cpp-basics test setup-environment

# Default target
all: help

# Help target - shows available commands
help:
	@echo "$(GREEN)C/C++ Tutorial Build System$(NC)"
	@echo "================================"
	@echo ""
	@echo "$(YELLOW)Available targets:$(NC)"
	@echo "  help              - Show this help message"
	@echo "  setup-environment - Check and setup development environment"
	@echo "  c-basics          - Build all C basics examples"
	@echo "  hello-world       - Build Hello World examples"
	@echo "  variables-demo    - Build variables and data types examples"
	@echo "  cpp-basics        - Build all C++ basics examples"
	@echo "  test              - Run basic compilation tests"
	@echo "  clean             - Remove all compiled files"
	@echo "  clean-all         - Deep clean all build artifacts"
	@echo "  check-style       - Run code style checks (if tools available)"
	@echo "  install-deps      - Install development dependencies (Linux/macOS)"
	@echo ""
	@echo "$(YELLOW)Quick Start:$(NC)"
	@echo "  1. Run 'make setup-environment' first"
	@echo "  2. Run 'make hello-world' to build first examples"
	@echo "  3. Run 'make test' to verify everything works"
	@echo ""
	@echo "$(YELLOW)Tutorial Sections:$(NC)"
	@echo "  $(GREEN)C Programming:$(NC)"
	@echo "    - 01-C-Basics: Fundamentals of C programming"
	@echo "    - 02-C-Intermediate: Advanced C concepts"
	@echo "    - 03-C-Advanced: System programming and advanced topics"
	@echo ""
	@echo "  $(GREEN)C++ Programming:$(NC)"
	@echo "    - 04-CPP-Basics: Object-oriented programming basics"
	@echo "    - 05-CPP-Intermediate: STL and advanced C++ features"
	@echo "    - 06-CPP-Advanced: Modern C++ and design patterns"
	@echo ""
	@echo "  $(GREEN)Practice:$(NC)"
	@echo "    - 07-Projects: Real-world programming projects"
	@echo "    - 08-Exercises: Practice problems and solutions"

# Setup development environment
setup-environment:
	@echo "$(GREEN)Checking Development Environment...$(NC)"
	@echo "====================================="
	@echo -n "Checking for GCC compiler... "
	@command -v gcc >/dev/null 2>&1 && echo "$(GREEN)✓ Found$(NC)" || echo "$(RED)✗ Not found$(NC)"
	@echo -n "Checking for G++ compiler... "
	@command -v g++ >/dev/null 2>&1 && echo "$(GREEN)✓ Found$(NC)" || echo "$(RED)✗ Not found$(NC)"
	@echo -n "Checking for Make... "
	@command -v make >/dev/null 2>&1 && echo "$(GREEN)✓ Found$(NC)" || echo "$(RED)✗ Not found$(NC)"
	@echo -n "Checking for Git... "
	@command -v git >/dev/null 2>&1 && echo "$(GREEN)✓ Found$(NC)" || echo "$(RED)✗ Not found$(NC)"
	@echo ""
	@echo "$(YELLOW)Compiler Versions:$(NC)"
	@gcc --version 2>/dev/null | head -1 || echo "GCC not available"
	@g++ --version 2>/dev/null | head -1 || echo "G++ not available"
	@echo ""
	@echo "$(YELLOW)System Information:$(NC)"
	@echo "OS: $$(uname -s 2>/dev/null || echo 'Unknown')"
	@echo "Architecture: $$(uname -m 2>/dev/null || echo 'Unknown')"

# Build Hello World examples
hello-world:
	@echo "$(GREEN)Building Hello World Examples...$(NC)"
	@echo "================================="
	@if [ -d "$(C_BASICS_DIR)/01-hello-world" ]; then \
		cd $(C_BASICS_DIR)/01-hello-world && $(MAKE) all; \
	else \
		echo "$(RED)Hello World directory not found!$(NC)"; \
		exit 1; \
	fi

# Build variables and data types examples
variables-demo:
	@echo "$(GREEN)Building Variables Demo...$(NC)"
	@echo "=========================="
	@if [ -d "$(C_BASICS_DIR)/02-variables-datatypes" ]; then \
		cd $(C_BASICS_DIR)/02-variables-datatypes && $(MAKE) all 2>/dev/null || echo "No Makefile found, building manually..."; \
		if [ -f "$(C_BASICS_DIR)/02-variables-datatypes/variables_demo.c" ]; then \
			$(CC) $(CFLAGS) $(C_BASICS_DIR)/02-variables-datatypes/variables_demo.c -o $(C_BASICS_DIR)/02-variables-datatypes/variables_demo; \
			echo "$(GREEN)✓ Built variables_demo$(NC)"; \
		fi \
	else \
		echo "$(RED)Variables directory not found!$(NC)"; \
	fi

# Build all C basics examples
c-basics: hello-world variables-demo
	@echo "$(GREEN)All C Basics examples built!$(NC)"

# Build all C++ basics examples (placeholder)
cpp-basics:
	@echo "$(YELLOW)C++ basics examples coming soon...$(NC)"

# Test compilation and execution
test:
	@echo "$(GREEN)Running Basic Tests...$(NC)"
	@echo "======================"
	@echo "Testing Hello World compilation and execution:"
	@if [ -f "$(C_BASICS_DIR)/01-hello-world/hello" ]; then \
		echo "$(GREEN)✓ Hello World compiled$(NC)"; \
		cd $(C_BASICS_DIR)/01-hello-world && ./hello; \
	else \
		echo "$(YELLOW)Building Hello World first...$(NC)"; \
		$(MAKE) hello-world && cd $(C_BASICS_DIR)/01-hello-world && ./hello; \
	fi

# Clean compiled files
clean:
	@echo "$(GREEN)Cleaning compiled files...$(NC)"
	@find . -name "*.o" -delete 2>/dev/null || true
	@find . -name "*.exe" -delete 2>/dev/null || true
	@find . -type f -executable ! -name "*.sh" ! -name "*.py" ! -path "*/.*" -delete 2>/dev/null || true
	@echo "$(GREEN)✓ Clean completed$(NC)"

# Deep clean including backup files
clean-all: clean
	@echo "$(GREEN)Deep cleaning...$(NC)"
	@find . -name "*~" -delete 2>/dev/null || true
	@find . -name "*.swp" -delete 2>/dev/null || true
	@find . -name "*.swo" -delete 2>/dev/null || true
	@find . -name ".DS_Store" -delete 2>/dev/null || true
	@echo "$(GREEN)✓ Deep clean completed$(NC)"

# Install development dependencies (Linux/macOS)
install-deps:
	@echo "$(GREEN)Installing Development Dependencies...$(NC)"
	@echo "======================================"
	@if command -v apt-get >/dev/null 2>&1; then \
		echo "Detected Ubuntu/Debian system"; \
		sudo apt-get update && sudo apt-get install -y build-essential gdb valgrind cppcheck clang-format; \
	elif command -v dnf >/dev/null 2>&1; then \
		echo "Detected Fedora system"; \
		sudo dnf install -y gcc gcc-c++ make gdb valgrind cppcheck clang-tools-extra; \
	elif command -v yum >/dev/null 2>&1; then \
		echo "Detected RHEL/CentOS system"; \
		sudo yum groupinstall -y "Development Tools" && sudo yum install -y gdb valgrind; \
	elif command -v brew >/dev/null 2>&1; then \
		echo "Detected macOS with Homebrew"; \
		brew install gcc gdb cppcheck clang-format; \
	elif command -v pacman >/dev/null 2>&1; then \
		echo "Detected Arch Linux system"; \
		sudo pacman -S base-devel gdb valgrind cppcheck clang; \
	else \
		echo "$(YELLOW)Could not detect package manager. Please install manually:$(NC)"; \
		echo "- GCC/G++ compiler"; \
		echo "- Make"; \
		echo "- GDB debugger"; \
		echo "- Valgrind (optional)"; \
		echo "- Cppcheck (optional)"; \
	fi

# Style checking (if tools are available)
check-style:
	@echo "$(GREEN)Checking Code Style...$(NC)"
	@echo "======================"
	@if command -v clang-format >/dev/null 2>&1; then \
		echo "Running clang-format check..."; \
		find . -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | head -10 | xargs clang-format --dry-run -Werror 2>/dev/null && echo "$(GREEN)✓ Style check passed$(NC)" || echo "$(YELLOW)Style issues found$(NC)"; \
	else \
		echo "$(YELLOW)clang-format not available$(NC)"; \
	fi
	@if command -v cppcheck >/dev/null 2>&1; then \
		echo "Running cppcheck static analysis..."; \
		find . -name "*.c" -o -name "*.cpp" | head -5 | xargs cppcheck --quiet --error-exitcode=0 2>/dev/null && echo "$(GREEN)✓ Static analysis completed$(NC)" || true; \
	else \
		echo "$(YELLOW)cppcheck not available$(NC)"; \
	fi

# Build documentation (placeholder)
docs:
	@echo "$(YELLOW)Documentation generation coming soon...$(NC)"
	@echo "For now, open README.md files in each directory"

# Development workflow targets
dev-setup: setup-environment install-deps
	@echo "$(GREEN)Development environment setup completed!$(NC)"

# Quick test of basic functionality
quick-test: hello-world test
	@echo "$(GREEN)Quick test completed successfully!$(NC)"

# Tutorial progression helper
next-step:
	@echo "$(GREEN)Tutorial Progress Helper$(NC)"
	@echo "========================"
	@echo ""
	@echo "$(YELLOW)Recommended learning path:$(NC)"
	@echo ""
	@echo "1. $(GREEN)Start Here:$(NC) Complete setup with 'make setup-environment'"
	@echo "2. $(GREEN)Hello World:$(NC) Run 'make hello-world' and explore 01-C-Basics/01-hello-world/"
	@echo "3. $(GREEN)Variables:$(NC) Study 01-C-Basics/02-variables-datatypes/"
	@echo "4. $(GREEN)Continue:$(NC) Work through each section in 01-C-Basics/"
	@echo "5. $(GREEN)Practice:$(NC) Complete exercises in each section"
	@echo ""
	@echo "$(YELLOW)Current status:$(NC)"
	@if [ -f "$(C_BASICS_DIR)/01-hello-world/hello" ]; then \
		echo "$(GREEN)✓ Hello World completed$(NC)"; \
	else \
		echo "$(YELLOW)○ Hello World - run 'make hello-world'$(NC)"; \
	fi

# Create a new exercise/project template
create-exercise:
	@read -p "Enter exercise name: " name; \
	read -p "Enter section (c-basics/c-intermediate/etc.): " section; \
	mkdir -p "08-Exercises/$$section/$$name"; \
	echo "// Exercise: $$name" > "08-Exercises/$$section/$$name/$$name.c"; \
	echo "// Section: $$section" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "#include <stdio.h>" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "int main() {" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "    // Your code here" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "    return 0;" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "}" >> "08-Exercises/$$section/$$name/$$name.c"; \
	echo "$(GREEN)Created exercise template at 08-Exercises/$$section/$$name/$(NC)"

# Statistics about the tutorial
stats:
	@echo "$(GREEN)Tutorial Statistics$(NC)"
	@echo "==================="
	@echo "C source files: $$(find . -name "*.c" | wc -l)"
	@echo "C++ source files: $$(find . -name "*.cpp" | wc -l)"
	@echo "Header files: $$(find . -name "*.h" -o -name "*.hpp" | wc -l)"
	@echo "README files: $$(find . -name "README.md" | wc -l)"
	@echo "Makefiles: $$(find . -name "Makefile" -o -name "makefile" | wc -l)"
	@echo "Total lines of code: $$(find . -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | xargs wc -l 2>/dev/null | tail -1 | awk '{print $$1}' || echo '0')"
	@echo "Directories: $$(find . -type d | wc -l)"

# Archive the tutorial for sharing
archive:
	@echo "$(GREEN)Creating tutorial archive...$(NC)"
	@tar -czf c-cpp-tutorial-$$(date +%Y%m%d).tar.gz \
		--exclude='*.o' --exclude='*.exe' --exclude='a.out' \
		--exclude='.git' --exclude='*.tar.gz' \
		.
	@echo "$(GREEN)Archive created: c-cpp-tutorial-$$(date +%Y%m%d).tar.gz$(NC)"
