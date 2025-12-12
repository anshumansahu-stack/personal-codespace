#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter the number " << endl;
    cin >> n;
    cout << "Enter the number i" << endl;
    cin >> i;
    if (n & (1 << i) != 0)//Left shift Operator
    {
        cout << "The " << i << "th bit is set" << endl;
    }
    else
    {
        cout << "The " << i << "th bit is not set" << endl;
    }
    return 0;
}