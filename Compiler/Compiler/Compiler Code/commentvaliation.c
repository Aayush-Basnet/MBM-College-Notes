#include <stdio.h>
#include <string.h>

// Function to check if the string is a valid comment
void validateComment(char str[]) {
    int len = strlen(str);

    // Check for single-line comment
    if (str[0] == '/' && str[1] == '/') {
        printf("\nThis is a valid single-line comment.\n");
    }
    // Check for multi-line comment
    else if (str[0] == '/' && str[1] == '*') {
        if (str[len - 2] == '*' && str[len - 1] == '/') {
            printf("\nThis is a valid multi-line comment.\n");
        } else {
            printf("\nInvalid multi-line comment. Missing closing '*/'.\n");
        }
    } else {
        printf("\nNot a valid comment.\n");
    }
}

int main() {
    char input[100];

    printf("Enter a comment: ");
    fgets(input, sizeof(input), stdin);

    validateComment(input);

    return 0;
}

