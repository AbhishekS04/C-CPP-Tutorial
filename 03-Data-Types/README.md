# 📊 Chapter 3: Data Types - Understanding Different Kinds of Data

## 🎯 What You'll Learn
- All the different types of data in C
- When to use each data type
- Memory usage and ranges for each type
- How to choose the right data type
- Common mistakes and how to avoid them

## 📝 The Story
Just like you have different containers for different things (water bottles for liquids, boxes for solids), C has different data types for different kinds of information!

---

## 💡 What are Data Types?

**Data types** tell the computer:
- 📏 How much memory to allocate
- 🎯 What kind of operations are allowed
- 🔄 How to interpret the stored bits

Think of data types as **templates** for your variables!

---

## 🏗️ Complete Overview

### 🔢 Integer Types (Whole Numbers)

| Type | Size | Range | Usage |
|------|------|-------|-------|
| `char` | 1 byte | -128 to 127 | Small numbers, ASCII characters |
| `short` | 2 bytes | -32,768 to 32,767 | Small integers |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 | Most common integer type |
| `long` | 8 bytes | Very large negative to positive | Large integers |

### 🎯 Floating Point Types (Decimal Numbers)

| Type | Size | Precision | Usage |
|------|------|----------|-------|
| `float` | 4 bytes | 6-7 decimal places | Basic decimal numbers |
| `double` | 8 bytes | 15-16 decimal places | High precision decimals |
| `long double` | 16 bytes | 18-19 decimal places | Extremely precise decimals |

---

## 🧪 Complete Example Program

```c
#include <stdio.h>

int main() {
    printf("=== C DATA TYPES DEMONSTRATION ===\n\n");
    
    // INTEGER TYPES
    printf("📊 INTEGER TYPES:\n");
    char smallNum = 100;
    short mediumNum = 30000;
    int normalNum = 2000000;
    long bigNum = 5000000000L;  // L suffix for long
    
    printf("char: %d (size: %zu bytes)\n", smallNum, sizeof(smallNum));
    printf("short: %d (size: %zu bytes)\n", mediumNum, sizeof(mediumNum));
    printf("int: %d (size: %zu bytes)\n", normalNum, sizeof(normalNum));
    printf("long: %ld (size: %zu bytes)\n", bigNum, sizeof(bigNum));
    
    // FLOATING POINT TYPES  
    printf("\n🎯 FLOATING POINT TYPES:\n");
    float price = 19.99f;        // f suffix for float
    double pi = 3.14159265359;
    long double precisePi = 3.141592653589793238L;
    
    printf("float: %.2f (size: %zu bytes)\n", price, sizeof(price));
    printf("double: %.10f (size: %zu bytes)\n", pi, sizeof(pi));
    printf("long double: %.15Lf (size: %zu bytes)\n", precisePi, sizeof(precisePi));
    
    // CHARACTER TYPE
    printf("\n🔤 CHARACTER TYPE:\n");
    char letter = 'A';
    char digit = '5';
    char symbol = '@';
    
    printf("letter: %c (ASCII: %d)\n", letter, letter);
    printf("digit: %c (ASCII: %d)\n", digit, digit);
    printf("symbol: %c (ASCII: %d)\n", symbol, symbol);
    
    // UNSIGNED TYPES (Only positive numbers)
    printf("\n✨ UNSIGNED TYPES:\n");
    unsigned int positiveOnly = 4000000000U;
    unsigned char smallPositive = 250;
    
    printf("unsigned int: %u\n", positiveOnly);
    printf("unsigned char: %u\n", smallPositive);
    
    return 0;
}
```

---

## 🎮 When to Use Each Type

### 🔢 Integer Types

#### `char` - Small Numbers & Characters
```c
char age = 25;          // Age (0-127 is plenty)
char grade = 'A';       // Single character
char temperature = -10;  // Small temperature range
```
**Use when:** Small whole numbers, single characters, or saving memory

#### `int` - Your Go-To Integer
```c
int students = 500;     // Number of students
int year = 2024;        // Years
int score = 95;         // Test scores
```
**Use when:** Most integer calculations (this is your default choice!)

#### `long` - Big Numbers
```c
long population = 7800000000L;  // World population
long distance = 150000000L;     // Distance in kilometers
```
**Use when:** Numbers larger than 2 billion

### 🎯 Floating Point Types

#### `float` - Basic Decimals
```c
float height = 5.8f;    // Height in feet
float price = 19.99f;   // Prices
float gpa = 3.75f;      // GPA
```
**Use when:** Basic decimal calculations, saving memory

#### `double` - High Precision
```c
double pi = 3.14159265359;      // Mathematical constants
double bankBalance = 1234.56;   // Money (be careful with floating point for money!)
double scientificData = 0.0000123456789;
```
**Use when:** Scientific calculations, high precision needed

---

## 🔍 Understanding Memory and Ranges

### Visual Memory Layout
```
char:    [8 bits ] = 1 byte  = -128 to 127
short:   [16 bits] = 2 bytes = -32,768 to 32,767
int:     [32 bits] = 4 bytes = -2.1 billion to 2.1 billion
long:    [64 bits] = 8 bytes = Very large numbers
float:   [32 bits] = 4 bytes = ±3.4E-38 to ±3.4E+38
double:  [64 bits] = 8 bytes = ±1.7E-308 to ±1.7E+308
```

### Range Testing Program
```c
#include <stdio.h>
#include <limits.h>  // For integer limits
#include <float.h>   // For floating point limits

int main() {
    printf("=== DATA TYPE RANGES ===\n");
    
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("float: %E to %E\n", FLT_MIN, FLT_MAX);
    
    return 0;
}
```

---

## ⚠️ Signed vs Unsigned Types

### Signed (Default) - Can be positive or negative
```c
int temperature = -20;      // Can be negative
char balance = -50;         // Can be negative
```

### Unsigned - Only positive numbers (but bigger range!)
```c
unsigned int population = 4000000000U;  // Only positive, but bigger range
unsigned char age = 200;                // 0 to 255 instead of -128 to 127
```

### Comparison Example
```c
#include <stdio.h>

int main() {
    // Signed types
    char signedChar = -100;
    int signedInt = -1000000;
    
    // Unsigned types  
    unsigned char unsignedChar = 200;
    unsigned int unsignedInt = 4000000000U;
    
    printf("Signed char: %d (can be negative)\n", signedChar);
    printf("Unsigned char: %u (only positive, but goes to 255)\n", unsignedChar);
    
    printf("Signed int: %d (can be negative)\n", signedInt);
    printf("Unsigned int: %u (only positive, but bigger range)\n", unsignedInt);
    
    return 0;
}
```

---

## 🎯 Format Specifiers Guide

| Data Type | Format Specifier | Example |
|-----------|------------------|---------|
| `char` | `%c` (character) or `%d` (number) | `printf("%c", 'A')` |
| `int` | `%d` | `printf("%d", 123)` |
| `long` | `%ld` | `printf("%ld", 123L)` |
| `float` | `%f` or `%.2f` | `printf("%.2f", 3.14f)` |
| `double` | `%f` or `%.2f` | `printf("%.2f", 3.14)` |
| `unsigned int` | `%u` | `printf("%u", 123U)` |

### Precision Control for Floats
```c
float number = 3.14159f;

printf("%.1f", number);  // Output: 3.1
printf("%.2f", number);  // Output: 3.14
printf("%.3f", number);  // Output: 3.142
printf("%.0f", number);  // Output: 3
```

---

## 🚫 Common Mistakes and Solutions

### ❌ Wrong Format Specifier
```c
float height = 5.8f;
printf("Height: %d", height);  // WRONG! Prints garbage
```
**✅ Fix:**
```c
float height = 5.8f;
printf("Height: %.1f", height);  // Correct!
```

### ❌ Integer Overflow
```c
char number = 200;  // WRONG! char only goes to 127
printf("%d", number);  // Prints negative number!
```
**✅ Fix:**
```c
unsigned char number = 200;  // Use unsigned for 0-255 range
printf("%u", number);        // Prints: 200
```

### ❌ Precision Loss
```c
float result = 1.0f / 3.0f;
printf("%.10f", result);  // Shows: 0.3333333433 (not exact!)
```
**✅ Fix:**
```c
double result = 1.0 / 3.0;     // Use double for more precision
printf("%.10f", result);       // Shows: 0.3333333333 (more accurate)
```

### ❌ Forgetting Type Suffixes
```c
float pi = 3.14159265359;  // Actually stored as double, then converted
long big = 5000000000;     // Might cause warning
```
**✅ Fix:**
```c
float pi = 3.14159f;       // f suffix for float
long big = 5000000000L;    // L suffix for long
```

---

## 🧮 Type Conversion (Casting)

### Automatic Conversion
```c
int whole = 5;
float decimal = 2.0f;
float result = whole + decimal;  // int is automatically converted to float
printf("%.1f", result);         // Output: 7.0
```

### Manual Conversion (Casting)
```c
float decimal = 3.8f;
int whole = (int)decimal;        // Force conversion to int
printf("%d", whole);             // Output: 3 (decimal part lost!)

int a = 7, b = 2;
float result = (float)a / b;     // Cast to get decimal result
printf("%.2f", result);          // Output: 3.50
```

---

## 🎯 Real-World Examples

### Student Grade System
```c
#include <stdio.h>

int main() {
    // Different data types for different purposes
    unsigned int studentID = 123456;        // ID numbers are always positive
    char letterGrade = 'B';                 // Single character
    float gpa = 3.25f;                      // Decimal precision needed
    unsigned short creditsCompleted = 85;    // Credits are positive, relatively small
    double tuitionBalance = 12750.50;       // Money needs precision
    
    printf("Student ID: %u\n", studentID);
    printf("Letter Grade: %c\n", letterGrade);
    printf("GPA: %.2f\n", gpa);
    printf("Credits: %u\n", creditsCompleted);
    printf("Balance: $%.2f\n", tuitionBalance);
    
    return 0;
}
```

### Scientific Calculator
```c
#include <stdio.h>

int main() {
    // Different precisions for different calculations
    float basicCalc = 10.5f / 3.2f;         // Basic math
    double scientificCalc = 299792458.0 * 3600.0;  // Speed of light calculations
    long double preciseCalc = 3.141592653589793238L / 2.0L;  // Ultra-precise
    
    printf("Basic: %.2f\n", basicCalc);
    printf("Scientific: %.2f\n", scientificCalc);
    printf("Precise: %.15Lf\n", preciseCalc);
    
    return 0;
}
```

---

## 📚 Choosing the Right Data Type

### Decision Tree 🌳

**Need to store a number?**
- 📍 **Whole number?**
  - Small (-128 to 127)? → `char`
  - Normal range? → `int`
  - Very large? → `long`
  - Only positive? → Add `unsigned`

- 🎯 **Decimal number?**
  - Basic precision? → `float`
  - High precision? → `double`
  - Ultra precision? → `long double`

**Need to store a character?**
- Single letter/symbol? → `char`

---

## 🎉 Practice Exercises

### Exercise 1: Variable Types
Choose the best data type for:
- A person's age
- The population of a country
- A student's GPA
- A single letter grade
- The price of a house

### Exercise 2: Memory Efficiency
Rewrite this code to use the most memory-efficient types:
```c
int age = 20;
int grade = 'A';
double gpa = 3.5;
int temperature = -10;
```

### Exercise 3: Range Testing
Write a program that tests what happens when you exceed the range of different data types.

---

## 🚀 Challenge: Data Type Showcase

Create a program that demonstrates all major data types with real-world examples. Include:
- Personal information (age, initial, height)
- Academic information (GPA, credits, grade)
- Financial information (balance, tuition)
- Scientific data (pi, speed of light)

Show the memory usage of each variable using `sizeof()`.

<details>
<summary>🎁 Click to see solution</summary>

```c
#include <stdio.h>

int main() {
    printf("=== DATA TYPE SHOWCASE ===\n\n");
    
    // Personal Information
    unsigned char age = 19;              // Ages are positive and small
    char initial = 'J';                  // Single character
    float height = 5.75f;                // Height with decimal
    
    // Academic Information
    double gpa = 3.87654321;             // High precision for GPA
    unsigned short credits = 90;         // Credits are positive, medium range
    char letterGrade = 'A';             // Single character
    
    // Financial Information
    double bankBalance = 2547.89;        // Money needs precision
    unsigned int tuition = 25000;       // Large positive number
    
    // Scientific Data
    double pi = 3.14159265359;           // Mathematical constant
    long lightSpeed = 299792458L;       // Large scientific number
    
    printf("👤 PERSONAL INFO:\n");
    printf("Age: %u years (size: %zu bytes)\n", age, sizeof(age));
    printf("Initial: %c (size: %zu bytes)\n", initial, sizeof(initial));
    printf("Height: %.2f ft (size: %zu bytes)\n", height, sizeof(height));
    
    printf("\n🎓 ACADEMIC INFO:\n");
    printf("GPA: %.8f (size: %zu bytes)\n", gpa, sizeof(gpa));
    printf("Credits: %u (size: %zu bytes)\n", credits, sizeof(credits));
    printf("Grade: %c (size: %zu bytes)\n", letterGrade, sizeof(letterGrade));
    
    printf("\n💰 FINANCIAL INFO:\n");
    printf("Balance: $%.2f (size: %zu bytes)\n", bankBalance, sizeof(bankBalance));
    printf("Tuition: $%u (size: %zu bytes)\n", tuition, sizeof(tuition));
    
    printf("\n🔬 SCIENTIFIC DATA:\n");
    printf("Pi: %.11f (size: %zu bytes)\n", pi, sizeof(pi));
    printf("Speed of Light: %ld m/s (size: %zu bytes)\n", lightSpeed, sizeof(lightSpeed));
    
    printf("\nTotal memory used: %zu bytes\n", 
           sizeof(age) + sizeof(initial) + sizeof(height) + 
           sizeof(gpa) + sizeof(credits) + sizeof(letterGrade) +
           sizeof(bankBalance) + sizeof(tuition) + 
           sizeof(pi) + sizeof(lightSpeed));
    
    return 0;
}
```

</details>

---

## 📚 Key Takeaways

✅ **int** is your default choice for whole numbers  
✅ **float** is good for basic decimal numbers  
✅ **double** when you need high precision  
✅ **char** for single characters and small numbers  
✅ **unsigned** types for positive-only numbers with larger ranges  
✅ Always match format specifiers with data types  
✅ Consider memory usage when choosing types  
✅ Use type suffixes: `f` for float, `L` for long  

---

## 🚀 What's Next?

Great job! You now understand all the different types of data in C! 🎉

**Next Chapter:** [Input/Output - Talking to Users →](../04-Input-Output/)

In the next chapter, you'll learn how to get input from users and display output in different ways.

---

## 📞 Need Help?

- **Confused about which type to use?** Start with `int` for whole numbers and `float` for decimals
- **Getting weird output?** Check your format specifiers (`%d`, `%f`, `%c`)
- **Numbers not storing correctly?** Check if you're exceeding the range of your data type
- **Precision problems?** Consider using `double` instead of `float`

**Remember:** Choose the right tool for the job - different data types for different kinds of data! 🔧
