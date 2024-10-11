#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 500

void encrypt() {
    char text[MAX_SIZE], ch;
    int key, i;

    // taking user input
    printf("Enter a message to encrypt: ");
    scanf("%s", text);
    
    printf("Enter the key: ");
    scanf("%d", &key);

    // visiting character by character
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // check for valid character
        if (isalnum(ch)) {
            // lower case characters
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            // uppercase characters
            else if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
            // numbers
            else if (isdigit(ch)) {
                ch = (ch - '0' + key) % 10 + '0';
            }
        }
        // invalid character
        else {
            printf("Invalid Message");
            return;
        }

        // adding encoded answer
        text[i] = ch;
    }

    printf("Encrypted message: %s\n", text);
}

void decrypt() {
    char text[MAX_SIZE], ch;
    int key, i;

    // taking user input
    printf("\n\n\nEnter a message to decrypt: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%d", &key);

    //visiting each character
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // check for valid characters
        if (isalnum(ch)) {
            // lower case characters
            if (islower(ch)) {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }
            // uppercase characters
            else if (isupper(ch)) {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }
            // numbers
            else if (isdigit(ch)) {
                ch = (ch - '0' - key + 10) % 10 + '0';
            }
        }
        // invalid characters
        else {
            printf("Invalid Message");
            return;
        }

        // adding decoded character back
        text[i] = ch;
    }

    printf("Decrypted message: %s\n", text);
}

int main() {
    encrypt();
    decrypt();

    return 0; // Indicates successful execution
}
