#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;
//Submitted
unordered_map<char, int> uniqueElements(const string s)
{
    unordered_map<char, int> mpp;
    for (char i : s)
    {
        mpp[i]++;
    }
    return mpp;
} // O(n)
long long minCost(string s, vector<int> &cost)
{
    long long min_cost = LLONG_MAX;
    unordered_map<char, int> mpp = uniqueElements(s);
    for (auto it : mpp)
    {
        char a = it.first;
        long long inst_cost = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != a)
            {
                inst_cost += cost[i]; // total cost of keeping that character
            }
        }
        min_cost = min(min_cost, inst_cost); // minimal value stored
    }
    return min_cost;
} // ©leetcode
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> cost;
    cout << "Enter " << N << " costs:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        cost.push_back(x);
    } // Input taken
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "The minimum cost required is:" << minCost(s, cost) << endl;
    return 0;
}