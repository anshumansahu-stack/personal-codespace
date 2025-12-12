#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Objective: to return all the sums of possible subsets in ascending order.
void printSubsetSum(vector<int> &nums, vector<int> &result, int sumTrack, int index)
{
    // Base condition
    if (index >= nums.size())
    {
        // cout << "sum=" << sumTrack << " pushed!" << endl;//for debugging
        result.push_back(sumTrack); // Pushing the current sum
        return;
    }
    // Pick condition;
    // cout << "nums " << index << " pushed!" << endl;//for debugging
    printSubsetSum(nums, result, sumTrack + nums[index], index + 1);

    // cout << "nums " << index << " popped!" << endl;//for debugging
    printSubsetSum(nums, result, sumTrack, index + 1); // Not pick condition.
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
    vector<int> result;
    int sumTrack = 0, index = 0;
    printSubsetSum(nums, result, sumTrack, index); // O(2^N) TC. O(2^N) SC since there are those 2^N number of subsets.
    sort(result.begin(), result.end());            // O(2^n.log(2^n)),n being the input
    cout << "The array is:" << endl;
    cout << "[";
    for (int i : result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
    return 0;
}