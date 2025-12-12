// What is the largest prime factor of a given number N ?
#include <iostream>
using namespace std;

// BRUTEFORCE
// bool is_prime(int n)
// {
//     if (n <= 1)
//         return false;
//     if (n == 2)
//         return true;
//     if (n % 2 == 0)
//         return false;
//     for (int i = 3; i * i <= n; i += 2)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// } // TC=O(sqrt(n)) Much Better
// int Max(int a, int b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     // Largest prime integer will be an odd number.
//     int optimised_digit;
//     if (n % 2 == 0)
//     {
//         optimised_digit = n - 1;
//     }
//     else
//     {
//         optimised_digit = n;
//     } // optimised_digit always remains odd, and the original digit is never included.
//     int result;
//     for (int i = optimised_digit; i > 2; i -= 2)
//     {
//         if (is_prime(i) && n % i == 0)
//         {
//             result = i;
//             break;
//         }
//     }
//     if (n % 2 == 0)
//         result = Max(result, 2);
//     cout << result << endl;
//     return 0;
// }// O(n sqrt(n))

// OPTIMAL APPROACH
template <class T2>
bool is_prime(T2 n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
} // TC=O(sqrt(n)) Much Better
template <class T1>
T1 largestPrimeFactor(T1 n)
{

    // Divide-out Algorithm:
    T1 largest = -1;
    // First trim out all even terms
    if (n % 2 == 0)
    {
        largest = 2;
        n /= 2;
    }
    // trimming out all the odds
    for (T1 i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            largest = i;
            n /= i;
        }
    }
    // Considering 2
    if (n > 2)
        largest = 2;

    return largest
}