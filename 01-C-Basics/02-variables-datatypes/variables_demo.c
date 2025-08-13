/**
 * @file variables_demo.c
 * @brief Comprehensive demonstration of C variables and data types
 * @author C/C++ Tutorial
 * @date 2024
 * 
 * This program demonstrates all fundamental data types in C,
 * including their sizes, ranges, and proper usage patterns.
 * It serves as a complete reference for variable declarations,
 * initialization, type conversions, and formatting.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>  // C99 feature for bool type

// Preprocessor constants
#define MAX_NAME_LENGTH 50
#define PI 3.14159265359
#define WELCOME_MESSAGE "Welcome to Variables Demo!"

// Named constants (preferred over #define)
const int CURRENT_YEAR = 2024;
const float GRAVITY = 9.81f;
const double LIGHT_SPEED = 299792458.0;  // meters per second

/**
 * @brief Demonstrates integer data types
 */
void demonstrate_integer_types(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║           INTEGER TYPES              ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    // Basic integer types with different sizes
    char tiny_number = 127;                    // 1 byte
    short small_number = 32767;                // 2 bytes typically
    int regular_number = 2147483647;           // 4 bytes typically
    long big_number = 2147483647L;             // 4 or 8 bytes
    long long huge_number = 9223372036854775807LL; // 8 bytes minimum
    
    printf("Data Type    | Value              | Size    | Min Value          | Max Value\n");
    printf("-------------|--------------------|---------|--------------------|--------------------\n");
    printf("char         | %18d | %2zu byte | %18d | %18d\n", 
           tiny_number, sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short        | %18hd | %2zu bytes| %18d | %18d\n", 
           small_number, sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int          | %18d | %2zu bytes| %18d | %18d\n", 
           regular_number, sizeof(int), INT_MIN, INT_MAX);
    printf("long         | %18ld | %2zu bytes| %18ld | %18ld\n", 
           big_number, sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long    | %18lld | %2zu bytes| %18lld | %18lld\n", 
           huge_number, sizeof(long long), LLONG_MIN, LLONG_MAX);
    
    // Demonstrate unsigned vs signed
    printf("\n--- Unsigned vs Signed Comparison ---\n");
    unsigned int positive_only = 4294967295U;  // Maximum unsigned int
    int can_be_negative = -1000000;
    
    printf("unsigned int: %u (always positive)\n", positive_only);
    printf("signed int:   %d (can be negative)\n", can_be_negative);
    
    // Show what happens with overflow
    printf("\n--- Overflow Demonstration ---\n");
    unsigned char max_uchar = 255;
    printf("unsigned char max: %u\n", max_uchar);
    max_uchar = max_uchar + 1;  // This will wrap around to 0
    printf("After +1 (overflow): %u\n", max_uchar);
}

/**
 * @brief Demonstrates character data type and ASCII values
 */
void demonstrate_character_type(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║           CHARACTER TYPE             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    char letter = 'A';
    char digit = '7';
    char symbol = '@';
    char newline = '\n';
    char tab = '\t';
    
    printf("Character literals and their ASCII values:\n");
    printf("Letter '%c' has ASCII value: %d\n", letter, letter);
    printf("Digit '%c' has ASCII value: %d\n", digit, digit);
    printf("Symbol '%c' has ASCII value: %d\n", symbol, symbol);
    printf("Newline '\\n' has ASCII value: %d\n", newline);
    printf("Tab '\\t' has ASCII value: %d\n", tab);
    
    // Demonstrate character arithmetic
    printf("\n--- Character Arithmetic ---\n");
    char uppercase = 'A';
    char lowercase = uppercase + 32;  // ASCII difference between A and a
    printf("Uppercase: %c (ASCII %d)\n", uppercase, uppercase);
    printf("Lowercase: %c (ASCII %d)\n", lowercase, lowercase);
    
    // Character ranges
    printf("\n--- Character Ranges ---\n");
    printf("char range: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char range: 0 to %d\n", UCHAR_MAX);
}

/**
 * @brief Demonstrates floating-point data types
 */
void demonstrate_floating_point_types(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║        FLOATING-POINT TYPES         ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    float single_precision = 3.14159f;
    double double_precision = 3.14159265358979323846;
    long double extended_precision = 3.14159265358979323846L;
    
    printf("Type         | Value                    | Size    | Precision\n");
    printf("-------------|--------------------------|---------|----------\n");
    printf("float        | %24.7f | %2zu bytes| ~7 digits\n", 
           single_precision, sizeof(float));
    printf("double       | %24.15lf | %2zu bytes| ~15 digits\n", 
           double_precision, sizeof(double));
    printf("long double  | %24.19Lf | %2zu bytes| varies\n", 
           extended_precision, sizeof(long double));
    
    // Scientific notation
    printf("\n--- Scientific Notation ---\n");
    double large_number = 1.23e10;    // 12,300,000,000
    double small_number = 4.56e-5;    // 0.0000456
    
    printf("Large number: %.2e = %.0f\n", large_number, large_number);
    printf("Small number: %.2e = %.7f\n", small_number, small_number);
    
    // Precision limitations
    printf("\n--- Precision Limitations ---\n");
    float precise_float = 1.23456789f;
    double precise_double = 1.23456789012345678901234567890;
    
    printf("float precision:  %.10f\n", precise_float);
    printf("double precision: %.20lf\n", precise_double);
    
    // Special values (requires C99)
    printf("\n--- Floating-Point Limits ---\n");
    printf("float min: %e, max: %e\n", FLT_MIN, FLT_MAX);
    printf("double min: %e, max: %e\n", DBL_MIN, DBL_MAX);
}

/**
 * @brief Demonstrates type conversions and casting
 */
void demonstrate_type_conversions(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║         TYPE CONVERSIONS             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    // Implicit conversions
    printf("--- Implicit Conversions ---\n");
    int int_value = 42;
    float float_from_int = int_value;  // int to float (safe)
    printf("int %d → float %.1f\n", int_value, float_from_int);
    
    float float_value = 3.99f;
    int int_from_float = float_value;  // float to int (loses decimal)
    printf("float %.2f → int %d (truncated)\n", float_value, int_from_float);
    
    // Explicit conversions (casting)
    printf("\n--- Explicit Conversions (Casting) ---\n");
    double precise_value = 3.99999;
    int casted_int = (int)precise_value;
    printf("(int)%.5lf = %d\n", precise_value, casted_int);
    
    // Division examples
    printf("\n--- Division Examples ---\n");
    int a = 7, b = 3;
    
    printf("Integer division: %d / %d = %d\n", a, b, a / b);
    printf("Float division: %d / %d = %.2f\n", a, b, (float)a / b);
    printf("Mixed division: %.1f / %d = %.2f\n", (float)a, b, (float)a / b);
    
    // Type promotion in expressions
    printf("\n--- Type Promotion in Expressions ---\n");
    char small = 10;
    short medium = 20;
    int large = small + medium;  // Both promoted to int
    printf("char(%d) + short(%d) = int(%d)\n", small, medium, large);
    
    float f = 2.5f;
    double d = f + 1;  // float promoted to double
    printf("float(%.1f) + int(1) = double(%.1lf)\n", f, d);
}

/**
 * @brief Demonstrates constants and literals
 */
void demonstrate_constants_and_literals(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║       CONSTANTS & LITERALS           ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    // Literal constants
    printf("--- Literal Constants ---\n");
    printf("Integer literals:\n");
    printf("  Decimal: %d\n", 42);
    printf("  Octal: %d (written as 0%o)\n", 052, 052);
    printf("  Hexadecimal: %d (written as 0x%X)\n", 0x2A, 0x2A);
    
    printf("\nFloating-point literals:\n");
    printf("  Float: %.2f (written as %.2ff)\n", 3.14f, 3.14f);
    printf("  Double: %.5lf (written as %.5f)\n", 3.14159, 3.14159);
    printf("  Scientific: %.2e (written as %.2e)\n", 1.5e3, 1.5e3);
    
    printf("\nCharacter literals:\n");
    printf("  Regular: '%c'\n", 'A');
    printf("  Escape sequences: newline='\\n', tab='\\t', quote='\\''\n");
    
    // Named constants vs preprocessor macros
    printf("\n--- Named Constants vs Macros ---\n");
    printf("Preprocessor macro PI: %.10f\n", PI);
    printf("const variable GRAVITY: %.2f\n", GRAVITY);
    printf("Macro MAX_NAME_LENGTH: %d\n", MAX_NAME_LENGTH);
    printf("const CURRENT_YEAR: %d\n", CURRENT_YEAR);
    
    // Demonstrate const behavior
    const int FIXED_VALUE = 100;
    printf("const int FIXED_VALUE = %d (cannot be changed)\n", FIXED_VALUE);
    // FIXED_VALUE = 200;  // This would cause a compilation error
}

/**
 * @brief Demonstrates variable scope and storage classes
 */
void demonstrate_scope_and_storage(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║       SCOPE & STORAGE CLASSES        ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    // Local variables
    printf("--- Variable Scope ---\n");
    int outer_variable = 10;
    printf("Outer scope variable: %d\n", outer_variable);
    
    // Block scope
    {
        int inner_variable = 20;
        printf("Inner scope variable: %d\n", inner_variable);
        printf("Outer variable accessible in inner scope: %d\n", outer_variable);
        
        // Variable shadowing
        int outer_variable = 30;  // Shadows the outer variable
        printf("Shadowed variable (inner): %d\n", outer_variable);
    }
    printf("Back to outer scope: %d\n", outer_variable);  // Original value
    
    // Static variables (retain value between function calls)
    printf("\n--- Static Variables ---\n");
    static int static_counter = 0;
    static_counter++;
    printf("Static counter: %d (retains value between calls)\n", static_counter);
}

/**
 * @brief Demonstrates advanced formatting techniques
 */
void demonstrate_formatting(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║         FORMAT SPECIFIERS            ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    int number = 42;
    float decimal = 3.14159f;
    
    printf("--- Integer Formatting ---\n");
    printf("Default: %d\n", number);
    printf("Width 10: '%10d'\n", number);
    printf("Left-aligned: '%-10d'\n", number);
    printf("Zero-padded: '%010d'\n", number);
    printf("Hexadecimal: %x (lowercase), %X (uppercase)\n", number, number);
    printf("Octal: %o\n", number);
    
    printf("\n--- Floating-Point Formatting ---\n");
    printf("Default: %f\n", decimal);
    printf("2 decimals: %.2f\n", decimal);
    printf("Width 10, 2 decimals: '%10.2f'\n", decimal);
    printf("Left-aligned: '%-10.2f'\n", decimal);
    printf("Scientific notation: %.2e\n", decimal);
    printf("Shorter of %%f or %%e: %.2g\n", decimal);
    
    printf("\n--- Character and String Formatting ---\n");
    char character = 'A';
    printf("Character: '%c', ASCII: %d\n", character, character);
    printf("String: '%s'\n", WELCOME_MESSAGE);
}

/**
 * @brief Interactive demonstration - gets user input
 */
void interactive_demo(void) {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║        INTERACTIVE DEMO              ║\n");
    printf("╚══════════════════════════════════════╝\n");
    
    int user_age;
    float user_height;
    char user_grade;
    
    printf("Let's practice with user input!\n");
    
    printf("Enter your age: ");
    if (scanf("%d", &user_age) == 1) {
        printf("You entered age: %d\n", user_age);
        
        // Type conversion demonstration
        float age_in_months = user_age * 12.0f;
        printf("That's approximately %.1f months\n", age_in_months);
    }
    
    printf("Enter your height in meters (e.g., 1.75): ");
    if (scanf("%f", &user_height) == 1) {
        printf("You entered height: %.2f meters\n", user_height);
        
        // Convert to centimeters
        int height_cm = (int)(user_height * 100);
        printf("That's %d centimeters\n", height_cm);
    }
    
    printf("Enter your grade (A, B, C, D, F): ");
    if (scanf(" %c", &user_grade) == 1) {  // Note the space before %c
        printf("You entered grade: '%c' (ASCII: %d)\n", user_grade, user_grade);
        
        // Convert to lowercase if uppercase
        if (user_grade >= 'A' && user_grade <= 'Z') {
            char lowercase_grade = user_grade + 32;
            printf("Lowercase version: '%c'\n", lowercase_grade);
        }
    }
}

/**
 * @brief Main function - orchestrates all demonstrations
 */
int main(void) {
    // Program header
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                C VARIABLES & DATA TYPES                   ║\n");
    printf("║                  COMPREHENSIVE DEMO                       ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("║ This program demonstrates all fundamental data types in C  ║\n");
    printf("║ including integers, characters, floating-point numbers,   ║\n");
    printf("║ type conversions, constants, and formatting options.      ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    // System information
    printf("\nSystem Information:\n");
    printf("sizeof(char): %zu byte(s)\n", sizeof(char));
    printf("sizeof(int): %zu byte(s)\n", sizeof(int));
    printf("sizeof(long): %zu byte(s)\n", sizeof(long));
    printf("sizeof(float): %zu byte(s)\n", sizeof(float));
    printf("sizeof(double): %zu byte(s)\n", sizeof(double));
    printf("sizeof(pointer): %zu byte(s)\n", sizeof(void*));
    
    // Run all demonstrations
    demonstrate_integer_types();
    demonstrate_character_type();
    demonstrate_floating_point_types();
    demonstrate_type_conversions();
    demonstrate_constants_and_literals();
    demonstrate_scope_and_storage();
    demonstrate_formatting();
    
    // Interactive portion
    printf("\n\nWould you like to try the interactive demo? (1=yes, 0=no): ");
    int choice;
    if (scanf("%d", &choice) == 1 && choice == 1) {
        interactive_demo();
    }
    
    // Summary
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                        SUMMARY                             ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("You've learned about:\n");
    printf("✓ Integer types (char, short, int, long, long long)\n");
    printf("✓ Floating-point types (float, double, long double)\n");
    printf("✓ Character type and ASCII values\n");
    printf("✓ Signed vs unsigned types\n");
    printf("✓ Type conversions and casting\n");
    printf("✓ Constants vs variables\n");
    printf("✓ Variable scope and storage classes\n");
    printf("✓ Format specifiers and output formatting\n");
    
    printf("\nNext steps:\n");
    printf("• Study operators and expressions\n");
    printf("• Learn about control structures (if, loops)\n");
    printf("• Practice with arrays and strings\n");
    printf("• Explore functions and parameter passing\n");
    
    printf("\n🎉 Congratulations! You've completed the Variables & Data Types demo!\n");
    
    return 0;
}

/*
 * Compilation instructions:
 * ========================
 * 
 * Basic compilation:
 * gcc variables_demo.c -o variables_demo
 * 
 * With warnings and C11 standard:
 * gcc -std=c11 -Wall -Wextra variables_demo.c -o variables_demo
 * 
 * With debugging information:
 * gcc -std=c11 -Wall -Wextra -g variables_demo.c -o variables_demo
 * 
 * For maximum compatibility (C99):
 * gcc -std=c99 -Wall variables_demo.c -o variables_demo
 * 
 * Running the program:
 * ./variables_demo    (Linux/macOS)
 * variables_demo.exe  (Windows)
 */
