#include <iostream>
using namespace std;
// Write a program that:

// Takes n integers as input using dynamic memory (new)

// Finds the sum of only even numbers

// Frees memory using delete[]
int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    int *arr = new int[n]; // Dynamic allocation
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } // Array Input taken
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum = sum + arr[i];
        }
    } // Even sum calculated
    cout << "The sum of all even integers is " << sum << endl;
    delete[] arr; // deletes the allocated memory
    return 0;
}