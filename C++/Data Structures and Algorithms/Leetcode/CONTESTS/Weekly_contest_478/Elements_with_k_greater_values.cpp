#include <iostream>
#include <vector>
using namespace std;
// return the number of qualified elements in nums
int countElements(vector<int> &nums, int k)
{
    int qualcount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int elcount = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j == i)
            {
                continue;
            }
            if (nums[j] > nums[i])
            {
                elcount++;
            }
            if (elcount >= k)
            {
                qualcount++;
                break;
            }
        }
    }
    return qualcount;
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
    cout << "Enter the integer k:" << endl;
    cin >> k;
    cout << "The number of qualified elements is " << countElements(nums, k) << endl;
    return 0;
}