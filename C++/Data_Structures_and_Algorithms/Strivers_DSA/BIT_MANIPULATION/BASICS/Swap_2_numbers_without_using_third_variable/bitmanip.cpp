#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter two numbers " << endl;
    cin >> a >> b;
    cout << "The value of a was " << a << endl;
    cout << "The value of b was " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;// Successfully swapped
    return 0;
}