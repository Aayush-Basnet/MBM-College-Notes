#include <stdio.h>

struct Item {
    int value, weight;
};

void fractionalKnapsack(struct Item items[], int n, int capacity) {
    
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    double totalValue = 0.0;
    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
          
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int n,i, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter value and weight of each item:\n");
    for ( i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);
    return 0;
}

