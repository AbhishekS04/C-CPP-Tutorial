/**
 * @file hello_enhanced.c
 * @brief Enhanced Hello World program with multiple messages
 * @author Tutorial Author
 * @date 2024
 * 
 * This program demonstrates multiple printf statements and
 * shows different formatting options available in C.
 */

#include <stdio.h>

int main() {
    // Multiple greeting messages
    printf("Hello, World!\n");
    printf("Welcome to C programming!\n");
    printf("This is my first enhanced C program.\n");
    
    // Demonstrate different escape sequences
    printf("\n");  // Empty line
    printf("Here are some formatting examples:\n");
    printf("Tab-separated:\tHello\tWorld\n");
    printf("Quoted text: \"Hello, World!\"\n");
    printf("Backslash: C:\\Program Files\\\n");
    
    // Some simple ASCII art
    printf("\n");
    printf("    *    \n");
    printf("   ***   \n");
    printf("  *****  \n");
    printf(" ******* \n");
    printf("*********\n");
    
    printf("\nProgram completed successfully!\n");
    return 0;
}
