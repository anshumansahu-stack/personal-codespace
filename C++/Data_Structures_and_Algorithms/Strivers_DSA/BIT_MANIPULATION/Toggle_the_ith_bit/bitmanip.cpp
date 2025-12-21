#include <iostream>
using namespace std;
// Set the ith bit
int main()
{
    int i, n;
    cout << "Enter the number:" << endl;
    cin >> n;
    cout << "Enter the bit to toggled" << endl;
    cin >> i;
    cout << "Bit toggled. Number= " << (n ^ (1 << i)) << endl;
    return 0;
}