#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// check if string matches a*
bool isAStar(char str[]) {
	int i;
    for (i = 0; str[i]; i++) {
        if (str[i] != 'a')
            return false;
    }
    return true;
}

// check if string matches a*b+
bool isAStarBPlus(char str[]) {
    int i = 0;
   
    while (str[i] == 'a') i++;

    int bCount = 0;
   
    while (str[i] == 'b') {
        bCount++;
        i++;
    }

    return (str[i] == '\0' && bCount >= 1);
}

// check if string is exactly "abb"
bool isExactlyAbb(char str[]) {
    return (strcmp(str, "abb") == 0);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    bool matchAStar = isAStar(input);
    bool matchAStarBPlus = isAStarBPlus(input);
    bool matchExactlyAbb = isExactlyAbb(input);

    printf("\nResult:\n");
    if (matchAStar)
        printf("\nMatches a*\n");
    if (matchAStarBPlus)
        printf("\nMatches a*b+\n");
    if (matchExactlyAbb)
        printf("\nMatches abb\n");
    if (!matchAStar && !matchAStarBPlus && !matchExactlyAbb)
        printf("\nDoes not match any of the given patterns.\n");

    return 0;
}

