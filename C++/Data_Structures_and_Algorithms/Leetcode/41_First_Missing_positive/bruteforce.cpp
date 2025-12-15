#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool oneInNums(vector<int> &nums, int &index)
{
    while (index < nums.size())
    {
        if (nums[index] == 1)
        { // Index is already updated to the index of value 1.
            return true;
        }
        index++;
    }
    index = 0; // Return initial value if not found.
    return false;
}
int firstMissingPositive(vector<int> &nums)
{
    // We are concerned with positives. We need to skim out the negatives first.
    sort(nums.begin(), nums.end()); // Sort them
    int index = 0;
    if (oneInNums(nums, index) == false)
    { // One is not in the array
        return 1;
    }
    else
    { // One is in the array, index has some value now
        // Forward-Iterate through till we find the smallest positive integer after 1.
        int next_ind = index + 1;
        while (next_ind < nums.size())
        {
            if (nums[next_ind] - nums[next_ind - 1] > 1)
            {                                  // If the step is any other than 1 or 0.
                return nums[next_ind - 1] + 1; // Return the previous with one added to it.
            }
            next_ind++;
        }
        // Skimmed through the entire array, unable to find a step greater than 1.
        return nums[nums.size() - 1] + 1;
    }
    return -1; // Improbable, just for logic.
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
    cout << "The smallest integer not in the array nums is: " << firstMissingPositive(nums) << endl;
    return 0;
}