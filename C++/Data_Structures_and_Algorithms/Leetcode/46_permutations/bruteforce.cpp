#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> permute;
    sort(nums.begin(), nums.end());
    do
    {
        permute.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return permute;
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
    vector<vector<int>> Permute = permute(nums);
    for (int i = 0; i < Permute.size(); i++)
    {
        cout << "[";
        for (int j : Permute[i])
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}