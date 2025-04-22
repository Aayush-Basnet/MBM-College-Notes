#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

// Predictive Parsing Table for the above grammar
const char* table[5][6] = {
    /*          id        +         *         (         )         $   */
    /*E*/   { "TE'",   "",       "",      "TE'",   "",       "" },
    /*E'*/  { "",      "+TE'",   "",      "",      "e",     "e" },
    /*T*/   { "FT'",   "",       "",      "FT'",   "",       "" },
    /*T'*/  { "",      "e",      "*FT'",  "",      "e",     "e" },
    /*F*/   { "id",    "",       "",      "(E)",   "",       "" }
};

int getRow(char nonTerminal) {
    switch(nonTerminal) {
        case 'E': return 0;
        case 'X': return 1; // E'
        case 'T': return 2;
        case 'Y': return 3; // T'
        case 'F': return 4;
        default: return -1;
    }
}

int getCol(char terminal) {
    switch(terminal) {
        case 'i': return 0; // id starts with i
        case '+': return 1;
        case '*': return 2;
        case '(': return 3;
        case ')': return 4;
        case '$': return 5;
        default: return -1;
    }
}

void parse(const char* input) {
    push('$');
    push('E'); // Start symbol

    int ip = 0;
    char symbol;

    printf("Stack\t\tInput\t\tAction\n");
    printf("-----\t\t-----\t\t------\n");

    while (1) {
        symbol = peek();
        char curr = input[ip];
		int i;
        // Display stack and input
        for ( i = 0; i <= top; i++) printf("%c", stack[i]);
        printf("\t\t%s\t\t", input + ip);

        // If both match and it's terminal
        if (symbol == curr && symbol == '$') {
            printf("Accepted!\n");
            break;
        }
        else if (!isupper(symbol)) {
            if (symbol == 'i' && curr == 'i') {
                pop();
                ip++;
                printf("Match id\n");
            } else if (symbol == curr) {
                pop();
                ip++;
                printf("Match %c\n", curr);
            } else {
                printf("Error: Unexpected symbol %c\n", curr);
                break;
            }
        }
        else {
            int row = getRow(symbol == 'E' ? 'E' : symbol);
            int col = getCol(curr);

            const char* prod = table[row][col];

            if (prod == NULL || strcmp(prod, "") == 0) {
                printf("Error: No rule\n");
                break;
            }

            printf("%c -> %s\n", symbol, prod);

            pop();
            if (strcmp(prod, "e") != 0) {
                int len = strlen(prod);
                int i;
                for ( i = len - 1; i >= 0; i--) {
                    push(prod[i]);
                }
            }
        }
    }
}

int main() {
    char input[100];

    printf("Enter input string (use 'i' for id), end with $: ");
    scanf("%s", input);

    parse(input);

    return 0;
}

