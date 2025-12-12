#include <iostream>
using namespace std;
void numprint(int n, int N)
{
    if (n > N)
        return;
    cout << n << endl;
    numprint(n + 1, N);
}
int main()
{
    int N;
    cout << "Enter a number:" << endl;
    cin >> N;
    numprint(1, N);
    return 0;
}
