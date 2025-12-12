#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//TLE
bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
} // O(sqrt(n))
int largestPrime(int n)
{
    int max_res = INT_MIN;
    for (int i = 2; i <= n; i++)
    {
        int res = 0;
        // cout << "Iter for " << i << endl;
        for (int j = 2; j <= i && res < i; j++)
        {
            if (isPrime(j))
            {
                res += j;
                // cout << "added " << j << " to res, res=" << res << endl;
            }
            if (isPrime(res) && res == i)
            {
                max_res = max(max_res, res);
                // cout << "Updated max_res, max_res=" << max_res << endl;
            }
        }
    }
    return max_res;
} // O(n^2)
int main()
{
    int N;
    cout << "Enter the number:" << endl;
    cin >> N;
    // if (isPrime(N))
    // {
    //     cout << "Prime" << endl;
    // }
    // else
    // {
    //     cout << "Not Prime" << endl;
    // }
    cout << "The required Largest Prime is: " << largestPrime(N) << endl;
    return 0;
}