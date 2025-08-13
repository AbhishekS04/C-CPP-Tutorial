# C/C++ Coding Standards and Best Practices

This document outlines the coding standards and best practices used throughout this tutorial. Following these conventions will make your code more readable, maintainable, and professional.

## 📋 Table of Contents

1. [General Principles](#general-principles)
2. [C Coding Standards](#c-coding-standards)
3. [C++ Coding Standards](#cpp-coding-standards)
4. [Naming Conventions](#naming-conventions)
5. [Code Formatting](#code-formatting)
6. [Documentation Standards](#documentation-standards)
7. [Error Handling](#error-handling)
8. [Performance Guidelines](#performance-guidelines)
9. [Security Best Practices](#security-best-practices)
10. [Tools and Automation](#tools-and-automation)

## 🎯 General Principles

### Code Quality Principles
1. **Clarity over Cleverness**: Write code that is easy to understand
2. **Consistency**: Follow established patterns throughout your codebase
3. **Simplicity**: Keep solutions as simple as possible
4. **DRY Principle**: Don't Repeat Yourself
5. **YAGNI**: You Aren't Gonna Need It (don't over-engineer)

### The Boy Scout Rule
> "Always leave the code cleaner than you found it."

## 🔤 C Coding Standards

### Header Files
```c
#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// System includes first
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Local includes second
#include "local_header.h"

// Constants and macros
#define MAX_BUFFER_SIZE 1024
#define PI 3.14159265359

// Type definitions
typedef struct {
    int id;
    char name[50];
} person_t;

// Function declarations
int calculate_sum(int a, int b);
void print_person(const person_t* person);

#endif // HEADER_NAME_H
```

### Function Definitions
```c
/**
 * @brief Calculates the sum of two integers
 * @param a First integer
 * @param b Second integer
 * @return Sum of a and b
 */
int calculate_sum(int a, int b) {
    // Validate inputs if necessary
    if (a > INT_MAX - b) {
        fprintf(stderr, "Integer overflow detected\n");
        return -1; // or handle error appropriately
    }
    
    return a + b;
}
```

### Variable Declarations
```c
// Group related variables
int width, height, depth;
char buffer[MAX_BUFFER_SIZE];
FILE* input_file = NULL;

// Initialize variables at declaration when possible
int count = 0;
bool is_valid = false;
```

### Control Structures
```c
// Always use braces, even for single statements
if (condition) {
    do_something();
}

// Prefer early returns to reduce nesting
if (!is_valid_input(data)) {
    return ERROR_INVALID_INPUT;
}

// Process valid data here
```

## ➕ C++ Coding Standards

### Class Definitions
```cpp
class Calculator {
private:
    double last_result_;
    std::string operation_history_;

public:
    // Constructor
    Calculator() : last_result_(0.0), operation_history_("") {}
    
    // Destructor
    ~Calculator() = default;
    
    // Copy constructor
    Calculator(const Calculator& other) = default;
    
    // Move constructor
    Calculator(Calculator&& other) noexcept = default;
    
    // Assignment operators
    Calculator& operator=(const Calculator& other) = default;
    Calculator& operator=(Calculator&& other) noexcept = default;
    
    // Public methods
    double Add(double a, double b);
    double GetLastResult() const { return last_result_; }
    
    // Static methods
    static bool IsValidNumber(double num);
};
```

### Modern C++ Features (C++11 and later)
```cpp
// Use auto for type deduction
auto result = CalculateComplexValue();
auto numbers = std::vector<int>{1, 2, 3, 4, 5};

// Range-based for loops
for (const auto& number : numbers) {
    std::cout << number << " ";
}

// Smart pointers instead of raw pointers
std::unique_ptr<Calculator> calc = std::make_unique<Calculator>();
std::shared_ptr<Data> shared_data = std::make_shared<Data>();

// Lambda functions
auto is_even = [](int n) { return n % 2 == 0; };
```

### RAII (Resource Acquisition Is Initialization)
```cpp
class FileHandler {
private:
    std::ifstream file_;

public:
    explicit FileHandler(const std::string& filename) : file_(filename) {
        if (!file_.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
    }
    
    // Destructor automatically closes file
    ~FileHandler() {
        if (file_.is_open()) {
            file_.close();
        }
    }
    
    // Disable copy to prevent resource issues
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
    
    // Enable move semantics
    FileHandler(FileHandler&& other) noexcept : file_(std::move(other.file_)) {}
};
```

## 📝 Naming Conventions

### Variables
```c
// C style: snake_case
int user_count;
char file_name[256];
double average_score;

// Constants: UPPER_SNAKE_CASE
#define MAX_USERS 1000
const int DEFAULT_TIMEOUT = 30;
```

```cpp
// C++ style: snake_case for local variables
int user_count;
std::string file_name;

// Member variables: trailing underscore
class MyClass {
private:
    int member_variable_;
    std::string class_name_;
};
```

### Functions
```c
// C style: snake_case
void calculate_average(void);
int get_user_input(void);
bool is_valid_email(const char* email);
```

```cpp
// C++ style: PascalCase for public methods
class Calculator {
public:
    double CalculateSum(double a, double b);
    bool IsValidInput(const std::string& input);
    
private:
    // snake_case for private methods
    void update_history_(const std::string& operation);
};
```

### Types
```c
// C style: snake_case with _t suffix
typedef struct {
    int id;
    char name[50];
} user_data_t;

typedef enum {
    STATUS_SUCCESS,
    STATUS_ERROR,
    STATUS_PENDING
} operation_status_t;
```

```cpp
// C++ style: PascalCase
class UserManager {};
struct UserData {};
enum class OperationStatus {
    kSuccess,
    kError,
    kPending
};
```

## 🎨 Code Formatting

### Indentation
- Use **4 spaces** for indentation (no tabs)
- Be consistent throughout the project

### Line Length
- Maximum **80-100 characters** per line
- Break long lines appropriately

### Braces
```c
// K&R style (opening brace on same line)
if (condition) {
    do_something();
} else {
    do_something_else();
}

// Function definitions: opening brace on new line
int main()
{
    return 0;
}
```

### Spacing
```c
// Spaces around operators
int result = a + b * c;
bool is_equal = (x == y);

// No space after function names
printf("Hello, World!\n");

// Space after keywords
if (condition) {
    while (running) {
        for (int i = 0; i < count; i++) {
            // code
        }
    }
}
```

## 📚 Documentation Standards

### File Headers
```c
/**
 * @file calculator.c
 * @brief Simple calculator implementation
 * @author Your Name
 * @date 2024-01-15
 * @version 1.0
 * 
 * This file contains the implementation of basic calculator
 * functions including addition, subtraction, multiplication,
 * and division operations.
 */
```

### Function Documentation
```c
/**
 * @brief Divides two numbers with error checking
 * 
 * This function performs division of two double precision
 * floating point numbers with proper error handling for
 * division by zero cases.
 * 
 * @param dividend The number to be divided
 * @param divisor The number to divide by (must not be zero)
 * @param result Pointer to store the result
 * @return true if division successful, false if divisor is zero
 * 
 * @warning divisor must not be zero
 * @see calculate_sum, calculate_product
 * 
 * Example usage:
 * @code
 * double result;
 * if (divide_numbers(10.0, 3.0, &result)) {
 *     printf("Result: %.2f\n", result);
 * }
 * @endcode
 */
bool divide_numbers(double dividend, double divisor, double* result);
```

### Inline Comments
```c
// Good: Explain WHY, not WHAT
int timeout = 300; // 5 minutes in seconds for network operations

// Bad: Obvious comment
int i = 0; // Initialize i to 0

// Good: Explain complex logic
// Use binary search to find insertion point
// This maintains sorted order in O(log n) time
int position = binary_search(array, size, target);
```

## 🚨 Error Handling

### C Error Handling
```c
typedef enum {
    RESULT_SUCCESS = 0,
    RESULT_ERROR_INVALID_INPUT,
    RESULT_ERROR_OUT_OF_MEMORY,
    RESULT_ERROR_FILE_NOT_FOUND
} result_code_t;

result_code_t process_file(const char* filename) {
    if (filename == NULL) {
        return RESULT_ERROR_INVALID_INPUT;
    }
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return RESULT_ERROR_FILE_NOT_FOUND;
    }
    
    // Process file...
    
    fclose(file);
    return RESULT_SUCCESS;
}

// Usage
result_code_t result = process_file("data.txt");
if (result != RESULT_SUCCESS) {
    fprintf(stderr, "Error processing file: %d\n", result);
    return 1;
}
```

### C++ Exception Handling
```cpp
class FileProcessor {
public:
    void ProcessFile(const std::string& filename) {
        if (filename.empty()) {
            throw std::invalid_argument("Filename cannot be empty");
        }
        
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }
        
        try {
            // Process file content
            ProcessContent(file);
        } catch (const std::exception& e) {
            // Log error and re-throw
            std::cerr << "Error processing content: " << e.what() << std::endl;
            throw;
        }
    }
    
private:
    void ProcessContent(std::ifstream& file) {
        // Implementation that might throw
    }
};

// Usage with proper exception handling
try {
    FileProcessor processor;
    processor.ProcessFile("data.txt");
} catch (const std::invalid_argument& e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
} catch (const std::runtime_error& e) {
    std::cerr << "Runtime error: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
}
```

## ⚡ Performance Guidelines

### Memory Management
```c
// C: Always pair malloc with free
char* buffer = malloc(size * sizeof(char));
if (buffer == NULL) {
    return RESULT_ERROR_OUT_OF_MEMORY;
}

// Use buffer...

free(buffer);
buffer = NULL; // Prevent double-free errors
```

```cpp
// C++: Prefer smart pointers
{
    auto buffer = std::make_unique<char[]>(size);
    // Use buffer...
    // Automatically freed when going out of scope
}

// Or use containers
std::vector<char> buffer(size);
// Automatically managed
```

### Efficient Algorithms
```cpp
// Prefer algorithms with better time complexity
std::sort(vec.begin(), vec.end()); // O(n log n)
// vs bubble sort O(n²)

// Use appropriate containers
std::unordered_map<std::string, int> lookup; // O(1) average lookup
// vs std::vector linear search O(n)

// Reserve capacity for vectors when size is known
std::vector<int> numbers;
numbers.reserve(1000); // Prevents multiple reallocations
```

## 🔒 Security Best Practices

### Buffer Safety
```c
// Unsafe
char buffer[100];
strcpy(buffer, user_input); // Buffer overflow risk

// Safe
char buffer[100];
strncpy(buffer, user_input, sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';

// Even better: use secure functions
#ifdef _MSC_VER
    strcpy_s(buffer, sizeof(buffer), user_input);
#else
    strlcpy(buffer, user_input, sizeof(buffer));
#endif
```

### Input Validation
```c
int get_positive_integer(void) {
    int value;
    char buffer[20];
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1; // Error reading input
    }
    
    // Remove newline if present
    buffer[strcspn(buffer, "\n")] = '\0';
    
    char* endptr;
    value = strtol(buffer, &endptr, 10);
    
    // Check for conversion errors
    if (*endptr != '\0' || value <= 0) {
        return -1; // Invalid input
    }
    
    return value;
}
```

## 🛠️ Tools and Automation

### Static Analysis Tools
```bash
# Cppcheck
cppcheck --enable=all --std=c11 src/

# Clang Static Analyzer
scan-build make

# PVS-Studio (commercial)
pvs-studio-analyzer trace -- make
```

### Code Formatting
```bash
# clang-format configuration (.clang-format file)
BasedOnStyle: Google
IndentWidth: 4
ColumnLimit: 100
AllowShortFunctionsOnASingleLine: None

# Format code
clang-format -i src/*.c src/*.h
```

### Compiler Warnings
```bash
# Enable all useful warnings
gcc -Wall -Wextra -Wpedantic -Werror src/program.c

# Additional warnings for security
gcc -Wall -Wextra -Wformat=2 -Wstrict-overflow=4 -Wundef \
    -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings \
    -Waggregate-return -Wcast-qual -Wswitch-default \
    -Wswitch-enum -Wunreachable-code src/program.c
```

### Build Configuration
```makefile
# Makefile example
CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Wpedantic -O2
DEBUG_CFLAGS=-g -DDEBUG -fsanitize=address

SRCDIR=src
SOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(SOURCES:.c=.o)

.PHONY: all clean debug

all: program

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: program

program: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) program
```

## 📋 Code Review Checklist

### Before Submitting Code
- [ ] Code compiles without warnings
- [ ] All functions have proper documentation
- [ ] Error handling is implemented
- [ ] Memory leaks are checked (valgrind/static analysis)
- [ ] Code follows naming conventions
- [ ] No hardcoded magic numbers
- [ ] Appropriate const usage
- [ ] Thread safety considered (if applicable)

### During Code Review
- [ ] Logic is correct and efficient
- [ ] Edge cases are handled
- [ ] Code is readable and maintainable
- [ ] Security vulnerabilities checked
- [ ] Performance implications considered
- [ ] Documentation is accurate and complete

## 🎯 Summary

Following these coding standards will help you:
- Write more maintainable code
- Reduce bugs and security vulnerabilities
- Improve code readability
- Collaborate more effectively with others
- Build professional-quality software

Remember: **Consistency is key**. Pick a style and stick with it throughout your project.

## 📖 References

- **ISO C Standard**: ISO/IEC 9899:2018
- **ISO C++ Standard**: ISO/IEC 14882:2020
- **MISRA C**: Guidelines for critical systems
- **Google Style Guide**: [google.github.io/styleguide/](https://google.github.io/styleguide/)
- **Linux Kernel Coding Style**: [kernel.org/doc/html/latest/process/coding-style.html](https://www.kernel.org/doc/html/latest/process/coding-style.html)
