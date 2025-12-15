#include <iostream>
#include <string>
using namespace std;
// bruteforce
void helpAllOccurrences(string &s, const string part, bool &hascut)
{
    int par_len = part.length(), ref_ind;
    bool haspart = false;
    hascut = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (haspart)
        {
            haspart = false;
        }
        else
        {
            ref_ind = 0;
        }
        while (ref_ind < par_len)
        {
            // cout << "working index =" << i << ", working letter=" << s[i] << endl;         // comment
            // cout << "ref_ind=" << ref_ind << ", working letter=" << part[ref_ind] << endl; // comment
            if (s[i] != part[ref_ind])
            {
                // cout << "not same!" << endl;
                if (ref_ind != 0)
                { // Similar part of string present earlier
                    while (ref_ind >= 0)
                    {
                        ref_ind--;
                        if (s[i] == part[ref_ind])
                        {
                            haspart = true;
                            ref_ind++;
                            break;
                        }
                    }
                }
                break;
            }
            else
            {
                if (ref_ind == par_len - 1)
                {
                    s.erase(s.begin() + ref_ind, s.begin() + ref_ind + par_len);
                    i -= par_len;
                    hascut = true;
                    // cout << "string erased! resultant string is: " << s << endl; // comment
                    break;
                }
                else
                {
                    ref_ind++;
                    i++;
                }
            }
        }
    }
    if (hascut == false)
    {
        return;
    }
    helpAllOccurrences(s, part, hascut);
}
void removeAllOccurrences(string &s, string part)
{
    bool hascut = false;
    helpAllOccurrences(s, part, hascut);
}
int main()
{
    string s, part;
    cout << "Enter the string s:" << endl;
    getline(cin, s);
    cout << "enter the substring to be removed:" << endl;
    getline(cin, part);
    removeAllOccurrences(s, part);
    cout << "The resultant string is: " << s << endl;
    return 0;
}