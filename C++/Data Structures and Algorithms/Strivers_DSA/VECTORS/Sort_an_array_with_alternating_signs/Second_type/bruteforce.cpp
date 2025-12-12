#include <iostream>
#include <vector>
using namespace std;
// BRUTEFORCE.. Fallback since new type
vector<int> rearrangeArray(vector<int> &nums)
{
    // We will make two temporary arrays to store pure positives, then pure negatives.
    vector<int> pos, neg;
    for (int i = 0; i < nums.size(); i++) // nums.size()=10; 0,1,2,3,4,5,6,7,8,9
    {
        if (nums[i] < 0)
        {
            neg.push_back(nums[i]); // instance neg.size()=6; 0,1,2,3,4,5
        }
        else
        {
            pos.push_back(nums[i]); // instance pos.size()=4; 0,1,2,3
        }
    } // O(n),all positives and negatives collected
    int i;
    for (i = 0; i < nums.size() && i / 2 < pos.size() && (i - 1) / 2 < neg.size(); i++)
    {
        if (i % 2 == 0)
        {
            nums[i] = pos[i / 2]; // 0,2,4,6,break at i=8
        }
        else
        {
            nums[i] = neg[(i - 1) / 2]; // 1,3,5,7
        }
    } // O(n)
    // i=8
    if (i / 2 != pos.size()) // i/2=6/2=3,unsatisfied
    // if this satisfies then number i is odd
    {
        for (int k = (i - 1) / 2; k < pos.size() && i < nums.size(); k++, i++)
        {
            nums[i] = pos[k];
        }
    } // Remaining added serially
    if ((i - 1) / 2 != neg.size()) // i-1/2=2 floored, will satisfy
    // if this satisfies then the number i is even
    {
        for (int k = ((i) / 2) -1; k < neg.size() && i < nums.size(); k++, i++)
        {
            nums[i] = neg[k];
        }
    } // Remaining added serially
    return nums;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> nums;
    cout << "PLEASE ENTER EQUAL NUMBER OF POSITIVES AND NEGATIVES" << endl;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    } // Input taken
    nums = rearrangeArray(nums);
    for (int i : nums)
    {

        cout << i << " ";
    }
    return 0;
}