#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Selection_Sort(vector<int> &nums, int startind, int endind)
{
    if (startind >= endind)
        return;
    int minimal_index = startind;
    for (int i = startind; i <= endind; i++)
    {
        if (nums[i] <= nums[minimal_index])
        {
            minimal_index = i;
        }
    }
    swap(nums[startind], nums[minimal_index]);
    Selection_Sort(nums, startind + 1, endind);
}
bool twosum(vector<int> &nums, int target)
{
    Selection_Sort(nums, 0, nums.size() - 1);
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        if (nums[left] + nums[right] > target)
        {
            // Reduce larger value
            right--;
        }
        else if (nums[left] + nums[right] < target)
        {
            // increase smaller value
            left++;
        }
        else
        {
            return true;
            // number found
        }
    }
    return false;
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
    int target;
    cout << "Enter the target value:" << endl;
    cin >> target;
    if (twosum(nums, target))
    {
        cout << "target sum exists";
    }
    else
    {
        cout << "Target sum doesnt exist";
    }
    return 0;
}