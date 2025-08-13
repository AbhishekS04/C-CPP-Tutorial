/*
 * Student Profile Example
 * A complete example showing how to use variables for real-world data
 */

#include <stdio.h>

int main() {
    // Student information using different variable types
    char initial = 'S';        // First initial
    int age = 19;             // Age in years
    float gpa = 3.75;         // Grade Point Average
    int creditsCompleted = 45; // Credits completed
    char letterGrade = 'B';    // Current grade
    float tuitionOwed = 5500.00; // Tuition balance
    
    // Display student profile
    printf("╔═══════════════════════════════╗\n");
    printf("║        STUDENT PROFILE        ║\n");
    printf("╚═══════════════════════════════╝\n");
    printf("\nPersonal Information:\n");
    printf("  Initial: %c\n", initial);
    printf("  Age: %d years old\n", age);
    
    printf("\nAcademic Information:\n");
    printf("  Current GPA: %.2f\n", gpa);
    printf("  Credits Completed: %d\n", creditsCompleted);
    printf("  Current Grade: %c\n", letterGrade);
    
    printf("\nFinancial Information:\n");
    printf("  Tuition Balance: $%.2f\n", tuitionOwed);
    
    // Simulate end of semester updates
    printf("\n" "═" "═" "═" " END OF SEMESTER UPDATE " "═" "═" "═" "\n");
    
    // Update values
    age = 20;                 // Birthday!
    gpa = 3.80;              // Improved GPA
    creditsCompleted = 60;    // Completed more credits
    letterGrade = 'A';        // Better grade
    tuitionOwed = 3200.00;    // Paid some tuition
    
    printf("\nUpdated Profile:\n");
    printf("  Age: %d years old (Happy Birthday!)\n", age);
    printf("  New GPA: %.2f (Great improvement!)\n", gpa);
    printf("  Credits Completed: %d\n", creditsCompleted);
    printf("  New Grade: %c (Excellent work!)\n", letterGrade);
    printf("  Tuition Balance: $%.2f\n", tuitionOwed);
    
    // Calculate some derived information
    int creditsRemaining = 120 - creditsCompleted;  // Assuming 120 total credits needed
    float amountPaid = 5500.00 - tuitionOwed;
    
    printf("\nCalculated Information:\n");
    printf("  Credits remaining to graduate: %d\n", creditsRemaining);
    printf("  Amount paid this semester: $%.2f\n", amountPaid);
    
    return 0;
}
