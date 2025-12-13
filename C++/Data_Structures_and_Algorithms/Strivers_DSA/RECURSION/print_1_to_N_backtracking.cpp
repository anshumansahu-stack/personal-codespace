#include <iostream>
using namespace std;
void numprint(int n, int N)
{
    if (n < 1)
        return;
    numprint(n - 1, N);
    cout << n << endl;
}
int main()
{
    int N;
    cout << "Enter a number:" << endl;
    cin >> N;
    numprint(N, N);
    return 0;
}
