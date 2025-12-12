#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Bruteforce
int Sum(vector<int> nums)
{
    int sum = 0;
    for (int i : nums)
    {
        sum += i;
    }
    return sum;
}
int minSubarray(vector<int> &nums, int p)
{
    int sum = Sum(nums); // O(n)
    if (sum % p == sum)
    {
        return -1;
    }
    if (sum % p == 0)
    {
        return 0;
    }
    int minlength = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int length = 0, subarraySum = 0;
            for (int k = i; k <= j; k++)
            {
                subarraySum += nums[k];
                if ((sum - subarraySum) % p == 0)
                {
                    length = k - i + 1;
                }
            }
            if (length > 0)
            {
                minlength = min(minlength, length);
            }
        }
    } // O(n^3)
    return minlength;
} // Very bad approach but works.
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
    int p;
    cout << "Enter the divisor p: " << endl;
    cin >> p;
    cout << "The length of the minimal subarray is: ";
    cout << minSubarray(nums, p);
    return 0;
}