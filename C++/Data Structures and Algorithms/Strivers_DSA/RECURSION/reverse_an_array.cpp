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
    if (start >= end)
        return;
    swap(nums[start], nums[end]);
    reverse(nums, start + 1, end - 1);
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
    reverse(nums, 0, nums.size() - 1);
    for (int i : nums)
    {

        cout << i << " ";
    }
    return 0;
}