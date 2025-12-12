#include <iostream>
#include <vector>
#include <map>
using namespace std;
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
    cout << "Original Vector:" << endl;
    cout << "[";
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
    cout << endl;
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    } // hasharray stored
    // Print the map
    for (auto it : mpp)
    { // since it is a copy of a map element. no need of dereferencing.
        cout << it.first << "->" << it.second << endl;
    }
    cout << endl;
    for (auto &it : mpp)
    { // since it is a map element. no need of dereferencing.
        cout << it.first << "->" << it.second << endl;
    }
    // so we need to use exactly the map element for dereferencing --1
    //  Decoding the hashmap mpp into a vector
    vector<int> decoded_num;
    for (auto &it : mpp)
    {
        if (it.second != 0)
        {
            while(it.second!=0){
                decoded_num.push_back(it.first);
                it.second--;
            }
        }
    }
    cout << "[";
    for (int i : decoded_num)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}