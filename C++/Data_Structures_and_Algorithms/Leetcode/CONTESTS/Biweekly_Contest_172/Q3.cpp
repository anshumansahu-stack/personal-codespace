#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ERROR in SOURCE Question
int setBits(string s)
{
    int count = 0;
    for (char i : s)
    {
        if (i == 1)
        {
            count++;
        }
    }
    return count;
} // O(n)
long long maximumScore(vector<int> &nums, string s)
{
    sort(nums.begin(), nums.end()); // O(nlogn), ascending
    int reps = setBits(s), n = nums.size(), maxscore = 0;
    for (int i = n - 1; i >= 0 && n - i <= reps; i--)
    {
        maxscore += (nums[i]);
    }
    return maxscore;
} // ©leetcode
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
    string s;
    cout << "Enter the string" << endl;
    cin >> s;
    cout << maximumScore(nums, s) << endl;
    return 0;
}