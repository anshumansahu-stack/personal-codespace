#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// KADANES ALGORITHM
int maximumsubarraysum(vector<int> &nums)
{
    int sum = 0, maxsum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > maxsum)
        {
            maxsum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    } // O(n)
    return maxsum;
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
    cout << "The maximum subarray sum is " << maximumsubarraysum(nums) << endl;
    return 0;
}