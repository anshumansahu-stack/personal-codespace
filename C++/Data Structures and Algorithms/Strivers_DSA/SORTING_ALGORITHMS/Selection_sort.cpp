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
int main()
{
    vector<int> nums;
    char consent = 'y';
    do
    {
        int input;
        cout << "Enter the number: ";
        cin >> input;
        nums.push_back(input);
        cout << "Do you want to enter another number?" << endl;
        cin >> consent;
    } while (consent == 'y');
    // Array input taken
    if (nums.empty())
    {
        cout << "No elements to sort!" << endl;
        return 0;
    }
    Selection_Sort(nums, 0, nums.size() - 1);
    cout << "The sorted array is:" << endl;
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl
         << "OK Thank You!" << endl;
    return 0;
}