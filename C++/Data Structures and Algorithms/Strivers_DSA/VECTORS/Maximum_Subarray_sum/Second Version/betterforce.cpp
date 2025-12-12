#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// BETTERFORCE
int maximumsubarraysum(vector<int> &nums, int &index1, int &index2)
{
    int sum = 0, maxsum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j]; // adding the sum to the previous subarray
            if (sum > maxsum)
            {
                maxsum = sum;
                index1 = i;
                index2 = j;
            } // maxsum stored
        } // sum calculated
        sum = 0;
    } // O(n^2)
    return maxsum;
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
    int index1, index2;
    cout << "The maximum subarray sum is " << maximumsubarraysum(nums, index1, index2) << endl;
    cout << "The indices where the array begins and ends are: " << index1 << " " << index2 << endl;
    cout << "The subarray is:" << endl;
    for (int i = index1; i <= index2; i++)
    {

        cout << nums[i] << " ";
    }
    return 0;
}