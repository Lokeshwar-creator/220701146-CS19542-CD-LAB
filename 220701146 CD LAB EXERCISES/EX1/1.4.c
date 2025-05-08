#include <stdio.h>

int main() {
    char str[100], noSpaceStr[100];
    int i, j = 0;

    // Input the string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Loop to copy only non-space characters
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            noSpaceStr[j++] = str[i];
        }
    }

    // Null-terminate the new string
    noSpaceStr[j] = '\0';

    // Output the result
    printf("String without spaces: %s\n", noSpaceStr);

    return 0;
}
