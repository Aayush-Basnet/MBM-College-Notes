#include <stdio.h>
#include <string.h>

int main() {
    char str[10];

    printf("Enter your string: ");
    scanf("%s", str);

    if (strcmp(str, "aababaa") == 0) {
        printf("String accepted");
    } else {
        printf("String rejected");
    }

    return 0;
}

