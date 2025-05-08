#include <stdio.h>
#include <string.h>

int main() {
    char str[100], substr[100];
    int i, j, found;

    // Input the main string
    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Input the substring to search
    printf("Enter the substring to search: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0';

    int strLen = strlen(str);
    int subLen = strlen(substr);

    for (i = 0; i <= strLen - subLen; i++) {
        found = 1;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != substr[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            printf("Substring found at index %d\n", i);
            return 0;
        }
    }

    printf("Substring not found.\n");
    return 0;
}
