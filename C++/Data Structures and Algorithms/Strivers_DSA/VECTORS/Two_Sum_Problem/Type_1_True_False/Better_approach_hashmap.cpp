#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool twosum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]] = i;
    } // Storing the data
    for (int i = 0; i < nums.size(); i++)
    {
        int remtar = target - nums[i];
        if (mpp.find(remtar) != mpp.end())
        {
            return true;
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