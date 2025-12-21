#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int minOperations(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    int countel = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    { // Reverse Iteration
        if (mpp[nums[i]] != 0)
        {
            // we'll write the return here. countel has some value now.
            int remel = nums.size() - countel;
            if (remel < 3)
            {
                return 0;
            }
            else
            {
                if (remel % 3 == 0)
                {
                    return remel / 3;
                }
                else
                {
                    return (remel / 3) + 1;
                }
            }
        }
        else
        {
            mpp[nums[i]]++;
            countel++;
        }
    }
    return 0;
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
    cout << minOperations(nums) << endl;
    return 0;
}