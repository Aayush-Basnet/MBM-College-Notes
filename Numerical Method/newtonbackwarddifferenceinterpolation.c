#include<stdio.h>
#define MAXN 100
#define ORDER 4

void main() {
    float ax[MAXN+1], ay[MAXN+1], diff[MAXN+1][ORDER+1], nr=1.0, dr=1.0, x, p, h, yp;
    int n, i, j, k;

    printf("\t\t\t Newton's Backward Difference Interpolation \n");
    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    printf("\nEnter the values in the form x, y:\n");
    for (i = 0; i <= n; i++)
        scanf("%f %f", &ax[i], &ay[i]);

    printf("\nEnter the value of x for which the value of y is wanted: ");
    scanf("%f", &x);

    h = ax[1] - ax[0];

    // Calculate the 1st order of differences
    for (i = n; i >= 1; i--)
        diff[i][1] = ay[i] - ay[i-1];

    // Calculate the second and higher order differences
    for (j = 2; j <= ORDER; j++)
        for (i = n; i >= j; i--)
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];

    // Finding x0
    i = n;
    while (!(ax[i] < x))
        i--;

    // Now ax[i] is x0 and ay[i] is y0
    p = (x - ax[i]) / h;
    yp = ay[i];

    // Perform interpolation
    for (k = 1; k <= ORDER; k++) {
        nr *= p + k - 1;
        dr *= k;
        yp += (nr / dr) * diff[i][k];
    }

    printf("\nWhen x = %.4f, corresponding y = %.3f\n", x, yp);
}

