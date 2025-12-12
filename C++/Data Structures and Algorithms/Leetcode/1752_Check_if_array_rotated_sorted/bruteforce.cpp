#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void reverse(vector<int> &nums, int start, int end)
{
    if (start > end)
        return;
    swap(nums[start], nums[end]);
    reverse(nums, start + 1, end - 1);
}
bool check(vector<int> &nums)
{
    // for reversing
    int endindex;
    bool isnondescending = true;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            endindex = i;
            reverse(nums, 0, endindex - 1);
            reverse(nums, endindex, nums.size() - 1);
            reverse(nums, 0, nums.size() - 1);
            isnondescending = false;
            break;
        }
    }
    // for checking if the array is in non descending order
    if (isnondescending)
    {
        return true;
    }
    else
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
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
    if (check(nums))
    {
        cout << "rotated non descending" << endl;
    }
    else
    {
        cout << "not meeting requirements" << endl;
    }
    return 0;
}