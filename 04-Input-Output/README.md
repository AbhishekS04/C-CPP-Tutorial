# 💬 Chapter 4: Input/Output - Talking to Users

## 🎯 What You'll Learn
- How to get input from users with scanf()
- Different ways to display output with printf()
- Handling different data types in input/output
- Common input/output problems and solutions
- Building interactive programs

## 📝 The Story
Imagine programming as having a conversation with your computer. Until now, your programs could only "speak" (output). Now you'll learn how to "listen" (input) too!

---

## 💡 Input vs Output

**Output (printf)** - Your program talks to the user
```c
printf("Hello, user!");  // Computer says hello
```

**Input (scanf)** - Your program listens to the user
```c
scanf("%d", &age);       // Computer asks for and receives a number
```

Think of it as:
- 📢 **Output** = Speaking/Showing
- 👂 **Input** = Listening/Receiving

---

## 🎯 Complete Input/Output Example

```c
#include <stdio.h>

int main() {
    // Variables to store user input
    int age;
    float height;
    char initial;
    
    // OUTPUT: Greet the user
    printf("=== PERSONAL INFORMATION COLLECTOR ===\n");
    printf("Hi! I'd like to get to know you better.\n\n");
    
    // INPUT: Get user's age
    printf("What's your age? ");
    scanf("%d", &age);
    
    // INPUT: Get user's height
    printf("What's your height in feet? (e.g., 5.8): ");
    scanf("%f", &height);
    
    // INPUT: Get user's initial
    printf("What's your first initial? ");
    scanf(" %c", &initial);  // Note the space before %c
    
    // OUTPUT: Display collected information
    printf("\n=== YOUR INFORMATION ===\n");
    printf("Age: %d years old\n", age);
    printf("Height: %.1f feet\n", height);
    printf("Initial: %c\n", initial);
    printf("Nice to meet you, %c!\n", initial);
    
    return 0;
}
```

**Sample Run:**
```
=== PERSONAL INFORMATION COLLECTOR ===
Hi! I'd like to get to know you better.

What's your age? 20
What's your height in feet? (e.g., 5.8): 5.7
What's your first initial? J

=== YOUR INFORMATION ===
Age: 20 years old
Height: 5.7 feet
Initial: J
Nice to meet you, J!
```

---

## 📢 Output with printf()

### Basic printf Usage
```c
printf("Simple text");                    // Print text
printf("Number: %d", 42);                // Print number
printf("Float: %.2f", 3.14159);          // Print float with 2 decimals
printf("Character: %c", 'A');            // Print character
```

### Multiple Values in One printf
```c
int age = 20;
float gpa = 3.75;
char grade = 'B';

printf("Age: %d, GPA: %.2f, Grade: %c\n", age, gpa, grade);
// Output: Age: 20, GPA: 3.75, Grade: B
```

### Formatting Numbers
```c
int number = 1234;
float decimal = 123.456789;

printf("Basic: %d\n", number);           // Output: Basic: 1234
printf("Padded: %8d\n", number);         // Output: Padded:     1234
printf("Zero-padded: %08d\n", number);   // Output: Zero-padded: 00001234

printf("Basic float: %f\n", decimal);    // Output: Basic float: 123.456789
printf("2 decimals: %.2f\n", decimal);   // Output: 2 decimals: 123.46
printf("Width & decimals: %10.2f\n", decimal);  // Output: Width & decimals:     123.46
```

### Special Characters
```c
printf("Line 1\n");           // \n = new line
printf("Tab\there\n");        // \t = tab
printf("Quote: \"Hello\"\n"); // \" = quotation mark
printf("Backslash: \\\n");    // \\ = backslash
printf("Percent: %%\n");      // %% = percent sign
```

---

## 👂 Input with scanf()

### Basic scanf Usage
```c
int age;
printf("Enter your age: ");
scanf("%d", &age);              // Note the & before variable name!
printf("You are %d years old\n", age);
```

### 🚨 Important: The & Symbol
```c
int number;
scanf("%d", &number);    // ✅ Correct: & gives address of variable
scanf("%d", number);     // ❌ Wrong: This will cause problems!
```

The `&` tells scanf **where** to put the input value.

### Input Different Data Types
```c
int age;
float height;
char initial;
double salary;

printf("Age: ");
scanf("%d", &age);

printf("Height: ");
scanf("%f", &height);           // %f for float input

printf("Initial: ");
scanf(" %c", &initial);         // Space before %c is important!

printf("Salary: ");
scanf("%lf", &salary);          // %lf for double input
```

---

## 🎮 Interactive Programs

### Simple Calculator
```c
#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;
    
    printf("=== SIMPLE CALCULATOR ===\n");
    
    // Get first number
    printf("Enter first number: ");
    scanf("%f", &num1);
    
    // Get operation
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    
    // Get second number
    printf("Enter second number: ");
    scanf("%f", &num2);
    
    // Perform calculation based on operation
    if (operation == '+') {
        result = num1 + num2;
        printf("%.2f + %.2f = %.2f\n", num1, num2, result);
    } else if (operation == '-') {
        result = num1 - num2;
        printf("%.2f - %.2f = %.2f\n", num1, num2, result);
    } else if (operation == '*') {
        result = num1 * num2;
        printf("%.2f * %.2f = %.2f\n", num1, num2, result);
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
        } else {
            printf("Error: Cannot divide by zero!\n");
        }
    } else {
        printf("Error: Invalid operation!\n");
    }
    
    return 0;
}
```

### Temperature Converter
```c
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;
    
    printf("=== TEMPERATURE CONVERTER ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        printf("%.1f°C = %.1f°F\n", celsius, fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        printf("%.1f°F = %.1f°C\n", fahrenheit, celsius);
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}
```

---

## 📊 Format Specifiers Reference

### Input (scanf) Format Specifiers
| Data Type | Format | Example |
|-----------|--------|---------|
| `int` | `%d` | `scanf("%d", &age)` |
| `float` | `%f` | `scanf("%f", &height)` |
| `double` | `%lf` | `scanf("%lf", &salary)` |
| `char` | `%c` | `scanf(" %c", &grade)` |
| `long` | `%ld` | `scanf("%ld", &bigNum)` |
| `unsigned int` | `%u` | `scanf("%u", &positive)` |

### Output (printf) Format Specifiers
| Data Type | Format | Example | Output |
|-----------|--------|---------|---------|
| `int` | `%d` | `printf("%d", 123)` | `123` |
| `float` | `%f` or `%.2f` | `printf("%.2f", 3.14159)` | `3.14` |
| `double` | `%f` or `%.2f` | `printf("%.2f", 3.14159)` | `3.14` |
| `char` | `%c` | `printf("%c", 'A')` | `A` |
| `long` | `%ld` | `printf("%ld", 123L)` | `123` |
| `unsigned int` | `%u` | `printf("%u", 123U)` | `123` |

---

## 🚫 Common Input/Output Mistakes

### ❌ Forgetting & in scanf
```c
int age;
scanf("%d", age);        // WRONG! Missing &
```
**✅ Fix:**
```c
int age;
scanf("%d", &age);       // Correct!
```

### ❌ Wrong format specifier
```c
float height;
scanf("%d", &height);    // WRONG! %d is for integers
```
**✅ Fix:**
```c
float height;
scanf("%f", &height);    // Correct!
```

### ❌ Character input problems
```c
int age;
char grade;

scanf("%d", &age);
scanf("%c", &grade);     // This might not work as expected!
```
**✅ Fix:**
```c
int age;
char grade;

scanf("%d", &age);
scanf(" %c", &grade);    // Space before %c to skip whitespace
```

### ❌ Double vs Float confusion
```c
double salary;
scanf("%f", &salary);    // WRONG! Use %lf for double
```
**✅ Fix:**
```c
double salary;
scanf("%lf", &salary);   // Correct!
```

---

## 🔧 Advanced Input/Output Techniques

### Reading Strings (Preview)
```c
char name[50];  // Array to hold string (we'll learn arrays later)
printf("Enter your name: ");
scanf("%s", name);       // No & needed for strings
printf("Hello, %s!\n", name);
```

### Multiple Inputs in One scanf
```c
int day, month, year;
printf("Enter date (dd mm yyyy): ");
scanf("%d %d %d", &day, &month, &year);
printf("Date: %02d/%02d/%d\n", day, month, year);
```

### Input Validation
```c
int age;
printf("Enter your age: ");
if (scanf("%d", &age) == 1) {    // Check if input was successful
    printf("Your age is %d\n", age);
} else {
    printf("Invalid input! Please enter a number.\n");
}
```

---

## 🎯 Practice Exercises

### Exercise 1: Personal Profile
Create a program that asks for:
- Name (use string - just try it!)
- Age (int)
- Height (float)
- Grade (char)

Then display a nice profile with all the information.

### Exercise 2: Grade Calculator
Ask the user for 3 test scores and calculate:
- The average score
- Display whether they passed (average >= 60)

### Exercise 3: Rectangle Calculator
Ask for length and width of a rectangle, then calculate and display:
- Area (length × width)
- Perimeter (2 × (length + width))

---

## 🎮 Interactive Examples

### Age Calculator
```c
#include <stdio.h>

int main() {
    int birthYear, currentYear, age;
    
    printf("=== AGE CALCULATOR ===\n");
    printf("What year were you born? ");
    scanf("%d", &birthYear);
    
    printf("What is the current year? ");
    scanf("%d", &currentYear);
    
    age = currentYear - birthYear;
    
    printf("You are approximately %d years old!\n", age);
    
    if (age >= 18) {
        printf("You are an adult.\n");
    } else {
        printf("You are a minor.\n");
    }
    
    return 0;
}
```

### BMI Calculator
```c
#include <stdio.h>

int main() {
    float weight, height, bmi;
    
    printf("=== BMI CALCULATOR ===\n");
    printf("Enter your weight in kg: ");
    scanf("%f", &weight);
    
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    
    bmi = weight / (height * height);
    
    printf("Your BMI is: %.2f\n", bmi);
    
    if (bmi < 18.5) {
        printf("Category: Underweight\n");
    } else if (bmi < 25.0) {
        printf("Category: Normal weight\n");
    } else if (bmi < 30.0) {
        printf("Category: Overweight\n");
    } else {
        printf("Category: Obese\n");
    }
    
    return 0;
}
```

---

## 🎉 Challenge: Student Management System

Create a program that:
1. Asks for student information (name, ID, 3 grades)
2. Calculates the average grade
3. Determines letter grade (A: 90+, B: 80+, C: 70+, D: 60+, F: below 60)
4. Displays a complete report

<details>
<summary>🎁 Click to see solution</summary>

```c
#include <stdio.h>

int main() {
    char name[50];
    int studentID;
    float grade1, grade2, grade3, average;
    char letterGrade;
    
    printf("=== STUDENT MANAGEMENT SYSTEM ===\n\n");
    
    // Collect student information
    printf("Enter student name: ");
    scanf("%s", name);
    
    printf("Enter student ID: ");
    scanf("%d", &studentID);
    
    printf("Enter grade 1: ");
    scanf("%f", &grade1);
    
    printf("Enter grade 2: ");
    scanf("%f", &grade2);
    
    printf("Enter grade 3: ");
    scanf("%f", &grade3);
    
    // Calculate average
    average = (grade1 + grade2 + grade3) / 3.0;
    
    // Determine letter grade
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
    
    // Display report
    printf("\n" "=" "=" "=" " STUDENT REPORT " "=" "=" "=" "\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    printf("Grade 1: %.2f\n", grade1);
    printf("Grade 2: %.2f\n", grade2);
    printf("Grade 3: %.2f\n", grade3);
    printf("Average: %.2f\n", average);
    printf("Letter Grade: %c\n", letterGrade);
    
    if (letterGrade != 'F') {
        printf("Status: PASSED\n");
    } else {
        printf("Status: FAILED\n");
    }
    
    return 0;
}
```

</details>

---

## 📚 Key Takeaways

✅ **printf()** is for output (program talking to user)  
✅ **scanf()** is for input (program listening to user)  
✅ Always use `&` before variable names in scanf (except for strings)  
✅ Match format specifiers with data types  
✅ Use space before `%c` in scanf to handle whitespace  
✅ `%lf` for double input, `%f` for double output  
✅ Check for input errors when possible  
✅ Interactive programs are more engaging and useful  

---

## 🚀 What's Next?

Excellent! You can now create interactive programs! 🎉

**Next Chapter:** [Operators - Doing Math and Logic →](../05-Operators/)

In the next chapter, you'll learn all about operators - the tools for doing calculations, comparisons, and logical operations.

---

## 📞 Need Help?

- **scanf not working?** Check if you forgot the `&` symbol
- **Characters not inputting correctly?** Add a space before `%c` in scanf
- **Getting wrong results?** Verify your format specifiers match your data types
- **Program skipping input?** This often happens with character input after number input

**Remember:** Input/output is the foundation of interactive programming - practice makes perfect! 💪
