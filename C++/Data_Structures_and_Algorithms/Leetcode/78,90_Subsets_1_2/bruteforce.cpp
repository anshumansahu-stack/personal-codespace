#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Objective: to return the subsets in any order.
void HelperFunction(vector<int> &nums, vector<int> &subVec, vector<vector<int>> &subsets, int index)
{
    // Base case
    if (index >= nums.size())
    {
        subsets.push_back(subVec);
        // cout << "Subvec pushed!" << endl;
        return;
    }
    // Pick condition
    subVec.push_back(nums[index]);
    // Avoid duplicates section
    int next_index = index + 1;
    while (next_index < nums.size() && nums[next_index] == nums[index])
    {
        next_index++;
    }
    // cout << "Index " << index << " picked, next iteration is " << next_index << endl;
    HelperFunction(nums, subVec, subsets, index + 1);
    subVec.pop_back(); // Not pick condition
    // Avoid duplicates section
    next_index = index + 1;
    while (next_index < nums.size() && nums[next_index] == nums[index])
    {
        next_index++;
    }
    // cout << "Index " << index << " popped, next iteration is " << next_index << endl;
    HelperFunction(nums, subVec, subsets, next_index);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end());
    vector<int> subVec;
    HelperFunction(nums, subVec, subsets, 0);
    return subsets;
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
    vector<vector<int>> Subsets = subsets(nums);
    for (int i = 0; i < Subsets.size(); i++)
    {
        cout << "[";
        for (int j : Subsets[i])
        {
            cout << j << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}