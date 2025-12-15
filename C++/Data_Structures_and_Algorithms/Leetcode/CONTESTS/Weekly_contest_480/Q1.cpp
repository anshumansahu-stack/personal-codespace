#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int absDifference(vector<int> &nums, int k)//Submitted
{
    sort(nums.begin(), nums.end()); // O(nlogn)
    // k should definitely be smaller than nums.size()
    int p = nums.size(), greatsum = 0, smallsum = 0;
    for (int left = 0, right = p - 1; left < k && right > p - k - 1; left++, right--)
    {
        smallsum += nums[left];
        greatsum += nums[right];
    }
    return greatsum - smallsum;
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
    int k;
    cout << "Enter the value k " << endl;
    cin >> k;
    cout << "The difference between the largest " << k << " and the smallest " << k << " integers is " << absDifference(nums, k) << endl;
    return 0;
}