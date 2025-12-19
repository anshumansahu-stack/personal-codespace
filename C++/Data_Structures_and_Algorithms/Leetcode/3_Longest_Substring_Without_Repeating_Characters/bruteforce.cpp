#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mpp;
    int maxlen = 0;
    int left = 0, right = 0;
    while (right < s.length())
    {
        cout << "The index in consideration is " << right << endl;
        if (mpp[s[right]] != 0)
        { // What if we found that
            cout << "duplicate found!" << endl;
            // update maxlen
            maxlen = max(maxlen, right - left);
            cout << "maxlen=" << maxlen << endl;
            // Iterate left till right equals the concened char plus 1
            do
            {
                cout << "char " << s[left] << " is not equal to " << s[right] << endl;
                if (s[left] != s[right])
                {
                    mpp[s[left]]--;
                }
                left++;
                cout << "value of left is " << left << endl;
            } while (s[left] != s[right] && left <= right);
            // at this stage s[right]==s[left]
            if (left != right)
            { // The string doesnt contain only one letter
                mpp[s[left]]--;
                left++;
                cout << "left incremented post loop! left=" << left << endl;
            }
        }
        else
        {
            mpp[s[right]]++;
            cout << "char " << s[right] << " visited" << endl;
        }
        right++;
    }
    return maxlen;
}
int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "The length of the longest substring is:" << lengthOfLongestSubstring(s) << endl;
    return 0;
}