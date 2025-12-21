#include <iostream>

#include <vector>
using namespace std;
//TIME LIMIT EXCEEDED
int maximumSum(vector<int> &nums)
{
    bool notinloop = true;
    int maxsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum % 3 == 0)
                {
                    notinloop = false;
                    maxsum = max(maxsum, sum);
                }
            }
        }
    }
    if (notinloop)
    {
        return 0;
    }
    return maxsum;
} // ©leetcode
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
    cout << "The maximum sum is " << maximumSum(nums) << endl;
    return 0;
}