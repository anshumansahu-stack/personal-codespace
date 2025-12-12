#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
//solved
int maxDistinct(string s)
{
    map<char, int> mpp;
    int charcount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mpp.count(s[i]) != 0)
        {
            continue; // letter found
        }
        else
        {
            mpp[s[i]]++;
            charcount++;
        }
    }
    return charcount;
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << maxDistinct(s) << endl;

    return 0;
}