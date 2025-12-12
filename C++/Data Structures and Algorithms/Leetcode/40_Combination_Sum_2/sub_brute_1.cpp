#include <iostream>
#include <vector>
#include <map>
using namespace std;
// candidate[i] is from 1 to 50
//  Hasharray needs to be fed to a map
// Our objective is to identify the unique vectors that are fed, based on their number of elements.
// for instance, [1,6,1] and [1,1,6] are the same.
int main()
{
    int N1;
    cout << "Enter the number of vectors:" << endl;
    cin >> N1;
    vector<vector<int>> nums(N1);
    for (int i = 0; i < N1; i++)
    {
        int N;
        cout << "Enter the number of elements of " << i + 1 << " th vector" << endl;
        cin >> N;
        cout << "Enter " << N << " elements:" << endl;
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            nums[i].push_back(x);
        } // Input taken_f
    }
    map<map<int, int>, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        map<int, int> hash;
        for (int j = 0; j < nums[i].size(); j++)
        {
            hash[nums[i][j]]++;
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
    for (vector<int> i : result_f)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}