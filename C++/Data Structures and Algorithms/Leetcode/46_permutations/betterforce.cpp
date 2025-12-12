#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool elementCheck(int i, unordered_map<int, int> &mpp)
{ // Returns true if element is forund, false otherwise.
    if (mpp[i] == 0)
    {
        return false;
    }
    return true;
} // O(n) TC
void HelperFunction(vector<int> &nums, vector<int> &subVec, unordered_map<int, int> &mpp, vector<vector<int>> &result, int index)
{
    // Base Case
    if (subVec.size() == nums.size())
    {
        cout << "subVec pushed!" << endl;
        result.push_back(subVec);
        return;
    }
    // First element must be chosen as either of the three, then next must be chosen as either of the remaining.
    // You need to push back, try and pop back every element. an elementcheck function is required.
    while (index < nums.size())
    {
        int k = nums.size();
        if (elementCheck(nums[index], mpp) == false)
        {
            subVec.push_back(nums[index]);
            mpp[nums[index]]++;
            cout << "Element " << index << " pushed!, next Recursion index is " << index + 1 << endl;
            HelperFunction(nums, subVec, mpp, result, index + 1);
            subVec.pop_back();
            mpp[nums[index]]--;
            cout << "Element " << index << " popped!" << endl;
        }
        index++;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    unordered_map<int, int> mpp;
    vector<int> subVec;
    int index = 0;
    HelperFunction(nums, subVec, mpp, result, index);
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
    vector<vector<int>> Permute = permute(nums);
    for (int i = 0; i < Permute.size(); i++)
    {
        cout << "[";
        for (int j : Permute[i])
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}