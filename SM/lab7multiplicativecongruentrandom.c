/*
WAP in C to generate 100 random numbers
using Multiplicative Congruential Method where
X0=13, m =1000, a = 15 and c = 7.
*/
#include <stdio.h>

int main() {
 
    int X0 = 13; // Seed
    int a = 15;  // Multiplier
    int c = 7;   // Increment
    int m = 1000; // Modulus
    int n = 100;  // Number of random numbers to generate
    int random_numbers[n],i;

    
    random_numbers[0] = X0; 
    for (i = 1; i < n; i++) {
        random_numbers[i] = (a * random_numbers[i - 1] + c) % m;
    }

    
    printf("Generated Random Numbers:\n");
    for ( i = 0; i < n; i++) {
        printf("%d ", random_numbers[i]);
        if ((i + 1) % 10 == 0) { 
            printf("\n");
        }
    }

    return 0;
}

