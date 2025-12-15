#include <iostream>
#include <vector>
// Moore's voting algorithm
using namespace std;
bool majorityelementcheck(vector<int> &nums, int result)
{
    int count = 0;
    for (int i : nums)
    {
        if (i == result)
        {
            count++;
        }
    }
    if (count > nums.size() / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int majorityelement(vector<int> &nums)
{
    int currelement, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            currelement = nums[i];
            count++;
        }
        else if (currelement == nums[i])
        {
            count++;
        }
        else
        { // currelement!=nums[i]
            count--;
        }
    }
    return majorityelementcheck(nums, currelement) ? currelement : -1;
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
    cout << "The majority element is " << majorityelement(nums) << endl;
    return 0;
}