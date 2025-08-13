# 🧮 Chapter 5: Operators - Doing Math and Logic

## 🎯 What You'll Learn
- Arithmetic operators (+, -, *, /, %)
- Comparison operators (==, !=, <, >, <=, >=)
- Logical operators (&&, ||, !)
- Assignment operators (=, +=, -=, etc.)
- Increment/decrement operators (++, --)
- Operator precedence and associativity

## 📝 The Story
Operators are like the tools in your mathematical toolbox. Just like you use + for addition in math class, C has operators for calculations, comparisons, and logical decisions!

---

## 🧮 Arithmetic Operators

### Basic Math Operations
```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    printf("=== ARITHMETIC OPERATIONS ===\n");
    printf("a = %d, b = %d\n\n", a, b);
    
    printf("Addition:       %d + %d = %d\n", a, b, a + b);
    printf("Subtraction:    %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    printf("Division:       %d / %d = %d\n", a, b, a / b);
    printf("Remainder:      %d %% %d = %d\n", a, b, a % b);
    
    return 0;
}
```

**Output:**
```
=== ARITHMETIC OPERATIONS ===
a = 10, b = 3

Addition:       10 + 3 = 13
Subtraction:    10 - 3 = 7
Multiplication: 10 * 3 = 30
Division:       10 / 3 = 3
Remainder:      10 % 3 = 1
```

### Understanding Each Operator

| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `+` | Addition | Adds two numbers | `5 + 3 = 8` |
| `-` | Subtraction | Subtracts second from first | `5 - 3 = 2` |
| `*` | Multiplication | Multiplies two numbers | `5 * 3 = 15` |
| `/` | Division | Divides first by second | `6 / 3 = 2` |
| `%` | Modulus (Remainder) | Remainder after division | `7 % 3 = 1` |

### 🔍 Division Gotchas

#### Integer Division
```c
int result = 7 / 2;        // Result is 3, not 3.5!
printf("%d", result);      // Prints: 3
```

#### Float Division
```c
float result = 7.0 / 2.0;  // Result is 3.5
printf("%.1f", result);    // Prints: 3.5
```

#### Mixed Division
```c
int a = 7, b = 2;
float result = (float)a / b;  // Cast to get decimal result
printf("%.2f", result);       // Prints: 3.50
```

### 🎯 Modulus (%) Examples
```c
printf("%d %% %d = %d\n", 10, 3, 10 % 3);  // 10 % 3 = 1
printf("%d %% %d = %d\n", 15, 4, 15 % 4);  // 15 % 4 = 3
printf("%d %% %d = %d\n", 8, 2, 8 % 2);    // 8 % 2 = 0 (even)
printf("%d %% %d = %d\n", 9, 2, 9 % 2);    // 9 % 2 = 1 (odd)
```

**Common uses:**
- Check if number is even: `if (num % 2 == 0)`
- Get last digit: `lastDigit = num % 10`
- Cycle through values: `index = (index + 1) % arraySize`

---

## ⚖️ Comparison Operators

### All Comparison Operators
```c
#include <stdio.h>

int main() {
    int a = 10, b = 5, c = 10;
    
    printf("=== COMPARISON OPERATIONS ===\n");
    printf("a = %d, b = %d, c = %d\n\n", a, b, c);
    
    printf("a == b: %d (Equal to)\n", a == b);           // 0 (false)
    printf("a != b: %d (Not equal to)\n", a != b);       // 1 (true)
    printf("a > b:  %d (Greater than)\n", a > b);        // 1 (true)
    printf("a < b:  %d (Less than)\n", a < b);           // 0 (false)
    printf("a >= c: %d (Greater than or equal)\n", a >= c); // 1 (true)
    printf("a <= c: %d (Less than or equal)\n", a <= c); // 1 (true)
    
    return 0;
}
```

### Understanding True/False
In C:
- **0** = False
- **Any non-zero number** = True

```c
if (5) {
    printf("This prints because 5 is true!\n");
}

if (0) {
    printf("This never prints because 0 is false!\n");
}
```

### Practical Comparison Examples
```c
int age = 18;
int score = 85;

// Age checking
if (age >= 18) {
    printf("You can vote!\n");
} else {
    printf("Too young to vote.\n");
}

// Grade checking
if (score >= 90) {
    printf("Grade: A\n");
} else if (score >= 80) {
    printf("Grade: B\n");
} else if (score >= 70) {
    printf("Grade: C\n");
} else {
    printf("Grade: F\n");
}
```

---

## 🧠 Logical Operators

### The Three Logical Operators

| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `&&` | AND | True if both conditions are true | `(a > 5) && (b < 10)` |
| `\|\|` | OR | True if at least one condition is true | `(a == 0) \|\| (b == 0)` |
| `!` | NOT | Reverses true/false | `!(a == b)` |

### AND (&&) Operator
```c
int age = 20;
int hasLicense = 1;  // 1 = true, 0 = false

if (age >= 18 && hasLicense) {
    printf("You can drive!\n");
} else {
    printf("You cannot drive.\n");
}

// Both conditions must be true:
// age >= 18 AND hasLicense must be true
```

### OR (||) Operator
```c
int isWeekend = 1;
int isHoliday = 0;

if (isWeekend || isHoliday) {
    printf("No work today!\n");
} else {
    printf("Work day.\n");
}

// At least one condition must be true:
// isWeekend OR isHoliday must be true
```

### NOT (!) Operator
```c
int isRaining = 0;  // 0 = false (not raining)

if (!isRaining) {
    printf("Let's go for a walk!\n");
} else {
    printf("Stay inside.\n");
}

// ! reverses the boolean value
// !0 = 1 (true), !1 = 0 (false)
```

### Complex Logical Expressions
```c
int age = 25;
int income = 50000;
int creditScore = 700;

// Loan approval logic
if ((age >= 21 && income >= 30000) || creditScore >= 750) {
    printf("Loan approved!\n");
} else {
    printf("Loan denied.\n");
}
```

---

## 📝 Assignment Operators

### Basic Assignment (=)
```c
int a = 10;        // Assign 10 to a
a = 20;           // Change a to 20
a = a + 5;        // Add 5 to a (now a is 25)
```

### Compound Assignment Operators
```c
int number = 10;

number += 5;    // Same as: number = number + 5;    (15)
number -= 3;    // Same as: number = number - 3;    (12)
number *= 2;    // Same as: number = number * 2;    (24)
number /= 4;    // Same as: number = number / 4;    (6)
number %= 5;    // Same as: number = number % 5;    (1)

printf("Final result: %d\n", number);  // Prints: 1
```

### Practical Example: Score Accumulator
```c
#include <stdio.h>

int main() {
    int totalScore = 0;
    int gameScore;
    
    printf("=== SCORE TRACKER ===\n");
    printf("Starting score: %d\n", totalScore);
    
    printf("Enter score from game 1: ");
    scanf("%d", &gameScore);
    totalScore += gameScore;
    printf("Total after game 1: %d\n", totalScore);
    
    printf("Enter score from game 2: ");
    scanf("%d", &gameScore);
    totalScore += gameScore;
    printf("Total after game 2: %d\n", totalScore);
    
    printf("Enter bonus points: ");
    scanf("%d", &gameScore);
    totalScore += gameScore;
    printf("Final total: %d\n", totalScore);
    
    return 0;
}
```

---

## ⬆️⬇️ Increment and Decrement Operators

### Pre-increment and Post-increment
```c
int a = 5, b = 5;

// Pre-increment (increment first, then use)
int x = ++a;    // a becomes 6, then x gets 6
printf("a = %d, x = %d\n", a, x);  // a = 6, x = 6

// Post-increment (use first, then increment)
int y = b++;    // y gets 5, then b becomes 6
printf("b = %d, y = %d\n", b, y);  // b = 6, y = 5
```

### Pre-decrement and Post-decrement
```c
int c = 5, d = 5;

// Pre-decrement
int p = --c;    // c becomes 4, then p gets 4
printf("c = %d, p = %d\n", c, p);  // c = 4, p = 4

// Post-decrement
int q = d--;    // q gets 5, then d becomes 4
printf("d = %d, q = %d\n", d, q);  // d = 4, q = 5
```

### Practical Usage
```c
// Common in loops (we'll learn loops later)
for (int i = 0; i < 10; i++) {    // i++ increments after each iteration
    printf("%d ", i);
}

// Counter example
int attempts = 3;
while (attempts-- > 0) {          // Use current value, then decrement
    printf("Attempts remaining: %d\n", attempts + 1);
}
```

---

## 🔄 Operator Precedence (Order of Operations)

Just like in math, operators have an order of precedence:

### Precedence Table (High to Low)
1. `()` - Parentheses
2. `++`, `--` - Increment/Decrement
3. `!` - Logical NOT
4. `*`, `/`, `%` - Multiplication, Division, Modulus
5. `+`, `-` - Addition, Subtraction
6. `<`, `<=`, `>`, `>=` - Relational operators
7. `==`, `!=` - Equality operators
8. `&&` - Logical AND
9. `||` - Logical OR
10. `=`, `+=`, `-=`, etc. - Assignment operators

### Examples
```c
int result = 2 + 3 * 4;          // 2 + (3 * 4) = 14, not (2 + 3) * 4 = 20
int result2 = (2 + 3) * 4;       // Use parentheses to change order = 20

int a = 10, b = 5;
int result3 = a > 5 && b < 10;   // (a > 5) && (b < 10) = 1 (true)
```

### 💡 Pro Tip: Use Parentheses for Clarity
```c
// Confusing (relies on precedence knowledge)
if (age >= 18 && income > 30000 || creditScore > 750)

// Clear (uses parentheses)
if ((age >= 18 && income > 30000) || (creditScore > 750))
```

---

## 🎯 Real-World Examples

### Grade Calculator
```c
#include <stdio.h>

int main() {
    float test1, test2, test3, average;
    char letterGrade;
    
    printf("=== GRADE CALCULATOR ===\n");
    printf("Enter three test scores:\n");
    printf("Test 1: ");
    scanf("%f", &test1);
    printf("Test 2: ");
    scanf("%f", &test2);
    printf("Test 3: ");
    scanf("%f", &test3);
    
    // Calculate average using arithmetic operators
    average = (test1 + test2 + test3) / 3.0;
    
    // Determine letter grade using comparison operators
    if (average >= 90) {
        letterGrade = 'A';
    } else if (average >= 80) {
        letterGrade = 'B';
    } else if (average >= 70) {
        letterGrade = 'C';
    } else if (average >= 60) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }
    
    printf("\nResults:\n");
    printf("Average: %.2f\n", average);
    printf("Letter Grade: %c\n", letterGrade);
    
    // Use logical operators for additional info
    if (letterGrade == 'A' || letterGrade == 'B') {
        printf("Great job! You're doing well!\n");
    } else if (letterGrade == 'C') {
        printf("You're passing, but could improve.\n");
    } else {
        printf("You need to study more.\n");
    }
    
    return 0;
}
```

### Even/Odd Checker
```c
#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Use modulus operator to check even/odd
    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }
    
    // Additional checks using logical operators
    if (number > 0 && number % 2 == 0) {
        printf("It's a positive even number.\n");
    } else if (number > 0 && number % 2 != 0) {
        printf("It's a positive odd number.\n");
    } else if (number < 0) {
        printf("It's a negative number.\n");
    } else {
        printf("It's zero.\n");
    }
    
    return 0;
}
```

---

## 🎯 Practice Exercises

### Exercise 1: Basic Calculator
Create a calculator that takes two numbers and performs all arithmetic operations on them.

### Exercise 2: Temperature Ranges
Ask for a temperature and determine if it's:
- Freezing (≤ 32°F)
- Cold (33-50°F)
- Moderate (51-70°F)
- Warm (71-85°F)
- Hot (> 85°F)

### Exercise 3: Leap Year Checker
A year is a leap year if:
- It's divisible by 4 AND not divisible by 100
- OR it's divisible by 400

Use logical operators to check this!

---

## 🚫 Common Mistakes

### ❌ Using = instead of ==
```c
int age = 18;
if (age = 20) {        // WRONG! This assigns 20 to age
    printf("Adult");
}
```
**✅ Fix:**
```c
int age = 18;
if (age == 20) {       // Correct! This compares age to 20
    printf("Adult");
}
```

### ❌ Division by zero
```c
int a = 10, b = 0;
int result = a / b;    // WRONG! This will crash your program
```
**✅ Fix:**
```c
int a = 10, b = 0;
if (b != 0) {
    int result = a / b;
    printf("Result: %d\n", result);
} else {
    printf("Cannot divide by zero!\n");
}
```

### ❌ Confusing && and ||
```c
// Want: age between 13 and 19 (teenager)
if (age >= 13 || age <= 19) {  // WRONG! This is always true
```
**✅ Fix:**
```c
if (age >= 13 && age <= 19) {  // Correct! Both conditions must be true
```

---

## 📚 Key Takeaways

✅ **Arithmetic operators** (+, -, *, /, %) perform mathematical calculations  
✅ **Comparison operators** (==, !=, <, >, <=, >=) compare values  
✅ **Logical operators** (&&, ||, !) combine conditions  
✅ **Assignment operators** (=, +=, -=, etc.) assign and modify values  
✅ **Increment/decrement** (++, --) increase or decrease by 1  
✅ Use parentheses to clarify complex expressions  
✅ Integer division truncates decimal parts  
✅ Use modulus (%) to find remainders  

---

## 🚀 What's Next?

Fantastic! You now have all the tools for calculations and decision making! 🎉

**Next Chapter:** [Control Flow (if/else) - Making Decisions →](../06-If-Else/)

In the next chapter, you'll learn how to use these operators to make your programs smart and responsive!

---

## 📞 Need Help?

- **Confused about precedence?** Use parentheses to make the order clear
- **Getting unexpected results?** Check if you're using = instead of ==
- **Division not working?** Remember integer division truncates decimals
- **Logical operators confusing?** Draw truth tables to understand them better

**Remember:** Operators are the building blocks of all program logic! 🔧
