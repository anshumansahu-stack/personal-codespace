#include <iostream>
#include <vector>
// Objective: to return all the sums of possible subsets in ascending order.
// Bruteforce: Generate all subsets of a given set O(2^n)
// Merge sort O(nlogn)
// Net TC: O(nlogn)+O(2^n)
using namespace std;
int sum(vector<int> nums)
{
    int sum = 0;
    for (int i : nums)
    {
        sum += i;
    }
    return sum;
}
void subsets(vector<int> &nums, vector<int> &subVec, vector<int> &result, int index)
{
    if (index >= nums.size())
    {
        result.push_back(sum(subVec));
        return;
    }
    subVec.push_back(nums[index]);
    subsets(nums, subVec, result, index + 1);
    subVec.pop_back();
    subsets(nums, subVec, result, index + 1);
}
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
void printSubsetsum(vector<int> &nums)
{
    vector<int> subVec, result;
    subsets(nums, subVec, result, 0);
    mergesort(result, 0, result.size() - 1);
    cout << "[";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
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
    printSubsetsum(nums);
    return 0;
}