#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string &s)
{
    string tempstr;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << "Character: " << s[i] << endl; // comment
        int a = int(s[i]);
        // cout << "its integer value is : " << a << endl; // comment
        if ((a < 65 && a > 90) && (a < 97 && a > 122))
        {
            // cout << "Skipped!" << endl; // Comment
            continue;
        } // Filter out everything except letters
        if (a >= 65 && a <= 90)
        {
            // cout << char(a + 32) << " Pushed!" << endl; // Comment
            tempstr.push_back(char(a + 32));
        } // convert all capital to small
        if ((a >= 48 && a <= 57) || (a >= 97 && a <= 122))
        {
            // cout << char(a) << " Pushed!" << endl; // Comment
            tempstr.push_back(char(a));
        }
    } // tempstr updated
    // cout << "tempstr: " << tempstr << endl; // Comment
    int startind = 0, endind = tempstr.length() - 1;
    while (startind < endind)
    {
        if (tempstr[startind] != tempstr[endind])
        {
            return false;
        }
        startind++;
        endind--;
    }
    return true;
}
int main()
{
    string s;
    cout << "Enter a string" << endl;
    getline(cin, s);
    if (isPalindrome(s))
    {
        cout << "Valid Palindrome!" << endl;
    }
    else
    {
        cout << "Invalid palindrome!" << endl;
    }
    // cout << char('0') << endl;
    return 0;
}