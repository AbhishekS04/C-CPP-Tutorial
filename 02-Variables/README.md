# 🧰 Chapter 2: Variables - Storing Information

## 🎯 What You'll Learn
- What variables are and why they're useful
- How to create and use variables
- Different types of variables
- Rules for naming variables
- How to change variable values

## 📝 The Story
Imagine you have boxes to store things. Each box has a label (name) and can hold one item. Variables are like these boxes - they store information in your computer's memory!

---

## 💡 What is a Variable?

A **variable** is a named storage location that holds data. Think of it as:
- 📦 A box with a label
- 🏷️ The label is the variable name
- 📝 The contents are the data/value

### Real-World Example
```
Box labeled "age" contains: 20
Box labeled "name" contains: "John"
Box labeled "height" contains: 5.8
```

---

## 🎯 Basic Variable Syntax

```c
data_type variable_name = value;
```

**Example:**
```c
int age = 20;           // Create a box called "age" with value 20
```

Let's break this down:
- `int` = Type of data (whole number)
- `age` = Name of our variable
- `=` = Assignment operator ("put this value in the box")
- `20` = The value we're storing
- `;` = End of statement

---

## 🏗️ Complete Example Program

```c
#include <stdio.h>

int main() {
    // Create variables
    int age = 20;
    int score = 95;
    
    // Use variables
    printf("My age is %d years\n", age);
    printf("My score is %d points\n", score);
    
    // Change variable values
    age = 21;
    score = 100;
    
    printf("Next year, my age will be %d\n", age);
    printf("My new score is %d\n", score);
    
    return 0;
}
```

**Output:**
```
My age is 20 years
My score is 95 points
Next year, my age will be 21
My new score is 100
```

### 🔍 New Things Explained

**`%d` in printf:**
- `%d` means "put an integer here"
- The variable after the comma goes where `%d` is
- `printf("Age is %d", age)` becomes `printf("Age is 20")`

---

## 📊 Types of Variables

### 1. 🔢 Integer (`int`) - Whole Numbers
```c
int age = 25;
int students = 30;
int temperature = -5;   // Can be negative too!

printf("Age: %d\n", age);
printf("Students: %d\n", students);
printf("Temperature: %d°C\n", temperature);
```

### 2. 🎯 Floating Point (`float`) - Decimal Numbers
```c
float height = 5.8;
float price = 19.99;
float weight = 70.5;

printf("Height: %.1f meters\n", height);    // %.1f shows 1 decimal place
printf("Price: $%.2f\n", price);            // %.2f shows 2 decimal places
printf("Weight: %.1f kg\n", weight);
```

### 3. 🔤 Character (`char`) - Single Letters
```c
char grade = 'A';
char initial = 'J';
char symbol = '@';

printf("Grade: %c\n", grade);
printf("Initial: %c\n", initial);
printf("Symbol: %c\n", symbol);
```

**Note:** Characters use single quotes `'A'`, not double quotes!

---

## 🎮 Interactive Example

```c
#include <stdio.h>

int main() {
    // Student information
    char grade = 'A';
    int age = 19;
    float gpa = 3.85;
    
    printf("=== STUDENT REPORT ===\n");
    printf("Age: %d years old\n", age);
    printf("Grade: %c\n", grade);
    printf("GPA: %.2f\n", gpa);
    
    // Update information
    printf("\nAfter improvement:\n");
    grade = 'A';  // Grade stays the same
    age = 20;     // Birthday!
    gpa = 3.90;   // Improved GPA
    
    printf("Age: %d years old\n", age);
    printf("Grade: %c\n", grade);
    printf("GPA: %.2f\n", gpa);
    
    return 0;
}
```

---

## 📝 Variable Naming Rules

### ✅ Valid Names (Good!)
```c
int age;           // Simple and clear
int student_count; // Words separated by underscore
int maxScore;      // CamelCase (first letter lowercase)
int num1;          // Can end with numbers
```

### ❌ Invalid Names (Won't Work!)
```c
int 123age;        // Can't start with number
int my-age;        // Can't use hyphens
int class;         // Can't use C keywords
int my age;        // Can't have spaces
```

### 💡 Best Practices for Naming
```c
// ✅ Good names (describe what they store)
int studentAge;
float bankBalance;
char letterGrade;

// ❌ Poor names (unclear meaning)
int x;
float num;
char c;
```

---

## 🔧 Working with Variables

### Creating Variables
```c
// Method 1: Declare and assign together
int score = 100;

// Method 2: Declare first, assign later
int age;        // Create the box
age = 20;       // Put value in the box

// Method 3: Multiple variables of same type
int a = 5, b = 10, c = 15;
```

### Changing Variable Values
```c
int count = 0;      // Start with 0
printf("Count: %d\n", count);

count = 5;          // Change to 5
printf("Count: %d\n", count);

count = 10;         // Change to 10
printf("Count: %d\n", count);
```

### Using Variables in Calculations
```c
int a = 10;
int b = 5;
int sum = a + b;    // sum becomes 15

printf("%d + %d = %d\n", a, b, sum);
// Output: 10 + 5 = 15
```

---

## 🎯 Practice Exercises

### Exercise 1: Personal Information
Create a program that stores and displays:
- Your name's first initial (char)
- Your age (int) 
- Your height in feet (float)

### Exercise 2: Simple Calculator
Create variables for two numbers and calculate:
- Their sum
- Their difference
- Their product

### Exercise 3: Temperature Converter
Store a temperature in Celsius and convert it to Fahrenheit.
Formula: `fahrenheit = (celsius × 9/5) + 32`

---

## 🚫 Common Mistakes and Solutions

### ❌ Forgetting to initialize
```c
int age;                    // Created but empty!
printf("Age: %d\n", age);   // Prints random garbage!
```
**✅ Fix:**
```c
int age = 0;                // Always initialize!
printf("Age: %d\n", age);   // Prints: Age: 0
```

### ❌ Using wrong format specifier
```c
float height = 5.8;
printf("Height: %d\n", height);  // WRONG! %d is for integers
```
**✅ Fix:**
```c
float height = 5.8;
printf("Height: %.1f\n", height);  // Correct! %f is for floats
```

### ❌ Forgetting semicolons
```c
int age = 20        // Missing semicolon!
printf("Age: %d\n", age);
```
**✅ Fix:**
```c
int age = 20;       // Don't forget the semicolon!
printf("Age: %d\n", age);
```

---

## 🧠 Memory Visualization

When you create variables, here's what happens in memory:

```
Memory Address: |  Variable  |  Value  |
1000:          |    age     |   20    |
1004:          |   score    |   95    |
1008:          |   height   |  5.8    |
1009:          |   grade    |  'A'    |
```

Each variable gets its own address in memory!

---

## 📚 Key Takeaways

✅ Variables are named storage locations for data  
✅ Always initialize variables when you create them  
✅ Use descriptive names for your variables  
✅ Match the correct format specifier with variable type:
  - `%d` for `int`
  - `%f` for `float` (use `%.2f` for 2 decimal places)
  - `%c` for `char`  
✅ Variable values can be changed during program execution  
✅ Follow naming rules: start with letter/underscore, no spaces, no keywords  

---

## 🎉 Challenge: Personal Profile

Write a program that creates variables for:
- Your age (int)
- Your initial (char)
- Your GPA (float)
- Your favorite number (int)

Then print a nice profile like:
```
=== MY PROFILE ===
Initial: J
Age: 19 years old
GPA: 3.75
Lucky number: 7
```

<details>
<summary>🎁 Click to see solution</summary>

```c
#include <stdio.h>

int main() {
    // My information
    char initial = 'J';
    int age = 19;
    float gpa = 3.75;
    int luckyNumber = 7;
    
    // Display profile
    printf("=== MY PROFILE ===\n");
    printf("Initial: %c\n", initial);
    printf("Age: %d years old\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Lucky number: %d\n", luckyNumber);
    
    return 0;
}
```

</details>

---

## 🚀 What's Next?

Excellent work! You now know how to store information in variables! 🎉

**Next Chapter:** [Data Types - Understanding Different Kinds of Data →](../03-Data-Types/)

In the next chapter, you'll learn about all the different types of data you can store and when to use each one.

---

## 📞 Need Help?

- **Variable not storing value?** Check if you initialized it
- **Weird output?** Make sure you're using the right format specifier (`%d`, `%f`, `%c`)
- **Compilation error?** Check for missing semicolons and proper variable names
- **Still confused?** Variables are just labeled boxes - practice with simple examples!

**Remember:** The more you practice with variables, the more natural they become! 💪
