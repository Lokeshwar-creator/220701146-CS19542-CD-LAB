#include <stdio.h>
#include <ctype.h>  // for toupper

int main() {
    char str[100];

    // Ask the user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read input including spaces

    // Convert each character to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    // Display the result
    printf("Uppercase: %s", str);

    return 0;
}
