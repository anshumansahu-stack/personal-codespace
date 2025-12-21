#include <iostream>
using namespace std;
// Set the ith bit
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    if ((n & (n - 1)) == 0)
    {
        cout << "The number is a pure power of 2" << endl;
    }
    else
    {
        cout << "The number is not a pure power of 2" << endl;
    }
    return 0;
}