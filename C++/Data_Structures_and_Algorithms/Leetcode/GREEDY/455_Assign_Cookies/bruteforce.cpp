#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    // s=cookies(right) and g=children(left)
    sort(g.begin(), g.end());
    sort(s.begin(), s.end()); // O(2*nlogn) for both total
    int left = 0, right = 0;  // Lets place cookies on left and children on right
    int count = 0;
    while (left < g.size() && right < s.size())
    {
        // we are checking one cookie to be given to a single child.
        // if s[left]>=g[right], one cookie given so left++, one child satisfied so right++, and count++
        //  else no cookie given so left stays same, child unsatisfied only left++.
        //  I am being greedy by assigning different amount of cookies first and thinking later,
        // SO this is GREEDY ALGORITHM.
        if (g[left] <= s[right])
        {
            left++, right++, count++;
            // cout << "all 3 incremented!" << endl;
        }
        else
        {
            right++;
            // cout << "right incremented!" << endl;
        }
    }
    return count;
}
int main()
{
    int N1;
    cout << "Enter the number of children(g):" << endl;
    cin >> N1;
    vector<int> g;
    cout << "Enter " << N1 << " greed factors:" << endl;
    for (int i = 0; i < N1; i++)
    {
        int x;
        cin >> x;
        g.push_back(x);
    } // Children Input taken
    int N2;
    cout << "Enter the number of cookies(s):" << endl;
    cin >> N2;
    vector<int> s;
    cout << "Enter " << N2 << " cookie sizes:" << endl;
    for (int i = 0; i < N2; i++)
    {
        int x;
        cin >> x;
        s.push_back(x);
    } // Cookies Input taken
    cout << "The number of Content Children is: " << findContentChildren(g, s);
    return 0;
}