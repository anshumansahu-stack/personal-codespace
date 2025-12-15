#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int> &bt)
{
    sort(bt.begin(), bt.end()); // O(nlogn)
    int waiting_time = 0, twaiting_time = 0;
    int n = bt.size();
    for (int i = 0; i < n - 1; i++)
    {
        waiting_time += bt[i];
        twaiting_time += waiting_time;
    }
    return twaiting_time / n;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> bt;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        bt.push_back(x);
    } // Input taken
    cout << "The average waiting time is " << solve(bt) << endl;
    return 0;
}