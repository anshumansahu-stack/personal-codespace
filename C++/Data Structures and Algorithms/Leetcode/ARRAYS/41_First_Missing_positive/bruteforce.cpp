#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Approach: Sort and return first missing by iteration using i=1. O(nlogn +n) Time complexity
int firstMissingPositive(vector<int> &nums)
{
    //1 is the least positive number that can miss an array.
    //Strategy: Find the least positive integer in the array. If its not 1, return 1.
    // What if its 1?
    
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
    cout << "The first missing positive is: " << firstMissingPositive(nums) << endl;
    return 0;
}