/*
 * Grade Calculator Example
 * Demonstrates if-else chains and logical decision making
 */

#include <stdio.h>

int main() {
    float test1, test2, test3, average;
    char letterGrade;
    
    printf("=== STUDENT GRADE CALCULATOR ===\n");
    
    // Get test scores
    printf("Enter score for Test 1: ");
    scanf("%f", &test1);
    
    printf("Enter score for Test 2: ");
    scanf("%f", &test2);
    
    printf("Enter score for Test 3: ");
    scanf("%f", &test3);
    
    // Calculate average
    average = (test1 + test2 + test3) / 3.0;
    
    // Determine letter grade using if-else chain
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
    
    // Display results
    printf("\n=== GRADE REPORT ===\n");
    printf("Test 1 Score: %.2f\n", test1);
    printf("Test 2 Score: %.2f\n", test2);
    printf("Test 3 Score: %.2f\n", test3);
    printf("Average Score: %.2f\n", average);
    printf("Letter Grade: %c\n", letterGrade);
    
    // Additional feedback based on grade
    if (letterGrade == 'A') {
        printf("Status: Excellent work! 🌟\n");
    } else if (letterGrade == 'B') {
        printf("Status: Good job! Keep it up! 👍\n");
    } else if (letterGrade == 'C') {
        printf("Status: Satisfactory. Room for improvement. 📚\n");
    } else if (letterGrade == 'D') {
        printf("Status: Needs significant improvement. 📖\n");
    } else {
        printf("Status: Failed. Please study more and retake. ❌\n");
    }
    
    // Check if passing (nested if example)
    if (average >= 60) {
        printf("Result: PASSED ✅\n");
        if (average >= 85) {
            printf("Bonus: Eligible for honor roll!\n");
        }
    } else {
        printf("Result: FAILED ❌\n");
        printf("You need %.2f more points to pass.\n", 60.0 - average);
    }
    
    return 0;
}
