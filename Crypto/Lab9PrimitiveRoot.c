#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


bool isPrime(int n) {
	int i;

    if (n <= 1) return false;
    if (n <= 3) return true;

  
    if (n%2 == 0 || n%3 == 0) return false;

    for (i = 5; i <= sqrt(n); i = i + 6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}


int power(int x, unsigned int y, int p) {
    int res = 1;    

    x = x % p; 

    while (y > 0) {
       
        if (y & 1)
            res = (res*x) % p;

     
        y = y >> 1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


void findPrimefactors(int* s, int* size, int n) {
	int i;
    
    while (n % 2 == 0) {
        s[(*size)++] = 2;
        n = n / 2;
    }

    
    for (i = 3; i <= sqrt(n); i = i + 2) {
    
        while (n % i == 0) {
            s[(*size)++] = i;
            n = n / i;
        }
    }

   
    if (n > 2)
        s[(*size)++] = n;
}


int findPrimitive(int n) {
	int r,i;
    int s[20];
    int size = 0;

    // Check if n is prime or not
    if (!isPrime(n)) return -1;


    int phi = n - 1;

    // Find prime factors of phi and store in an array
    findPrimefactors(s, &size, phi);

    // Check for every number from 2 to phi
    for (r = 2; r <= phi; r++) {
      
		bool flag = false;
		for (i = 0; i < size; i++) {
			
			if (power(r, phi / s[i], n) == 1) {
			flag = true;
			break;
			}
		}
   		// If there was no power with value 1.
		if (flag == false)
        	return r;
	}
// If no primitive root found
	return -1;
}

int main() {
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	printf(" Smallest primitive root of %d is %d\n", n, findPrimitive(n));
	return 0;
}
