#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0};  // Initialize all elements to 0

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];  // Use unsigned to handle all ASCII values
        freq[ch]++;
    }

    // Display the frequencies
    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && i != '\n') {  // Ignore newline character
            printf("'%c' = %d\n", i, freq[i]);
        }
    }

    return 0;
}
