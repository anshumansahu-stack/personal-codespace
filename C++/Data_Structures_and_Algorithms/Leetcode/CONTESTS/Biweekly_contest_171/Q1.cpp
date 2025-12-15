#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n)
{
    // cout << endl
    //  << "Checking prime for int " << n << endl;
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
} // Works perfect, TC=O(sqrt(n))
bool SuffIteration(int &var, int &numfac)
{
    int n1 = var, gonum = 0;
    // cout << endl
    //  << "Suffiteration!" << endl;
    while (n1 > 0)
    {
        int i = n1 % 10;     //
        gonum += i * numfac; //
        if (isPrime(gonum))
        {
            numfac *= 10;
            n1 /= 10;
            // cout << gonum;
        }
        else
        {
            return false;
        }
    }
    var = gonum;
    return true;
} // O(k),k is the number length
bool PrefIteration(const int &var, int &numfac)
{
    // cout << endl
    //      << "Prefiteration!" << endl;
    while (numfac > 0)
    {
        numfac = int(numfac / 10);
        if (numfac == 0)
        {
            return true;
        }
        int n1 = int(var / numfac);
        if (isPrime(n1) == false)
        {
            return false;
        }
        // cout << n1 << endl;
    }
    return true;
}
bool completePrime(int num)
{
    int var = num, numfac = 1;
    if (SuffIteration(var, numfac))
    {
        return PrefIteration(var, numfac);
    }
    return false;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    if (completePrime(N))
    {
        cout << "Complete Prime" << endl;
    }
    else
    {
        cout << "Not Complete Prime" << endl;
    }
    // vector<int> nums;
    // cout << "Enter " << N << " elements:" << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     int x;
    //     cin >> x;
    //     nums.push_back(x);
    // } // Input taken
    return 0;
}