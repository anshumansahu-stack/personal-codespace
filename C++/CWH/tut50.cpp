#include <iostream>
using namespace std;
// Pointers Revisit
int main()
{
    // Basic Example
    int a = 4;
    int *ptr = &a; // Address stored
    cout << "The value of a is " << *(ptr) << endl;

    // new operator
    int *p = new int(40);         // p stores the address of a variable whose value is 40
    float *q = new float(78.123); // q stores the address of a variable whose value is 78.123
    cout << "The value at address p is " << *(p) << endl;
    cout << "The value at address q is " << *(q) << endl;
    // Any class object can also be used.
    delete p;
    delete q;

    // Dynamic allocation of arrays
    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;
    // Strange thing this didnt require dereferencing as other variables. Explain?
    // Access via indexing (no need for dereferencing because arr[i] is just syntactic sugar for *(arr + i)).
    delete[] arr; // Dynamically allocated block freed

    // Why is freeing up dynamically allocated space a good habit in C++? What happens if i dont?
    // Heap memory stays until explicitly released.
    // Not freeing = memory leak.
    // In small programs it may not show up. But in long-lived or loop-heavy systems → leads to crashes or performance drops.
    return 0;
}