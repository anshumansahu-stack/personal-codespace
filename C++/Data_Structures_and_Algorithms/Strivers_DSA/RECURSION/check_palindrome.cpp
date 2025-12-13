#include <iostream>
#include <string>
using namespace std;
template <class T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
void Palindrome(string &s, int start, int end)
{
    if (start >= end)
        return;
    Swap(s[start], s[end]);
    Palindrome(s, start + 1, end - 1);
}
int main()
{
    string s;
    cout << "Enter a string" << endl;
    cin >> s;
    string s1 = s;
    Palindrome(s, 0, s.length() - 1);
    if (s == s1)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not palindrome" << endl;
    }
    return 0;
}