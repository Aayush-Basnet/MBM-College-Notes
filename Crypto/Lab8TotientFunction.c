#include <stdio.h> 
//gcd calculation
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
// Totient Function 
int phi(unsigned int n) 
{ 
	int i;
    unsigned int result = 1; 
    for (i = 2; i < n; i++) 
        if (gcd(i, n) == 1) 
            result++; 
    return result; 
} 
int main() 
{ 
    int n; 
    printf("Enter the number:");
	scanf("%d",&n);
    printf("phi(%d) = %d\n", n, phi(n)); 
    return 0; 
} 
