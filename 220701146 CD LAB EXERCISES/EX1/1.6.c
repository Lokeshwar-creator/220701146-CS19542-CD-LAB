#include <stdio.h>
#include <string.h>

int main() {
    char str1[200], str2[100];

    // Input first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline

    // Input second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline

    // Concatenate str2 to str1
    strcat(str1, str2);

    // Output the concatenated result
    printf("Concatenated string: %s\n", str1);

    return 0;
}
