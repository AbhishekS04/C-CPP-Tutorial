/*
 * Simple Calculator Example
 * Demonstrates arithmetic operators, input/output, and if-else statements
 */

#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;
    
    printf("=== SIMPLE CALCULATOR ===\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    
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
        printf("Error: Invalid operation '%c'\n", operation);
        printf("Please use +, -, *, or /\n");
    }
    
    return 0;
}
