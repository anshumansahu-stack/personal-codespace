#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void DNFsort(vector<int> &nums)
{
    int left = 0, middle = 0, right = nums.size() - 1;
    while (middle <= right)
    {
        if (nums[middle] == 0)
        {
            swap(nums[middle], nums[left]);
            left++;
            middle++;
        }
        else if (nums[middle] == 1)
        {
            middle++;
        }
        else
        {
            swap(nums[middle], nums[right]);
            right--;
        }
    } // O(n)TC
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
    DNFsort(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}