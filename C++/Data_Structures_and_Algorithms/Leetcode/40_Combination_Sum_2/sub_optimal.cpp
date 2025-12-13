#include <iostream>
#include <vector>
using namespace std;
//NO USE
void merge(vector<int> &nums, int first, int mid, int last)
{
    int first1 = first, last1 = mid, first2 = mid + 1, last2 = last;
    vector<int> temp(last - first + 1, 0);
    int index = 0;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (nums[first1] < nums[first2])
        {
            temp[index] = nums[first1];
            index++;
            first1++;
        }
        else if (nums[first1] > nums[first2])
        {
            temp[index] = nums[first2];
            index++;
            first2++;
        }
        else
        {
            temp[index] = nums[first1];
            index++;
            first1++;
            temp[index] = nums[first2];
            index++;
            first2++;
        }
    }
    // adding remaining elements
    while (first1 <= last1)
    {
        temp[index] = nums[first1];
        index++;
        first1++;
    }
    while (first2 <= last2)
    {
        temp[index] = nums[first2];
        index++;
        first2++;
    }
    // replacing entire nums array
    for (int i = first, j = 0; i <= last; i++, j++)
    {
        nums[i] = temp[j];
    }
}
void mergesort(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}
vector<int> removeduplicates(vector<int> &nums)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            result.push_back(nums[i]);
            continue;
        }
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        result.push_back(nums[i]);
    }
} // O(n)
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
    mergesort(nums, 0, nums.size() - 1);
    cout << "[";
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}