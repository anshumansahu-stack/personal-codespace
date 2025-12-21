#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// TIME LIMIT EXCEEDED
void Operation1(vector<long long> &nums)
{
    vector<long long> result;
    for (int i = 0; i < nums.size(); i += 2)
    { // odd leaving one from left
        result.push_back(nums[i]);
    }
    nums = result;
}
void Operation2(vector<long long> &nums)
{
    vector<long long> result;
    long long n = nums.size();
    for (int i = n - 1; i >= 0; i -= 2)
    { // odd leaving one from left
        result.push_back(nums[i]);
    }
    sort(result.begin(), result.end());
    nums = result;
}
long long lastInteger(long long n)
{
    vector<long long> nums;
    for (long long i = 1; i <= n; i++)
    {
        nums.push_back(i);
    } // sequence made
    for (long long i = 1; nums.size() > 1; i++)
    {
        if (i % 2 != 0)
        {
            Operation1(nums);
        }
        else
        {
            Operation2(nums);
        }
    }
    return nums[0];
} // ©leetcode
int main()
{
    long long n;
    cout << "Enter the number:" << endl;
    cin >> n;
    cout << lastInteger(n) << endl;
    return 0;
}