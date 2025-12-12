#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();
    int m = s.size();
    int l = 0;
    int r = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (l < n && r < m)
    {
        if (g[l] <= s[r])
        {
            r++;
            l++;
        }
        else
        {
            r++;
        }
    }
    return l;//Basically where the children pointer ends is the result of the code.
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
