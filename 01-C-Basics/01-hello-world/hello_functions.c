/**
 * @file hello_functions.c
 * @brief Hello World program demonstrating multiple functions
 * @author Tutorial Author
 * @date 2024
 * 
 * This program shows how to organize code into separate functions,
 * demonstrating function declarations, definitions, and calls.
 */

#include <stdio.h>

// Function declarations (prototypes)
void print_welcome_banner(void);
void print_greeting(void);
void print_program_info(void);
void print_separator(void);

/**
 * @brief Main function that calls other functions
 * @return 0 on success
 */
int main() {
    print_welcome_banner();
    print_separator();
    print_greeting();
    print_separator();
    print_program_info();
    
    printf("\nThank you for running this program!\n");
    return 0;
}

/**
 * @brief Prints a welcome banner with ASCII art
 */
void print_welcome_banner(void) {
    printf("╔════════════════════════════════════╗\n");
    printf("║        WELCOME TO C WORLD!         ║\n");
    printf("║         Hello, World! Demo        ║\n");
    printf("╚════════════════════════════════════╝\n");
}

/**
 * @brief Prints the main greeting message
 */
void print_greeting(void) {
    printf("Hello, World!\n");
    printf("Greetings from the world of C programming!\n");
    printf("This message comes from a separate function.\n");
}

/**
 * @brief Prints information about the program
 */
void print_program_info(void) {
    printf("Program: Multi-Function Hello World\n");
    printf("Language: C Programming Language\n");
    printf("Functions used: 5 (including main)\n");
    printf("Purpose: Demonstrate function organization\n");
}

/**
 * @brief Prints a separator line
 */
void print_separator(void) {
    printf("----------------------------------------\n");
}
