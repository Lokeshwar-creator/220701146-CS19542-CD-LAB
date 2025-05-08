#include <stdio.h>

int main() {
    char str[100], oldChar, newChar;

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Input character to be replaced
    printf("Enter the character to replace: ");
    scanf(" %c", &oldChar);  // Notice the space before %c to consume newline

    // Input replacement character
    printf("Enter the new character: ");
    scanf(" %c", &newChar);

    // Replace occurrences
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }

    // Output the modified string
    printf("Modified string: %s", str);

    return 0;
}
