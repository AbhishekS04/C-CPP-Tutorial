# Variables and Data Types in C

Welcome to the Variables and Data Types section! This is where you'll learn how to store, manipulate, and work with different types of data in C programming.

## 🎯 Learning Objectives

After completing this section, you will:
- Understand what variables are and how to declare them
- Know all fundamental data types in C
- Learn about type modifiers and qualifiers
- Understand variable initialization and assignment
- Master type conversion and casting
- Work with constants and literals
- Understand variable scope and storage classes

## 📚 What Are Variables?

Variables are named memory locations that store data. Think of them as labeled containers that hold different types of information.

```c
int age = 25;        // Variable 'age' stores an integer
char grade = 'A';    // Variable 'grade' stores a character
float price = 19.99; // Variable 'price' stores a decimal number
```

### Variable Declaration Syntax
```c
data_type variable_name;           // Declaration
data_type variable_name = value;   // Declaration with initialization
```

## 🔢 Fundamental Data Types

### Integer Types

#### `int` - Basic Integer
```c
int count = 42;
int temperature = -5;
int year = 2024;

printf("Count: %d\n", count);
printf("Temperature: %d°C\n", temperature);
printf("Year: %d\n", year);
```

**Properties:**
- **Size**: Usually 4 bytes (32 bits)
- **Range**: -2,147,483,648 to 2,147,483,647
- **Format specifier**: `%d` or `%i`

#### `short` - Short Integer
```c
short small_number = 1000;
printf("Small number: %hd\n", small_number);
```

**Properties:**
- **Size**: Usually 2 bytes (16 bits)
- **Range**: -32,768 to 32,767
- **Format specifier**: `%hd`

#### `long` - Long Integer
```c
long big_number = 1000000L;
printf("Big number: %ld\n", big_number);
```

**Properties:**
- **Size**: Usually 8 bytes (64 bits) on modern systems
- **Range**: Much larger than int
- **Format specifier**: `%ld`
- **Suffix**: `L` or `l`

#### `long long` - Extended Integer
```c
long long very_big_number = 9223372036854775807LL;
printf("Very big number: %lld\n", very_big_number);
```

**Properties:**
- **Size**: At least 8 bytes
- **Range**: At least 64 bits
- **Format specifier**: `%lld`
- **Suffix**: `LL` or `ll`

### Character Type

#### `char` - Single Character
```c
char letter = 'A';
char digit = '7';
char symbol = '@';

printf("Letter: %c\n", letter);
printf("ASCII value: %d\n", letter);  // Print as integer
```

**Properties:**
- **Size**: 1 byte (8 bits)
- **Range**: -128 to 127 (signed) or 0 to 255 (unsigned)
- **Format specifier**: `%c` (character), `%d` (ASCII value)
- **Literals**: Single quotes `'A'`

### Floating-Point Types

#### `float` - Single Precision
```c
float price = 19.99f;
float pi = 3.14159f;

printf("Price: $%.2f\n", price);  // 2 decimal places
printf("Pi: %.5f\n", pi);         // 5 decimal places
```

**Properties:**
- **Size**: 4 bytes
- **Precision**: ~7 decimal digits
- **Range**: ~1.2E-38 to 3.4E+38
- **Format specifier**: `%f`, `%e`, `%g`
- **Suffix**: `f` or `F`

#### `double` - Double Precision
```c
double precise_pi = 3.141592653589793;
double large_number = 1.23e10;  // Scientific notation

printf("Precise Pi: %.15lf\n", precise_pi);
printf("Large number: %.2e\n", large_number);
```

**Properties:**
- **Size**: 8 bytes
- **Precision**: ~15 decimal digits
- **Range**: ~2.3E-308 to 1.7E+308
- **Format specifier**: `%lf`, `%le`, `%lg`

#### `long double` - Extended Precision
```c
long double extra_precise = 3.14159265358979323846L;
printf("Extra precise: %.20Lf\n", extra_precise);
```

**Properties:**
- **Size**: Usually 16 bytes (varies by system)
- **Precision**: System dependent
- **Format specifier**: `%Lf`, `%Le`, `%Lg`
- **Suffix**: `L`

## 🔄 Type Modifiers

### Signed and Unsigned

#### `unsigned` - Non-negative values only
```c
unsigned int positive_count = 4294967295U;
unsigned char byte_value = 255;

printf("Positive count: %u\n", positive_count);
printf("Byte value: %u\n", byte_value);
```

**Key Points:**
- Doubles the positive range
- No negative values allowed
- Use `%u` format specifier

#### `signed` - Both positive and negative (default)
```c
signed int normal_int = -1000;
printf("Normal int: %d\n", normal_int);
```

### Size Comparison Example
```c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("Data Type Sizes and Ranges:\n");
    printf("===========================\n");
    
    printf("char: %zu bytes, range: %d to %d\n", 
           sizeof(char), CHAR_MIN, CHAR_MAX);
    
    printf("short: %zu bytes, range: %d to %d\n", 
           sizeof(short), SHRT_MIN, SHRT_MAX);
    
    printf("int: %zu bytes, range: %d to %d\n", 
           sizeof(int), INT_MIN, INT_MAX);
    
    printf("long: %zu bytes, range: %ld to %ld\n", 
           sizeof(long), LONG_MIN, LONG_MAX);
    
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    
    return 0;
}
```

## 💡 Variable Declaration and Initialization

### Declaration Without Initialization
```c
int count;           // Declared but not initialized
float price;         // Contains garbage value
char grade;          // Unpredictable content

// Always initialize before use!
count = 0;
price = 0.0;
grade = 'F';
```

### Declaration With Initialization
```c
int students = 30;           // Declare and initialize
float average = 85.5;        // Better practice
char letter = 'A';           // Safe and clear
```

### Multiple Variable Declaration
```c
// Same type, separate declarations
int x = 10;
int y = 20;
int z = 30;

// Same type, single declaration
int a = 1, b = 2, c = 3;

// Mixed initialization
int initialized = 100, uninitialized, another = 200;
```

## 🔒 Constants and Literals

### Literal Constants
```c
42          // Integer literal
42L         // Long literal
42LL        // Long long literal
42U         // Unsigned literal
42UL        // Unsigned long literal

3.14f       // Float literal
3.14        // Double literal
3.14L       // Long double literal

'A'         // Character literal
"Hello"     // String literal (array of characters)
```

### Named Constants with `const`
```c
const int MAX_STUDENTS = 50;
const float PI = 3.14159f;
const char GRADE_A = 'A';

// MAX_STUDENTS = 60;  // Error! Cannot modify const
```

### Preprocessor Constants with `#define`
```c
#define MAX_SIZE 100
#define PI 3.14159
#define NEWLINE '\n'

int array[MAX_SIZE];  // Uses preprocessor constant
float circumference = 2 * PI * radius;
```

### Comparison: `const` vs `#define`
```c
// const - type-safe, scoped
const int SIZE = 10;        // Has type 'int'
int array[SIZE];            // Valid in C99+

// #define - text replacement, no type
#define SIZE 10             // Text substitution
int array[SIZE];            // Always valid
```

## 🔄 Type Conversion and Casting

### Implicit Conversion (Automatic)
```c
int i = 10;
float f = i;        // int to float (safe)
printf("f = %.1f\n", f);  // Output: f = 10.0

float x = 3.7;
int j = x;          // float to int (loses decimal part)
printf("j = %d\n", j);    // Output: j = 3
```

### Explicit Conversion (Casting)
```c
float result = (float) 5 / 2;    // Result: 2.5
int truncated = (int) 3.99;      // Result: 3

printf("Result: %.1f\n", result);
printf("Truncated: %d\n", truncated);
```

### Type Promotion in Expressions
```c
int a = 10;
float b = 3.5;
float result = a + b;  // 'a' promoted to float
printf("Result: %.1f\n", result);  // Output: 13.5
```

### Common Pitfalls
```c
// Integer division
int x = 5, y = 2;
float result1 = x / y;           // Result: 2.0 (not 2.5!)
float result2 = (float) x / y;   // Result: 2.5 (correct)

// Overflow
unsigned char max = 255;
max = max + 1;                   // Result: 0 (wraps around)

// Precision loss
float precise = 1.23456789;
printf("%.10f\n", precise);      // May not show all digits
```

## 🎨 Format Specifiers Reference

| Type | Format | Example | Output |
|------|--------|---------|---------|
| `int` | `%d`, `%i` | `printf("%d", 42)` | `42` |
| `unsigned int` | `%u` | `printf("%u", 42U)` | `42` |
| `short` | `%hd` | `printf("%hd", 42)` | `42` |
| `long` | `%ld` | `printf("%ld", 42L)` | `42` |
| `long long` | `%lld` | `printf("%lld", 42LL)` | `42` |
| `float` | `%f` | `printf("%.2f", 3.14f)` | `3.14` |
| `double` | `%lf` | `printf("%.2lf", 3.14)` | `3.14` |
| `long double` | `%Lf` | `printf("%.2Lf", 3.14L)` | `3.14` |
| `char` | `%c` | `printf("%c", 'A')` | `A` |
| `char*` | `%s` | `printf("%s", "Hello")` | `Hello` |
| Hexadecimal | `%x`, `%X` | `printf("%x", 255)` | `ff` |
| Octal | `%o` | `printf("%o", 64)` | `100` |

### Advanced Formatting
```c
int number = 42;
float value = 3.14159;

// Width and alignment
printf("%5d\n", number);      // Right-aligned in 5 spaces: "   42"
printf("%-5d\n", number);     // Left-aligned in 5 spaces: "42   "
printf("%05d\n", number);     // Zero-padded: "00042"

// Precision with floats
printf("%.2f\n", value);      // 2 decimal places: "3.14"
printf("%8.2f\n", value);     // 8 total width, 2 decimal: "    3.14"
printf("%-8.2f\n", value);    // Left-aligned: "3.14    "
```

## 🏗️ Complete Example Program

```c
/**
 * @file variables_demo.c
 * @brief Comprehensive demonstration of C variables and data types
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

// Named constants
#define MAX_NAME_LENGTH 50
const int CURRENT_YEAR = 2024;

int main() {
    // Integer types demonstration
    printf("=== INTEGER TYPES ===\n");
    
    char small_num = 127;
    short medium_num = 32000;
    int regular_num = 1000000;
    long big_num = 1000000000L;
    long long huge_num = 9223372036854775807LL;
    
    printf("char: %d (size: %zu bytes)\n", small_num, sizeof(small_num));
    printf("short: %hd (size: %zu bytes)\n", medium_num, sizeof(medium_num));
    printf("int: %d (size: %zu bytes)\n", regular_num, sizeof(regular_num));
    printf("long: %ld (size: %zu bytes)\n", big_num, sizeof(big_num));
    printf("long long: %lld (size: %zu bytes)\n", huge_num, sizeof(huge_num));
    
    // Unsigned vs signed
    printf("\n=== UNSIGNED vs SIGNED ===\n");
    unsigned int positive_only = 4000000000U;
    int can_be_negative = -1000000;
    
    printf("unsigned int: %u\n", positive_only);
    printf("signed int: %d\n", can_be_negative);
    
    // Floating-point types
    printf("\n=== FLOATING-POINT TYPES ===\n");
    float single_precision = 3.14159f;
    double double_precision = 3.14159265358979323846;
    long double extended_precision = 3.14159265358979323846L;
    
    printf("float: %.7f (size: %zu bytes)\n", single_precision, sizeof(single_precision));
    printf("double: %.15lf (size: %zu bytes)\n", double_precision, sizeof(double_precision));
    printf("long double: %.19Lf (size: %zu bytes)\n", extended_precision, sizeof(extended_precision));
    
    // Character type
    printf("\n=== CHARACTER TYPE ===\n");
    char letter = 'A';
    char digit = '5';
    char symbol = '@';
    
    printf("Character: %c (ASCII: %d)\n", letter, letter);
    printf("Digit: %c (ASCII: %d)\n", digit, digit);
    printf("Symbol: %c (ASCII: %d)\n", symbol, symbol);
    
    // Type conversions
    printf("\n=== TYPE CONVERSIONS ===\n");
    int int_val = 10;
    float float_val = 3.7f;
    
    // Implicit conversion
    float result1 = int_val + float_val;
    printf("int + float: %.1f\n", result1);
    
    // Explicit casting
    int result2 = (int) float_val;
    printf("(int) %.1f = %d\n", float_val, result2);
    
    // Integer division vs float division
    printf("5 / 2 = %d\n", 5 / 2);                    // Integer division
    printf("5.0 / 2.0 = %.1f\n", 5.0 / 2.0);         // Float division
    printf("(float) 5 / 2 = %.1f\n", (float) 5 / 2); // Cast to float
    
    // Constants demonstration
    printf("\n=== CONSTANTS ===\n");
    printf("MAX_NAME_LENGTH: %d\n", MAX_NAME_LENGTH);
    printf("CURRENT_YEAR: %d\n", CURRENT_YEAR);
    
    // Variable scope demonstration
    printf("\n=== VARIABLE SCOPE ===\n");
    int outer_var = 100;
    printf("Outer variable: %d\n", outer_var);
    
    {
        int inner_var = 200;
        printf("Inner variable: %d\n", inner_var);
        printf("Outer variable accessible: %d\n", outer_var);
    }
    // printf("Inner variable: %d\n", inner_var);  // Error! Out of scope
    
    // Format specifier examples
    printf("\n=== FORMAT SPECIFIERS ===\n");
    int hex_num = 255;
    printf("Decimal: %d, Hexadecimal: %x, Octal: %o\n", hex_num, hex_num, hex_num);
    printf("With width: %5d, Zero-padded: %05d\n", 42, 42);
    printf("Float precision: %.2f, Scientific: %.2e\n", 123.456, 123.456);
    
    return 0;
}
```

## 🧪 Practice Exercises

### Exercise 1: Variable Declarations
Declare variables for a student record:
- Name (you'll learn strings later, use char for first initial)
- Age
- GPA (with decimal places)
- Grade letter
- Student ID number

### Exercise 2: Type Conversion Practice
Write a program that:
1. Takes two integers as input
2. Performs both integer and floating-point division
3. Shows the difference in results

### Exercise 3: Size and Range Investigation
Create a program that displays the size and range of all fundamental data types using `sizeof` and constants from `<limits.h>`.

## 🎯 Key Takeaways

1. **Always initialize variables** before using them
2. **Choose appropriate data types** for your data
3. **Understand implicit vs explicit conversion**
4. **Be aware of precision and overflow issues**
5. **Use meaningful variable names**
6. **Prefer `const` over `#define` for type safety**

## 🔗 What's Next?

After mastering variables and data types, you'll learn about:
- **[Operators](../03-operators/)** - Manipulating data with arithmetic, logical, and other operators
- **Input/Output** - Reading user input and formatting output
- **Expressions and Statements** - Combining variables and operators

Understanding data types is fundamental to C programming. Take your time with this section, as everything else builds upon these concepts! 🚀
