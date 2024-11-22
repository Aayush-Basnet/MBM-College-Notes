#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

       
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
   
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

  
    for (i = n - 1; i > 0; i--) {
      
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

