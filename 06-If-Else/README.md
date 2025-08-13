# 🤔 Chapter 6: Control Flow (if/else) - Making Decisions

## 🎯 What You'll Learn
- Basic if statements
- if-else statements
- if-else if-else chains
- Nested if statements
- Switch statements
- Conditional (ternary) operator
- Common decision-making patterns

## 📝 The Story
Programming is like teaching a computer to make decisions just like humans do. "If it's raining, take an umbrella. Otherwise, don't." Now your programs can be smart and responsive!

---

## 🎯 Basic if Statement

### Simple Decision Making
```c
#include <stdio.h>

int main() {
    int age;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age >= 18) {
        printf("You are an adult!\n");
        printf("You can vote!\n");
    }
    
    printf("Program finished.\n");
    return 0;
}
```

### Syntax Breakdown
```c
if (condition) {
    // Code that runs if condition is true
    statement1;
    statement2;
}
// Code here always runs
```

**Key Points:**
- `condition` must evaluate to true (non-zero) or false (zero)
- Curly braces `{}` group statements together
- If condition is false, the entire block is skipped

---

## ⚖️ if-else Statement

### Two-Way Decision Making
```c
#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }
    
    return 0;
}
```

### Real-World Example: Grade Checker
```c
#include <stdio.h>

int main() {
    float score;
    
    printf("Enter your test score: ");
    scanf("%f", &score);
    
    if (score >= 60) {
        printf("Congratulations! You passed!\n");
        printf("Your score: %.1f\n", score);
    } else {
        printf("Sorry, you failed.\n");
        printf("You need at least 60 to pass.\n");
        printf("Your score: %.1f\n", score);
    }
    
    return 0;
}
```

---

## 🔗 if-else if-else Chains

### Multiple Conditions
```c
#include <stdio.h>

int main() {
    float score;
    
    printf("Enter your test score: ");
    scanf("%f", &score);
    
    if (score >= 90) {
        printf("Grade: A (Excellent!)\n");
    } else if (score >= 80) {
        printf("Grade: B (Good job!)\n");
    } else if (score >= 70) {
        printf("Grade: C (Satisfactory)\n");
    } else if (score >= 60) {
        printf("Grade: D (Needs improvement)\n");
    } else {
        printf("Grade: F (Failed)\n");
    }
    
    return 0;
}
```

### How It Works
```c
if (condition1) {
    // Runs if condition1 is true
} else if (condition2) {
    // Runs if condition1 is false AND condition2 is true
} else if (condition3) {
    // Runs if condition1 and condition2 are false AND condition3 is true
} else {
    // Runs if all above conditions are false
}
```

**Important:** Only ONE block executes, even if multiple conditions are true!

### Temperature Advisory System
```c
#include <stdio.h>

int main() {
    float temp;
    
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &temp);
    
    printf("Temperature: %.1f°F - ", temp);
    
    if (temp >= 100) {
        printf("EXTREMELY HOT! Stay inside with AC.\n");
    } else if (temp >= 85) {
        printf("Very hot. Drink lots of water.\n");
    } else if (temp >= 70) {
        printf("Nice weather. Perfect for outdoor activities.\n");
    } else if (temp >= 50) {
        printf("Cool weather. Light jacket recommended.\n");
    } else if (temp >= 32) {
        printf("Cold! Wear warm clothes.\n");
    } else {
        printf("FREEZING! Stay warm and be careful of ice.\n");
    }
    
    return 0;
}
```

---

## 🏗️ Nested if Statements

### if Statements Inside if Statements
```c
#include <stdio.h>

int main() {
    int age;
    char hasLicense;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age >= 16) {
        printf("Do you have a driver's license? (y/n): ");
        scanf(" %c", &hasLicense);
        
        if (hasLicense == 'y' || hasLicense == 'Y') {
            printf("You can drive!\n");
        } else {
            printf("You're old enough, but need a license first.\n");
        }
    } else {
        printf("You're too young to drive.\n");
    }
    
    return 0;
}
```

### Complex Example: College Admission System
```c
#include <stdio.h>

int main() {
    float gpa;
    int satScore;
    char hasRecommendation;
    
    printf("=== COLLEGE ADMISSION CHECKER ===\n");
    printf("Enter your GPA (0.0-4.0): ");
    scanf("%f", &gpa);
    
    if (gpa >= 3.5) {
        printf("Great GPA! Now checking SAT score...\n");
        printf("Enter your SAT score (400-1600): ");
        scanf("%d", &satScore);
        
        if (satScore >= 1200) {
            printf("Excellent! You're automatically admitted!\n");
        } else if (satScore >= 1000) {
            printf("Good SAT score. Do you have a recommendation letter? (y/n): ");
            scanf(" %c", &hasRecommendation);
            
            if (hasRecommendation == 'y' || hasRecommendation == 'Y') {
                printf("Congratulations! You're admitted!\n");
            } else {
                printf("You're on the waiting list.\n");
            }
        } else {
            printf("SAT score too low. Consider retaking the test.\n");
        }
    } else if (gpa >= 3.0) {
        printf("Decent GPA. You need a very high SAT score.\n");
        printf("Enter your SAT score: ");
        scanf("%d", &satScore);
        
        if (satScore >= 1400) {
            printf("Amazing SAT score! You're admitted!\n");
        } else {
            printf("Unfortunately, we cannot admit you at this time.\n");
        }
    } else {
        printf("GPA is too low for admission.\n");
    }
    
    return 0;
}
```

---

## 🔄 Switch Statement

### Multiple Choice Selection
```c
#include <stdio.h>

int main() {
    int choice;
    
    printf("=== SIMPLE CALCULATOR ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You chose Addition\n");
            // Add code for addition here
            break;
        case 2:
            printf("You chose Subtraction\n");
            // Add code for subtraction here
            break;
        case 3:
            printf("You chose Multiplication\n");
            // Add code for multiplication here
            break;
        case 4:
            printf("You chose Division\n");
            // Add code for division here
            break;
        default:
            printf("Invalid choice! Please select 1-4.\n");
            break;
    }
    
    return 0;
}
```

### Character-Based Switch
```c
#include <stdio.h>

int main() {
    char grade;
    
    printf("Enter your letter grade: ");
    scanf(" %c", &grade);
    
    switch (grade) {
        case 'A':
        case 'a':
            printf("Excellent! GPA: 4.0\n");
            break;
        case 'B':
        case 'b':
            printf("Good job! GPA: 3.0\n");
            break;
        case 'C':
        case 'c':
            printf("Satisfactory. GPA: 2.0\n");
            break;
        case 'D':
        case 'd':
            printf("Needs improvement. GPA: 1.0\n");
            break;
        case 'F':
        case 'f':
            printf("Failed. GPA: 0.0\n");
            break;
        default:
            printf("Invalid grade entered.\n");
            break;
    }
    
    return 0;
}
```

### 🚨 Important: The break Statement
```c
// WITHOUT break (dangerous!)
switch (number) {
    case 1:
        printf("One\n");
        // Falls through to case 2!
    case 2:
        printf("Two\n");
        // Falls through to case 3!
    case 3:
        printf("Three\n");
}
// If number is 1, prints: One, Two, Three

// WITH break (correct!)
switch (number) {
    case 1:
        printf("One\n");
        break;
    case 2:
        printf("Two\n");
        break;
    case 3:
        printf("Three\n");
        break;
}
// If number is 1, prints: One
```

---

## ❓ Conditional (Ternary) Operator

### Short Form of if-else
```c
condition ? value_if_true : value_if_false
```

### Examples
```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int max, min;
    char *result;
    
    // Find maximum
    max = (a > b) ? a : b;
    printf("Maximum: %d\n", max);
    
    // Find minimum
    min = (a < b) ? a : b;
    printf("Minimum: %d\n", min);
    
    // Even or odd
    result = (a % 2 == 0) ? "even" : "odd";
    printf("%d is %s\n", a, result);
    
    // Absolute value
    int number = -5;
    int absolute = (number < 0) ? -number : number;
    printf("Absolute value of %d is %d\n", number, absolute);
    
    return 0;
}
```

### When to Use Ternary Operator
```c
// Good for simple assignments
int max = (a > b) ? a : b;

// NOT good for complex logic (use regular if-else instead)
// This is hard to read:
int result = (score >= 90) ? 4 : (score >= 80) ? 3 : (score >= 70) ? 2 : 1;

// Better as regular if-else:
int result;
if (score >= 90) {
    result = 4;
} else if (score >= 80) {
    result = 3;
} else if (score >= 70) {
    result = 2;
} else {
    result = 1;
}
```

---

## 🎮 Real-World Examples

### ATM Machine Simulator
```c
#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.00;
    float amount;
    
    printf("=== ATM MACHINE ===\n");
    printf("Current Balance: $%.2f\n\n", balance);
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Your current balance is: $%.2f\n", balance);
            break;
        case 2:
            printf("Enter amount to deposit: $");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Deposit successful! New balance: $%.2f\n", balance);
            } else {
                printf("Invalid amount!\n");
            }
            break;
        case 3:
            printf("Enter amount to withdraw: $");
            scanf("%f", &amount);
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("Withdrawal successful! New balance: $%.2f\n", balance);
            } else if (amount > balance) {
                printf("Insufficient funds!\n");
            } else {
                printf("Invalid amount!\n");
            }
            break;
        case 4:
            printf("Thank you for using our ATM!\n");
            break;
        default:
            printf("Invalid choice! Please select 1-4.\n");
    }
    
    return 0;
}
```

### Age Category Classifier
```c
#include <stdio.h>

int main() {
    int age;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age < 0) {
        printf("Invalid age!\n");
    } else if (age <= 2) {
        printf("You are a baby.\n");
    } else if (age <= 12) {
        printf("You are a child.\n");
        if (age >= 6) {
            printf("You should be in elementary school.\n");
        }
    } else if (age <= 19) {
        printf("You are a teenager.\n");
        if (age >= 13 && age <= 15) {
            printf("Middle school age.\n");
        } else {
            printf("High school age.\n");
        }
    } else if (age <= 64) {
        printf("You are an adult.\n");
        if (age >= 18 && age <= 25) {
            printf("Young adult phase.\n");
        } else if (age >= 26 && age <= 40) {
            printf("Prime adult years.\n");
        } else {
            printf("Mature adult.\n");
        }
    } else {
        printf("You are a senior citizen.\n");
        if (age >= 65 && age <= 75) {
            printf("Young senior.\n");
        } else {
            printf("Elder senior.\n");
        }
    }
    
    return 0;
}
```

---

## 🎯 Practice Exercises

### Exercise 1: Number Classifier
Write a program that classifies a number as:
- Positive, negative, or zero
- Even or odd (if not zero)
- Single digit, double digit, or more

### Exercise 2: Simple Restaurant Menu
Create a menu system with at least 5 items. Ask the user to select an item and display the price and description.

### Exercise 3: BMI Calculator with Categories
Calculate BMI and categorize as:
- Underweight (< 18.5)
- Normal (18.5 - 24.9)
- Overweight (25.0 - 29.9)
- Obese (≥ 30.0)

---

## 🚫 Common Mistakes

### ❌ Using = instead of ==
```c
int age = 18;
if (age = 20) {        // WRONG! This assigns 20 to age
    printf("Twenty years old");
}
```
**✅ Fix:**
```c
int age = 18;
if (age == 20) {       // Correct! This compares age to 20
    printf("Twenty years old");
}
```

### ❌ Missing braces with multiple statements
```c
if (score >= 90)
    printf("Grade A");
    printf("Excellent work!");  // This ALWAYS executes!
```
**✅ Fix:**
```c
if (score >= 90) {
    printf("Grade A");
    printf("Excellent work!");  // Both statements in the block
}
```

### ❌ Forgetting break in switch
```c
switch (choice) {
    case 1:
        printf("Option 1");
        // Missing break! Falls through to case 2
    case 2:
        printf("Option 2");
        break;
}
```
**✅ Fix:**
```c
switch (choice) {
    case 1:
        printf("Option 1");
        break;              // Add break
    case 2:
        printf("Option 2");
        break;
}
```

### ❌ Comparing floats with ==
```c
float result = 1.0 / 3.0 * 3.0;
if (result == 1.0) {    // Might not work due to floating point precision
    printf("Equal");
}
```
**✅ Fix:**
```c
float result = 1.0 / 3.0 * 3.0;
if (result > 0.99 && result < 1.01) {  // Use range comparison
    printf("Approximately equal");
}
```

---

## 📚 Key Takeaways

✅ **if** statements let programs make decisions  
✅ **if-else** provides two-way branching  
✅ **if-else if-else** handles multiple conditions  
✅ **Nested if** allows complex decision trees  
✅ **switch** is great for multiple discrete choices  
✅ **Ternary operator** is shorthand for simple if-else  
✅ Always use `==` for comparison, not `=`  
✅ Use braces `{}` for multiple statements  
✅ Don't forget `break` in switch statements  

---

## 🚀 What's Next?

Awesome! Your programs can now make smart decisions! 🎉

**Next Chapter:** [Loops - Repeating Tasks →](../07-Loops/)

In the next chapter, you'll learn how to make your programs repeat tasks automatically - one of the most powerful features in programming!

---

## 📞 Need Help?

- **Conditions not working?** Check if you're using `==` instead of `=`
- **Multiple statements not executing?** Make sure you have braces `{}`
- **Switch not working correctly?** Don't forget the `break` statements
- **Complex logic confusing?** Break it down into smaller if statements first

**Remember:** Decision-making is what makes programs intelligent and useful! 🧠
