#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INSTRUCTIONS 100

// A structure to hold the TAC instruction
typedef struct {
    char result[10]; // result variable (t0, t1, etc.)
    char op[10];     // operation (+, -, *, /)
    char arg1[10];   // first argument (e.g., a, b, t0)
    char arg2[10];   // second argument (e.g., b, t0, t1)
} TACInstruction;

// Arrays to store TAC instructions and tracked variables/expressions
TACInstruction tac[MAX_INSTRUCTIONS];
int tac_count = 0;
char used_variables[MAX_INSTRUCTIONS][10];
int used_count = 0;

// Function to check if a variable is used
int is_variable_used(char* var) {
    for (int i = 0; i < used_count; i++) {
        if (strcmp(used_variables[i], var) == 0) {
            return 1; // Variable is used
        }
    }
    return 0; // Variable is not used
}

// Function to add a variable to the used list
void mark_variable_as_used(char* var) {
    strcpy(used_variables[used_count++], var);
}

// Function to generate new temporary variables
char* new_temp(int index) {
    static char temp[10];
    sprintf(temp, "t%d", index);
    return temp;
}

// Function to perform Dead Code Elimination (DCE)
void eliminate_dead_code() {
    // Keep track of used variables
    for (int i = 0; i < tac_count; i++) {
        if (is_variable_used(tac[i].result) == 0) {
            printf("Dead code found: %s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
        } else {
            printf("%s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
        }
    }
}

// Function to perform Common Subexpression Elimination (CSE)
void eliminate_common_subexpressions() {
    char expressions[MAX_INSTRUCTIONS][30]; // Store unique expressions
    int expression_count = 0;

    for (int i = 0; i < tac_count; i++) {
        // Check if expression exists in the list
        int found = 0;
        for (int j = 0; j < expression_count; j++) {
            if (strcmp(expressions[j], tac[i].arg1) == 0 && strcmp(expressions[j], tac[i].arg2) == 0) {
                // Replace with previous result
                printf("%s = %s %s %s\n", tac[i].result, expressions[j], tac[i].op, tac[i].arg2);
                found = 1;
                break;
            }
        }

        // If not found, add to the list of expressions
        if (!found) {
            strcpy(expressions[expression_count++], tac[i].arg1);
            printf("%s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
        }
    }
}

int main() {
    // Sample TAC instructions with common subexpressions and dead code
    strcpy(tac[0].result, "t1");
    strcpy(tac[0].op, "+");
    strcpy(tac[0].arg1, "a");
    strcpy(tac[0].arg2, "b");

    strcpy(tac[1].result, "t2");
    strcpy(tac[1].op, "+");
    strcpy(tac[1].arg1, "c");
    strcpy(tac[1].arg2, "d");

    strcpy(tac[2].result, "t3");
    strcpy(tac[2].op, "*");
    strcpy(tac[2].arg1, "t1");
    strcpy(tac[2].arg2, "t2");

    strcpy(tac[3].result, "t4");
    strcpy(tac[3].op, "+");
    strcpy(tac[3].arg1, "t1");  // Common expression: t1 is computed twice
    strcpy(tac[3].arg2, "t2");

    strcpy(tac[4].result, "x");
    strcpy(tac[4].op, "=");
    strcpy(tac[4].arg1, "t3");
    strcpy(tac[4].arg2, ""); // Dead code: t4 is never used

    tac_count = 5; // Number of TAC instructions

    // Perform Dead Code Elimination
    printf("Dead Code Elimination:\n");
    eliminate_dead_code();

    // Perform Common Subexpression Elimination
    printf("\nCommon Subexpression Elimination:\n");
    eliminate_common_subexpressions();

    return 0;
}
