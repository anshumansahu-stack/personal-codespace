#include <iostream>
#include <vector>
using namespace std;
void Swapper(vector<int> &nums, vector<int> &forbidden, int index, bool &Swapped)
{ // Start from the beginning and iterate the number not equal to swap
    // index is the number to be swapped
    // search from the beginning of the array
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[index] && i != index)
        {
            if (nums[i] == forbidden[i])
            {
                Swapped = true;
                swap(nums[i], nums[index]);
            }
            return;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[index] && i != index)
        {
            if (nums[i] != forbidden[i])
            {
                Swapped = true;
                swap(nums[i], nums[index]);
            }
            return;
        }
    }
}
bool Checker(vector<int> &nums, vector<int> &forbidden)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == forbidden[i])
        {
            return false;
        }
    }
    return true;
}
int minSwaps(vector<int> &nums, vector<int> &forbidden)
{
    int count = 0;
    bool Swapped = false; // Detects whether the number can be swapped or not
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == forbidden[i])
        {
            Swapper(nums, forbidden, i, Swapped);
            if (Swapped)
            {
                count++;
            }
            else
            {
                return -1;
            }
        }
    }
    if (Checker(nums, forbidden))
    {
        return count;
    }
    return -1;
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
    vector<int> forbidden;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        forbidden.push_back(x);
    } // Input taken
    cout << minSwaps(nums, forbidden) << endl;
    return 0;
}