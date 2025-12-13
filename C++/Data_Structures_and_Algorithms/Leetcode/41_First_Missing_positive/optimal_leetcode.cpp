#include <iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int &num = nums[i];
        if (num > 0 && num <= n)
        {
            if (nums[num - 1] != num)
            {
                swap(nums[num - 1], num);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
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
    cout << "The smallest missing positive number is " << firstMissingPositive(nums) << endl;
    return 0;
}