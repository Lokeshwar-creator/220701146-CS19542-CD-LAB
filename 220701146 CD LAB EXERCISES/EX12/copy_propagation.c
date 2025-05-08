#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char result[10];
    char arg1[10];
    char op[5];
    char arg2[10];
} TAC;

TAC code[MAX];
int n;

void perform_copy_propagation() {
    for (int i = 0; i < n; i++) {
        // Check if it's a copy statement: tX = tY;
        if (strcmp(code[i].op, "=") == 0 && strlen(code[i].arg2) == 0) {
            char copy_var[10];
            strcpy(copy_var, code[i].arg1);
            char target_var[10];
            strcpy(target_var, code[i].result);

            // Replace future uses of target_var with copy_var
            for (int j = i + 1; j < n; j++) {
                if (strcmp(code[j].arg1, target_var) == 0)
                    strcpy(code[j].arg1, copy_var);
                if (strcmp(code[j].arg2, target_var) == 0)
                    strcpy(code[j].arg2, copy_var);
            }
        }
    }

    // Now remove the redundant copy statements (optional)
    printf("\nOptimized TAC after Copy Propagation:\n");
    for (int i = 0; i < n; i++) {
        // Skip copy statements where result is unused later
        if (strcmp(code[i].op, "=") == 0 && strlen(code[i].arg2) == 0) {
            int used = 0;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(code[j].arg1, code[i].result) == 0 ||
                    strcmp(code[j].arg2, code[i].result) == 0) {
                    used = 1;
                    break;
                }
            }
            if (!used) continue; // Remove dead copy
        }

        // Print optimized instruction
        if (strlen(code[i].arg2) > 0)
            printf("%s = %s %s %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
        else
            printf("%s = %s\n", code[i].result, code[i].arg1);
    }
}

int main() {
    // Example: 4 TAC instructions
    n = 4;

    strcpy(code[0].result, "t1"); strcpy(code[0].arg1, "a"); strcpy(code[0].op, "="); strcpy(code[0].arg2, "");
    strcpy(code[1].result, "t2"); strcpy(code[1].arg1, "t1"); strcpy(code[1].op, "="); strcpy(code[1].arg2, "");
    strcpy(code[2].result, "t3"); strcpy(code[2].arg1, "t2"); strcpy(code[2].op, "+"); strcpy(code[2].arg2, "b");
    strcpy(code[3].result, "t4"); strcpy(code[3].arg1, "t3"); strcpy(code[3].op, "*"); strcpy(code[3].arg2, "c");

    printf("Original TAC:\n");
    for (int i = 0; i < n; i++) {
        if (strlen(code[i].arg2) > 0)
            printf("%s = %s %s %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
        else
            printf("%s = %s\n", code[i].result, code[i].arg1);
    }

    perform_copy_propagation();

    return 0;
}
