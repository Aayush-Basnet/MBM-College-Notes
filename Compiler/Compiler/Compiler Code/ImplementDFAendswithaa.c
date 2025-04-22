#include <stdio.h>
#include <string.h>


enum State { q0, q1, q2 };

int main() {
    char input[100];
    enum State currentState = q0;
    int i;

    printf("Enter a string (consisting of only 'a' and 'b'): ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        char symbol = input[i];

        switch (currentState) {
            case q0:
                if (symbol == 'a')
                    currentState = q1;
                else if (symbol == 'b')
                    currentState = q0;
                else {
                    printf("Invalid character: %c\n", symbol);
                    return 1;
                }
                break;

            case q1:
                if (symbol == 'a')
                    currentState = q1;
                else if (symbol == 'b')
                    currentState = q2;
                else {
                    printf("Invalid character: %c\n", symbol);
                    return 1;
                }
                break;

            case q2:
                if (symbol == 'a')
                    currentState = q1;
                else if (symbol == 'b')
                    currentState = q0;
                else {
                    printf("Invalid character: %c\n", symbol);
                    return 1;
                }
                break;
        }
    }

    if (currentState == q2)
        printf("\nThe string is accepted (ends with 'ab').\n");
    else
        printf("\nThe string is rejected (does not end with 'ab').\n");

    return 0;
}

