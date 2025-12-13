#include <iostream>
#include <vector>
using namespace std;
void printAllSubsequences(int index, vector<int> &nums, vector<int> &zero, int tarsum, bool &sumfound)
{
    if (index >= nums.size())
    { // resultant subarray obtained
        int sum = 0;
        if (sumfound)
        {
            return;
        }
        for (int i : zero)
        {
            sum += i;
        }
        if (sum == tarsum)
        {
            sumfound = true;
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
    printAllSubsequences(index + 1, nums, zero, tarsum, sumfound);
    zero.pop_back();
    printAllSubsequences(index + 1, nums, zero, tarsum, sumfound);
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
    bool sumfound = false;
    printAllSubsequences(0, nums, zero, K, sumfound);
    return 0;
}