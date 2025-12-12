#include <iostream>
using namespace std;
// BRUTEFORCE
// long long Max_pythagorean_triplet_product(long long N)
// {
//     long long max_product = -1;
//     for (long long a = 1; a < N - 1; a++)
//     {
//         for (long long b = a + 1; b < N; b++)
//         {
//             long long c = N - a - b;
//             if (c <= b)
//                 continue;
//             if (a * a + b * b == c * c)
//             {
//                 max_product = max(max_product, a * b * c);
//             }
//         }
//     }
//     return max_product;
// }

// BETTER FORCE
long long Max_pythagorean_triplet_product(long long N)
{
    if (N < 12)
        return -1;
    long long max_product = -1;
    for (long long a = 1; a <= N / 3; a++)
    {
        for (long long b = a + 1; b <= (N - a - 1) / 2; b++)
        {
            long long c = N - a - b;
            if (a * a + b * b == c * c)
            {
                max_product = max(max_product, a * b * c);
            }
        }
    }
    return max_product;
}
int main()
{
    long long n;
    cin >> n;
    cout << Max_pythagorean_triplet_product(n) << endl;
    return 0;
}