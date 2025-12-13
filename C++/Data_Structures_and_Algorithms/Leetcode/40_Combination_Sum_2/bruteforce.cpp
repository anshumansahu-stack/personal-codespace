#include <iostream>
#include <vector>
#include <map>
using namespace std;
// Throws in Memory limit exceeded when used in leetcode.
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
        Helper_function(candidates, subvec, result, target, index + 1);
    }
    else
    {
        Helper_function(candidates, subvec, result, target, index + 1);
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> subvec;                                     // initialised with no elements
    vector<vector<int>> result;                             // initialised with no vectors
    Helper_function(candidates, subvec, result, target, 0); // result vector is now full of vectors
    // Some operations required on result vector so that the vectors returned are unique
    map<map<int, int>, int> mpp;
    for (int i = 0; i < result.size(); i++)
    {
        map<int, int> hash;
        for (int j = 0; j < result[i].size(); j++)
        {
            hash[result[i][j]]++;
        }
        mpp[hash]++; // hasharray appended
    }
    // Now the hashmap mpp contains the list of all singular arrays.
    // 1. all the elements of the array need to be printed as they are.
    // 2. all the maps are needed to be printed only once.
    // Remember the structure of the hashmap: map(map(int,int),int).
    vector<vector<int>> result_f;
    for (auto &p : mpp)
    { // each element in p=mpp:(map<int,int>->int)
        vector<int> hash;
        if (p.second != 0)
        { // here only one copy of vector is required so while loop aint required.
            for (auto &q : p.first)
            { // each element in q=p:(int->int)
                if (q.second != 0)
                { // we are copying a vector. all elements required.
                    int k = q.second;
                    while (k != 0)
                    {
                        hash.push_back(q.first);
                        // q.second--; This wont work as q is the first element of the map and hence constant and non modifiable.
                        k--;
                    }
                }
            } // Complete vector copied. Time to push back into result.
            result_f.push_back(hash);
        }
    }
    return result_f;
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