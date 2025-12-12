#include <iostream>
#include <vector>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    // We will make one temporary array to store the result.
    vector<int> result(nums.size(), 0);
    int posind = 0, negind = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            result[posind] = nums[i];
            if (posind + 2 > nums.size() - 1)
            {
                continue;
            }
            posind += 2;
        }
        else
        {
            result[negind] = nums[i];
            if (negind + 2 > nums.size() - 1)
            {
                continue;
            }
            negind += 2;
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
    cout << "PLEASE ENTER EQUAL NUMBER OF POSITIVES AND NEGATIVES" << endl;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    } // Input taken
    nums = rearrangeArray(nums);
    for (int i : nums)
    {

        cout << i << " ";
    }
    return 0;
}