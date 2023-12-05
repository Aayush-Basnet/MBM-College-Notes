#include <iostream>
#include <vector>
using namespace std;

int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}
int main() {
    int arr[] = {4, 10, 5, 8, 1, 8,6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    vector<int> vecArr(arr, arr + arrSize);
    int target = 1;
    int result = sequentialSearch(vecArr, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

