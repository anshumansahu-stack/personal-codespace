#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
// The objective was to print binary Reflections in order. This is wrong.
using namespace std;
int decimalToBinary(int n)
{
    int result = 0, fac = 1;
    while (n > 0)
    {
        int i = n % 2;
        result += i * fac;
        fac *= 10;
        n /= 2;
    }
    return result;
} // O(size of number). Perfectly functioning
int BinarytoDecimal(int n)
{
    int res = 0, fac = 1;
    while (n > 0)
    {
        int i = n % 10;
        res += fac * i;
        n /= 10;
        fac *= 2;
    }
    return res;
}
vector<int> sortByReflection(vector<int> &nums)
{
    vector<int> result;
    map<int, int> mpp;
    for (int i : nums)
    {
        mpp[decimalToBinary(i)] += i; // By default sorted
    } // Converted all numbers to binary,and mapped them in case duplicates, O(nlogn)
    // for (auto it : mpp)
    // {
    //     // cout << it.first << "-->" << it.second << endl;
    // }
    for (auto it : mpp)
    {
        int m = BinarytoDecimal(it.first);
        int k = it.second;
        // cout << m << " " << k << endl;
        while (k > 0)
        {
            result.push_back(m);
            // cout << "Pushed back " << it.first << " to result" << endl;
            k -= m; // Handles duplicate entries
            // cout << "it.second==" << k << endl;
        }
    } // O(n)
    // Seeking duplicate entries
    for (int i = 1; i < result.size(); i++)
    {
        if (result[i] == result[i - 1] && mpp[i] < mpp[i - 1])
        {
            swap(result[i], result[i - 1]);
        }
    } // O(n)
    return result;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> nums;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    } // Input taken
    vector<int> result = sortByReflection(nums);
    cout << "[";
    for (int i : result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}