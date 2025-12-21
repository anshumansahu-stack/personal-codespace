#include <iostream>
#include <vector>
using namespace std;
//Submitted
int reverse(int n)
{
    int reverse = 0, initial = n;
    while (initial > 0)
    {
        int i = initial % 10;
        reverse += i;
        reverse *= 10;
        initial /= 10;
    }
    return reverse / 10;
}
int mirrorDistance(int n)
{
    int x = n - reverse(n);
    if (x < 0)
    {
        return -x;
    }
    return x;
} // ©leetcode
int main()
{
    int N;
    cout << "Enter the number:" << endl;
    cin >> N;
    cout << mirrorDistance(N) << endl;
}