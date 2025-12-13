#include <iostream>
#include <climits>
#include <vector>
using namespace std;
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
    int max_res = INT_MIN, cum_sum = 0;
    for (int i = 2; i <= n && cum_sum < n; i++)
    {
        if (isPrime(i))
        {
            cum_sum += i;
            // cout << i << " added to cum_sum, cum_sum=" << cum_sum << endl;
        }
        if (isPrime(cum_sum) && cum_sum <= n)
        {
            max_res = max(max_res, cum_sum);
            // cout << "max_res updated to " << max_res << endl;
        }
    }
    if (max_res == INT_MIN)
        return 0;
    else
    {
        for (int i = 2; i < max_res; i++)
        {
            int sum = 0;
            if (isPrime(i) && sum != max_res)
            {
                if (sum > max_res)
                {
                    break;
                }
                cout << i << " ";
                sum += i;
                cout << "sum is " << sum << endl;
            }
        }
        cout << endl;
        return max_res;
    }
} // O(n)
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