#include <iostream>
#include <vector>
using namespace std;
//BRUTEFORCE
vector<int> rearrangeArray(vector<int> &nums)
{
    // We will make two temporary arrays to store pure positives, then pure negatives.
    vector<int> pos, neg;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    } // O(n)
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            nums[i] = pos[i / 2];
        }
        else
        {
            nums[i] = neg[(i - 1) / 2];
        }
    } // O(n)
    return nums;
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