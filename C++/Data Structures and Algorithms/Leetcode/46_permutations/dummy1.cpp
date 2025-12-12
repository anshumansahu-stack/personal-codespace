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
    map<int, int> mpp;
    cout << "Incrementation" << endl;
    for (int &i : nums)
    {
        mpp[i]++;
    }
    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }
    cout << "Decrementation" << endl;
    for (int &i : nums)
    {
        mpp[i]--;
    }
    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }//Incremetation and decrementation logic works just fine in maps.
    return 0;
}