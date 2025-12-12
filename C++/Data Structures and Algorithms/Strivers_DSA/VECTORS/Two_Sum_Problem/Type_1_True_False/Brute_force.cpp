#include <iostream>
#include <vector>
using namespace std;
bool Two_Sum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return true;
            }
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
    cout << "enter target element" << endl;
    cin >> target;
    if (Two_Sum(nums, target))
    {
        cout << "target sum exists";
    }
    else
    {
        cout << "Target sum doesnt exist";
    }
    return 0;
}