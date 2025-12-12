#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void randGen(int arr[], int n) {
    // Seed the random number generator with the current time
    srand(time(0));

    // Fill the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n]; // Declare an array of size n
    
    // Generate random numbers and store them in the array
    randGen(arr, n);
    
    // Print the random numbers
    cout << "Random numbers: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

