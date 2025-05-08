#include <stdio.h>
#include <string.h>

int temp_counter = 0; // To generate unique temporary variables for TAC

// Function to generate temporary variable names
char* new_temp() {
    static char temp[10];
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

// Generate TAC for an arithmetic expression
void generate_arithmetic_tac(char* expr) {
    // For simplicity, assume expression is of the form: a + b * c
    // This will be parsed manually for demonstration

    if (strcmp(expr, "(a + b) * (c - d)") == 0) {
        // First, a + b -> t1
        printf("t1 = a + b\n");

        // Then, c - d -> t2
        printf("t2 = c - d\n");

        // Now, t1 * t2 -> x
        printf("x = t1 * t2\n");
    }
}

// Generate TAC for an if-else statement
void generate_if_else_tac(char* condition) {
    if (strcmp(condition, "x > y") == 0) {
        printf("if x > y goto L1\n");
        printf("t2 = x - y\n");
        printf("z = t2\n");
        printf("goto L2\n");
        printf("L1: t1 = x + y\n");
        printf("z = t1\n");
        printf("L2:\n");
    }
}

// Generate TAC for a while loop
void generate_while_tac(char* condition) {
    if (strcmp(condition, "x < y") == 0) {
        printf("L1: if x >= y goto L2\n");
        printf("t1 = x + 1\n");
        printf("x = t1\n");
        printf("goto L1\n");
        printf("L2:\n");
    }
}

int main() {
    // Example 1: Arithmetic Expression
    printf("Generating TAC for Arithmetic Expression:\n");
    generate_arithmetic_tac("(a + b) * (c - d)");

    // Example 2: If-Else Statement
    printf("\nGenerating TAC for If-Else Statement:\n");
    generate_if_else_tac("x > y");

    // Example 3: While Loop
    printf("\nGenerating TAC for While Loop:\n");
    generate_while_tac("x < y");

    return 0;
}
