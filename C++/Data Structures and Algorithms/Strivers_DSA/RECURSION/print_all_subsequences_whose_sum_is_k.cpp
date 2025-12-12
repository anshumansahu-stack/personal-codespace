#include <iostream>
#include <vector>
using namespace std;
void printAllSubsequences(int index, vector<int> &nums, vector<int> &zero, int tarsum)
{
    if (index >= nums.size())
    { // resultant subarray obtained
        int sum = 0;
        for (int i : zero)
        {
            sum += i;
        }
        if (sum == tarsum)
        {
            cout << "[";
            for (int i : zero)
            {
                cout << i << " ";
            }
            cout << "]" << endl;
        }
        return;
    }
    zero.push_back(nums[index]);
    printAllSubsequences(index + 1, nums, zero, tarsum);
    zero.pop_back();
    printAllSubsequences(index + 1, nums, zero, tarsum);
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
    int K;
    cout << "Enter target sum:" << endl;
    cin >> K;
    vector<int> zero;
    printAllSubsequences(0, nums, zero, K);
    return 0;
}