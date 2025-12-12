// A palindromic number reads the same both ways.
// The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101=143*707.

// Find the largest palindrome made from the product of two 3-digit numbers which is less than N(input).
#include <iostream>
using namespace std;

// BRUTE FORCE Uncomment Below
// template <class T1>
// bool isPalindrome(T1 n)
// {
//     T1 revnum = 0, refnum = n;
//     while (n > 0)
//     {
//         int last_digit = n % 10;
//         revnum = (revnum * 10) + last_digit;
//         n /= 10;
//     }
//     if (revnum == refnum)
//         return true;
//     else
//         return false;
// }
// int main()
// {
//     long long N;
//     cin >> N;
//     bool ans_found = false;
//     // Since were working for the greatest then its better to go for the largest to shortest decrement.
//     for (long long i1 = 999; i1 >= 100; i1--)
//     {
//         for (long long i2 = i1; i2 >= 100; i2--)
//         {
//             long long product = i1 * i2;
//             if (isPalindrome<long long>(product) && product < N)
//             {
//                 cout << product << endl;
//                 cout << "Factors are: " << i1 << " & " << i2 << endl;
//                 ans_found = true;
//                 break;
//             }
//         }
//         if (ans_found)
//         {
//             break;
//         }
//     }
//     if (ans_found == false)
//     {
//         cout << "DNE" << endl;
//     }
//     return 0;
// }

// Optimal Approach Below
// DESCENDING PALINDROME GENERATION ALGORITHM
template <class T1>
T1 reverse(T1 n)
{
    T1 revnum = 0;
    while (n > 0)
    {
        T1 temnum = n % 10;
        revnum = (revnum * 10) + temnum;
        n /= 10;
    }
    return revnum;
}
template <class T2>
bool is3digit(T2 n)
{
    if (n >= 100 && n <= 999)
    {
        return true;
    }
    return false;
}
int main()
{
    long long n;
    cin >> n;
    // palindrome generator
    bool ans_found = false;
    for (long long first_part = 999; first_part >= 100; first_part--)
    {
        long long palindrome = (first_part * 1000) + reverse<long long>(first_part);
        for (long long i = 999; i >= 100; i--)
        {
            if (palindrome >= n) continue;        // skip palindromes >= N first
            long long factor = palindrome / i;
            if (palindrome % i == 0 && is3digit<long long>(factor))
            {
                cout << palindrome << endl;
                ans_found = true;
                break;
            }
        }
        if (ans_found)
        {
            break;
        }
    }
    return 0;
}
