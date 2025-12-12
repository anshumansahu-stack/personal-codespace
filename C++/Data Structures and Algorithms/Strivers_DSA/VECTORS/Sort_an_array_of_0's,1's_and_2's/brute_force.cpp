#include <iostream>
#include <vector>
using namespace std;
// This is actually better force, Bruteforce is merge sorting the array.O(nlogn) +SC=O(n)
void bruteforce(vector<int> &nums)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i : nums)
    {
        if (i == 0)
        {
            count0++;
        }
        else if (i == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    } // O(n)
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < count0)
        {
            nums[i] = 0;
        }
        else if (i >= count0 && i < count0 + count1)
        {
            nums[i] = 1;
        }
        else
        {
            nums[i] = 2;
        }
    } // O(n)
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    cout << "PLEASE ENTER 0,1,OR 2" << endl;
    vector<int> nums;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    } // Input taken
    bruteforce(nums); // sorting
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}