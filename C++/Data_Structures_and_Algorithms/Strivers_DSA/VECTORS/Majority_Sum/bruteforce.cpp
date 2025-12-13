#include <iostream>
#include <vector>
#include <set>
// bruteforce
using namespace std;
int majorityelement(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    } // O(n1.n1logn1)

    for (int i : s)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == nums[j])
            {
                count++;
            }
            if (count > (nums.size() / 2))
            {
                return i;
            }
        } // O(n1*n2)
    } // n1=no.of unique elements;n2=number of total elements
    return -1;
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
    cout << "The majority element is " << majorityelement(nums) << endl;
    return 0;
}