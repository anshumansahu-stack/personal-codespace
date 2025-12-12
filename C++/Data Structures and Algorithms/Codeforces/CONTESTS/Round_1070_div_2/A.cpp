#include <iostream>
#include <vector>
using namespace std;
int operationsWithInversions(vector<int> &nums)
{
    int count = 0, reference_int = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < reference_int)
        {
            count++;
        }
        else
        {
            reference_int = nums[i];
        }
    }
    return count;
}
int main()
{
    int test_case;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++)
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
        cout << operationsWithInversions(nums) << endl;
    }
    return 0;
}