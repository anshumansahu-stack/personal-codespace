#include <iostream>
#include <vector>
using namespace std;
void printAllSubsequences(int index, vector<int> &nums, vector<int> &zero)
{
    if (index >= nums.size())
    {
        cout << "[";
        for (int i : zero)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
        return;
    }
    zero.push_back(nums[index]);
    printAllSubsequences(index + 1, nums, zero);
    zero.pop_back();
    printAllSubsequences(index + 1, nums, zero);
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
    vector<int> zero;
    printAllSubsequences(0, nums, zero);
    return 0;
}