// #include <iostream>
// using namespace std;
// // BRUTEFORCE
// bool isPrime(long long n)
// {
//     if (n <= 1)
//         return false;
//     if (n == 2)
//         return true;
//     for (long long i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// } // O(n) worst case.
// int main()
// {
//     long long n;
//     cin >> n;
//     // we need to start from 1 and all the way till infinity, wherever the counter reaches n we break.
//     long long curr_int = 1, counter = 0, res_int;
//     while (true)
//     {
//         if (isPrime(curr_int))
//         {
//             counter++;
//             cout << counter << ": " << curr_int << endl;
//             if (counter == n)
//             {
//                 res_int = curr_int;
//                 break;
//             }
//         }
//         curr_int++;
//     } // O(n) in itself, without considering function is prime.
//     cout << res_int << endl;
//     return 0;
// } // TC=O(n^2) overall, TLE .

// For higher values, i.e. n-->inf, the hidden log factor comes into play as p_n=nlogn.
// So the TC at Higher numbers is O(n^2logn^2), worse than that of O(n^2).

// A BETTER approach can be achieved by iterating the isPrime function till root n.
// That optimises the initial code a little bit.
// for (long long i = 2; i * i <= n; i++)
// TC=O((nlogn)^3/2). Refer to chatGPT and notes for procedure.

// OPTIMAL APPROACH: Sieve of Eratosthenes
// p_n=n(logn+loglogn)

#include <iostream>
using namespace std;
void Sieve_of_Eratosthenes(bool isPrime[], long long limit)
{ // Limit is till which the sieve is required
    isPrime[0] = false;
    isPrime[1] = false;
    for (long long i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j < limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    long long n;
    cin >> n;
    bool isPrime[200001];
    fill(isPrime, isPrime + 200001, true);
    Sieve_of_Eratosthenes(isPrime, 200001);
    long long prime;
    for (long long i = 2, counter = 0; counter < n; i++)
    {
        if (isPrime[i])
        {
            // cout << "mainl" << endl;
            counter++;
            prime = i;
        }
    }
    cout << prime << endl;
    return 0;
}