#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std; // Submitted
int vowelcount(string temp_s)
{
    int count = 0;
    for (int i = 0; i < temp_s.length(); i++)
    {
        if (temp_s[i] == 'a' || temp_s[i] == 'e' || temp_s[i] == 'i' || temp_s[i] == 'o' || temp_s[i] == 'u')
        {
            count++;
        }
    }
    return count;
} // working, O(length of word)
string reverseWords(string s)
{
    string temp_s;
    int refvow = 0;
    int i = 0, wordcount = 0, refind;
    while (i <= s.length())
    {
        if (i == 0 || s[i - 1] == ' ')
        {
            refind = i;
        }
        if (s[i] == ' ' || i == s.length())
        {
            wordcount++;

            int vowcount = vowelcount(temp_s);

            // vowel count function needs to be written
            if (wordcount == 1)
            {
                refvow = vowelcount(temp_s);
            }
            else
            {
                if (vowcount == refvow)
                {
                    reverse(s.begin() + refind, s.begin() + i);

                    // vowels reversed. reset tempstring
                }
            }
            while (temp_s.empty() == false)
            {
                temp_s.pop_back();
            }
            i++;
            continue;
        }
        temp_s.push_back(s[i]);
        i++;
    }
    return s;
}
int main()
{
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);
    cout << reverseWords(s);
    return 0;
}