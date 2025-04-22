#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char state[3];
bool flag;
int i;
bool dfaEndingWithab(const char* checkString) {
    strcpy(state, "q0");
    int length = strlen(checkString);

    for (i = 0; i < length; i++) {
        if (checkString[i] == 'a' && strcmp(state, "q0") == 0)
            strcpy(state, "q1");
        if (checkString[i] == 'b' && strcmp(state, "q0") == 0)
            strcpy(state, "q0");
        if (checkString[i] == 'a' && strcmp(state, "q1") == 0)
            strcpy(state, "q1");
        if (checkString[i] == 'b' && strcmp(state, "q1") == 0 && i == (length - 1))
            flag = true;
        if (checkString[i] == 'b' && strcmp(state, "q1") == 0)
            strcpy(state, "q2");
        if (checkString[i] == 'a' && strcmp(state, "q2") == 0)
            strcpy(state, "q1");
        if (checkString[i] == 'b' && strcmp(state, "q2") == 0)
            strcpy(state, "q0");
        else
            flag = false;
    }
    return flag;
}

int main() {
    const char* checkString = "bbbabbbbab";
    dfaEndingWithab(checkString);
    if (flag == true)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

