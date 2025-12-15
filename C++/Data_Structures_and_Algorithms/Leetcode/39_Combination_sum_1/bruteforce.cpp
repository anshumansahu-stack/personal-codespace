#include <iostream>
#include <vector>
using namespace std;
// 100% Accepted by Leetcode
void Helper_function(vector<int> &candidates, vector<int> &subvec, vector<vector<int>> &result, int target, int index)
{
    if (index >= candidates.size())
    {
        if (target == 0)
        {
            result.push_back(subvec);
        }
        return;
    }
    if (target - candidates[index] >= 0)
    {                                        // selection condition
        subvec.push_back(candidates[index]); // select, may try same index next
        Helper_function(candidates, subvec, result, target - candidates[index], index);
        subvec.pop_back(); // not select probability after trying
        Helper_function(candidates, subvec, result, target, index + 1);
    }
    else // if sum is not satisfactory, pick another element
    {
        Helper_function(candidates, subvec, result, target, index + 1);
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> subvec;         // initialised with no elements
    vector<vector<int>> result; // initialised with no vectors
    Helper_function(candidates, subvec, result, target, 0);
    return result;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> candidates;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        candidates.push_back(x);
    } // Input taken
    int target;
    cout << "Enter target element:" << endl;
    cin >> target;
    vector<vector<int>> result = combinationSum(candidates, target);
    for (vector<int> i : result)
    {
        cout << "[";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
