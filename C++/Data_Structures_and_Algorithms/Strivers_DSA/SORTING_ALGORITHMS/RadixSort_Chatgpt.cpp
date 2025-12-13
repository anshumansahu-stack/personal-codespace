#include <iostream>

using namespace std;

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// A function to perform counting sort based on the digit represented by exp (10^0, 10^1, etc.)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array to store sorted elements
    int count[10] = {0}; // There are only 10 possible digits (0-9)
    
    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that it now contains actual positions of digits in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to do Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit. The exp is 10^i, where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    
    // Prompt the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    
    // Take array input from the user
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Perform Radix Sort
    radixSort(arr, n);
    
    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

