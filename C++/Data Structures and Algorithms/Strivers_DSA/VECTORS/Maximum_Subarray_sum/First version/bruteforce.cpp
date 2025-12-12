#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// BRUTEFORCE
int maximumsubarraysum(vector<int> &nums)
{
    int sum = 0, maxsum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            } // sum obtained
            if (sum > maxsum)
            {
                maxsum = sum;
            }//maxsum retained
            sum = 0;
        }
    }//O(n^3)
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