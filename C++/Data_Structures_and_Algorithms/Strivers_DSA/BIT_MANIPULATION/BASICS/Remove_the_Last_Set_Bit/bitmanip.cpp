#include <iostream>
using namespace std;
// Set the ith bit
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    cout << "Last Bit removed. Number= " << (n & (n - 1)) << endl;
    return 0;
}