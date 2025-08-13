/*
 * Basic Variables Example
 * This program demonstrates how to create and use different types of variables
 */

#include <stdio.h>

int main() {
    // Integer variables (whole numbers)
    int age = 20;
    int students = 25;
    int temperature = -5;
    
    // Float variables (decimal numbers)
    float height = 5.8;
    float price = 19.99;
    float weight = 70.5;
    
    // Character variables (single letters/symbols)
    char grade = 'A';
    char initial = 'J';
    char symbol = '@';
    
    // Display all variables
    printf("=== INTEGER VARIABLES ===\n");
    printf("Age: %d years\n", age);
    printf("Number of students: %d\n", students);
    printf("Temperature: %d°C\n", temperature);
    
    printf("\n=== FLOAT VARIABLES ===\n");
    printf("Height: %.1f meters\n", height);
    printf("Price: $%.2f\n", price);
    printf("Weight: %.1f kg\n", weight);
    
    printf("\n=== CHARACTER VARIABLES ===\n");
    printf("Grade: %c\n", grade);
    printf("Initial: %c\n", initial);
    printf("Symbol: %c\n", symbol);
    
    // Changing variable values
    printf("\n=== CHANGING VALUES ===\n");
    age = 21;
    grade = 'A';
    price = 24.99;
    
    printf("New age: %d years\n", age);
    printf("New grade: %c\n", grade);
    printf("New price: $%.2f\n", price);
    
    return 0;
}
