/**
 * @file hello_interactive.c
 * @brief Interactive Hello World program that takes user input
 * @author Tutorial Author
 * @date 2024
 * 
 * This program demonstrates basic input/output operations by
 * reading the user's name and providing a personalized greeting.
 */

#include <stdio.h>

int main() {
    // Declare a character array to store the user's name
    char name[50];  // Array can hold up to 49 characters + null terminator
    
    // Greet the user and ask for their name
    printf("Hello! Welcome to C programming.\n");
    printf("What is your name? ");
    
    // Read the user's input
    // Note: scanf stops at whitespace, so it only reads first name
    scanf("%s", name);
    
    // Provide personalized greetings
    printf("\nNice to meet you, %s!\n", name);
    printf("Hello, %s! Welcome to the world of C programming.\n", name);
    printf("I hope you enjoy learning C, %s!\n", name);
    
    // Additional information
    printf("\n=== Program Information ===\n");
    printf("Language: C\n");
    printf("Your name: %s\n", name);
    printf("Status: First interactive program complete!\n");
    
    return 0;
}
