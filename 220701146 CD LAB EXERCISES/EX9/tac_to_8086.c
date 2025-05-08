#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTERS 4  // We will use 4 registers: AX, BX, CX, DX

// Map to store temporary variables (t0, t1, etc.) and their corresponding registers
char *registers[MAX_REGISTERS] = {"AX", "BX", "CX", "DX"};
int register_counter = 0;

// Function to get a free register for the temporary variable
char* get_register() {
    if (register_counter < MAX_REGISTERS) {
        return registers[register_counter++];
    } else {
        printf("Error: Not enough registers!\n");
        exit(1);
    }
}

// Function to generate the 8086 assembly code for the given TAC instruction
void generate_assembly(char* tac_instr) {
    char op[10], t1[10], t2[10], result[10];
    char* reg1;
    char* reg2;
    char* reg_result;

    // Example: t0 = t1 + t2
    // Parse the instruction: "t0 = t1 + t2"
    sscanf(tac_instr, "%s = %s %s %s", result, t1, op, t2);

    // Get registers for temporary variables
    reg1 = get_register();
    reg2 = get_register();
    reg_result = get_register();

    // Generate Assembly for each operation
    if (strcmp(op, "+") == 0) {
        // t0 = t1 + t2
        printf("MOV %s, %s\n", reg1, t1);         // MOV AX, t1
        printf("ADD %s, %s\n", reg1, t2);         // ADD AX, t2
        printf("MOV %s, %s\n", reg_result, reg1); // MOV t0, AX
    }
    else if (strcmp(op, "-") == 0) {
        // t0 = t1 - t2
        printf("MOV %s, %s\n", reg1, t1);         // MOV AX, t1
        printf("SUB %s, %s\n", reg1, t2);         // SUB AX, t2
        printf("MOV %s, %s\n", reg_result, reg1); // MOV t0, AX
    }
    else if (strcmp(op, "*") == 0) {
        // t0 = t1 * t2
        printf("MOV %s, %s\n", reg1, t1);         // MOV AX, t1
        printf("MOV %s, %s\n", reg2, t2);         // MOV BX, t2
        printf("IMUL %s\n", reg2);                // IMUL BX
        printf("MOV %s, AX\n", reg_result);       // MOV t0, AX
    }
    else if (strcmp(op, "/") == 0) {
        // t0 = t1 / t2
        printf("MOV %s, %s\n", reg1, t1);         // MOV AX, t1
        printf("MOV %s, %s\n", reg2, t2);         // MOV BX, t2
        printf("DIV %s\n", reg2);                 // DIV BX
        printf("MOV %s, AX\n", reg_result);       // MOV t0, AX (quotient)
    }
    else {
        printf("Unsupported operation: %s\n", op);
        exit(1);
    }
}

int main() {
    // Example Three Address Code Instructions
    char *tac_instructions[] = {
        "t0 = t1 + t2",
        "t1 = t3 - t4",
        "t2 = t5 * t6",
        "t3 = t7 / t8",
    };

    printf("Generating 8086 Assembly Code:\n\n");

    // Iterate through TAC instructions and generate assembly code
    for (int i = 0; i < 4; i++) {
        generate_assembly(tac_instructions[i]);
    }

    return 0;
}
