/*
In a single pump service station, vehicles arrive for fuelling
with an average of 5 minutes between arrivals. If an hour is
taken as unit of time, cars arrive according to Poison’s
process with an average of
?= 12 cars/hr.
Write a C program to generate Poisson distribution for x =
0,1,2, .... 15.
*/
#include <stdio.h>
#include <math.h>

// Function to calculate factorial
float factorial(int n) {
    float fact = 1,i;
    for ( i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    float lambda = 12; // Arrival rate (?) = 12 cars/hour
    float pr;          // Probability
    int x;

    printf("Poisson Distribution for ? = %.2f cars/hour:\n", lambda);
    printf("-------------------------------------------\n");

    // Generate Poisson probabilities for x = 0, 1, 2, ..., 15
    for (x = 0; x <= 15; x++) {
        pr = (exp(-lambda) * pow(lambda, x)) / factorial(x);
        printf("P(X = %2d) = %.6f\n", x, pr);
    }

    return 0;
}

