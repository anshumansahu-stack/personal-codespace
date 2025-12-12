#include <iostream>
#include <vector>
#include <unordered_map>
// Better approach using hashmap
using namespace std;
int majorityelement(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    } // Initially all values are initialised to 0;TC=O(n)
    for (auto it : mpp)
    {
        if (it.second > nums.size() / 2)
        {
            return it.first;
        }
    } // O(n)
    return -1;
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