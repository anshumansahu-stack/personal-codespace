#include <iostream>
using namespace std;
void numprint(int n)
{
    if (n < 1)
        return;
    cout << n << endl;
    numprint(n - 1);
}
int main()
{
    int N;
    cout << "Enter a number:" << endl;
    cin >> N;
    numprint(N);
    return 0;
}
