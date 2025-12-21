#include <iostream>
using namespace std;
// Set the ith bit
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int count = 0;
    while (n != 0)
    {
        n = (n & (n - 1));
        count++;
    }
    cout << count << endl;
    return 0;
}