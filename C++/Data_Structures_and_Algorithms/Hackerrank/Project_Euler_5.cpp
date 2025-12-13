// 2520 is the smallest number that can be divided by
// each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly
// divisible(divisible with no remainder) by all of the numbers from 1 to N?

// #include <iostream>
// using namespace std;
// // BRUTEFORCE
// bool divisibility(long long n1, long long n2)// Check divisibility from n2--> 1
// {
//     // n1 is larger number than n and n2 is the limit (1...n2) of factors.
//     while (n2 > 1)
//     {
//         if (n1 % n2 != 0)
//         {
//             return false;
//         }
//         n2--;
//     }
//     return true;
// }
// long long Max(long long n1, long long n2)
// {
//     if (n1 > n2)
//         return n1;
//     else
//         return n2;
// }
// int main()
// {
//     long long n;
//     cin >> n;
//     long long i = n + 1, smallest;
//     while (true)
//     {
//         if (divisibility(i, n))
//         {
//             smallest = i;
//             break;
//         }
//         i++;
//     }
//     cout << smallest << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
long long max(long long n1, long long n2)
{
    if (n1 > n2)
        return n1;
    else
        return n2;
}
long long min(long long n1, long long n2)
{
    if (n1 < n2)
        return n1;
    else
        return n2;
}
long long GCD(long long n1, long long n2)
{
    long long Max = max(n1, n2), Min = min(n1, n2), rem;
    do
    {
        rem = Max % Min;
        Max = Min;
        Min = rem;
    } while (rem > 0);
    return Max; // Euclidean Implementation
}
long long LCM(long long n1, long long n2)
{
    return (n1 / GCD(n1, n2)) * n2; // Euclidean Implementation, wrote this way so it doesnt exceed long long
}
int main()
{
    long long n;
    cin >> n;
    long long reqnum = 1;
    for (long long i = n; i >= 2; i--)
    {
        reqnum = LCM(reqnum, i);
    }
    cout << reqnum << endl;
    return 0;
}