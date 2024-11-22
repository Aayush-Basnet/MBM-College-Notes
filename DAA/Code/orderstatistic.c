#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1,j;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

   
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex > k - 1) {
            return quickselect(arr, low, pivotIndex - 1, k);
        } else {
            return quickselect(arr, pivotIndex + 1, high, k);
        }
    }
    return -1;
}

int main() {
    int n, k,i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = quickselect(arr, 0, n - 1, k);
    if (result != -1) {
        printf("The %d-th smallest element is: %d\n", k, result);
    } else {
        printf("Invalid value of k\n");
    }

    return 0;
}

