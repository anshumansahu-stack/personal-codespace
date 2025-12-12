#include <iostream>
#include <vector>
using namespace std;
// Sort the array first. Mergesort, O(nlogn) completion
// Submitted in Leetcode with 24.05% TC
void merge(vector<int> &candidates, int first, int mid, int last)
{
    int first1 = first, last1 = mid, first2 = mid + 1, last2 = last;
    vector<int> temp(last - first + 1, 0);
    int index = 0;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (candidates[first1] < candidates[first2])
        {
            temp[index] = candidates[first1];
            index++;
            first1++;
        }
        else if (candidates[first1] > candidates[first2])
        {
            temp[index] = candidates[first2];
            index++;
            first2++;
        }
        else
        {
            temp[index] = candidates[first1];
            index++;
            first1++;
            temp[index] = candidates[first2];
            index++;
            first2++;
        }
    }
    // adding remaining elements
    while (first1 <= last1)
    {
        temp[index] = candidates[first1];
        index++;
        first1++;
    }
    while (first2 <= last2)
    {
        temp[index] = candidates[first2];
        index++;
        first2++;
    }
    // replacing entire nums array
    for (int i = first, j = 0; i <= last; i++, j++)
    {
        candidates[i] = temp[j];
    }
}
void mergesort(vector<int> &candidates, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(candidates, start, mid);
        mergesort(candidates, mid + 1, end);
        merge(candidates, start, mid, end);
    }
}
// recursion part starts. Array is sorted and all the same elements are at one place.
void Helper_function(vector<int> &candidates, vector<int> &subvec, vector<vector<int>> &result, int target, int index)
{
    if (index >= candidates.size())
    {
        if (target == 0)
        {
            result.push_back(subvec);
        }
        return;
    }
    if (target - candidates[index] >= 0)
    {                                        // selection condition
        subvec.push_back(candidates[index]); // select, may try same index next
        Helper_function(candidates, subvec, result, target - candidates[index], index + 1);
        subvec.pop_back(); // not select probability after trying
    }
    // if sum is not satisfactory, pick another element
    int nextUnique = index + 1;
    while (nextUnique < candidates.size() && candidates[nextUnique] == candidates[index])
    {
        nextUnique++;
    }
    Helper_function(candidates, subvec, result, target, nextUnique);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> subvec;         // initialised with no elements
    vector<vector<int>> result; // initialised with no vectors
    mergesort(candidates, 0, candidates.size() - 1);
    int ref_tar = 0;
    Helper_function(candidates, subvec, result, target, 0);
    return result;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> candidates;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        candidates.push_back(x);
    } // Input taken
    int target;
    cout << "Enter target element:" << endl;
    cin >> target;
    vector<vector<int>> result = combinationSum2(candidates, target);
    for (vector<int> i : result)
    {
        cout << "[";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
