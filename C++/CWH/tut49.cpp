#include <iostream>
using namespace std;
// INITIALISATION LISTS IN CONSTRUCTORS IN C++
//  Initialisation section is used to Initialise values in C++.
//  It has the following Syntax:
//  Constructor(argument-list): initialisation section{ code }
class Test
{
    int i, j;

public:
    // Test(int a, int b) : i(a), j(b)
    // Test(int a, int b) : i(a), j(a+b)
    // Test(int a, int b) : i(a), j(i + b)
    // Test(int a, int b) : j(a), i(j + b)// This code will give Garbage Value.
    // Since the declaration order is i first then j(Line 9) So declaring j first in Constructor assigns a garbage value to i.
    // The initialisation and declaration orders must be the same.

    Test(int a, int b) : i(a), j(2 * b)
    {
        cout << "Test constructor executed!" << endl;
        cout << "The value of a is: " << i << endl;
        cout << "The value of b is: " << j << endl;
    }
};
int main()
{
    Test t(4, 6);
    return 0;
}