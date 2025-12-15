#include <iostream>
#include <vector>
using namespace std;
void HelperFunction(vector<char> &s, int startind, int endind)
{
    if (startind >= endind)
        return;
    swap(s[startind], s[endind]);
    HelperFunction(s, startind + 1, endind - 1);
}
void reverseString(vector<char> &s)
{
    HelperFunction(s, 0, s.size() - 1);
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<char> s;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        char x;
        cin >> x;
        s.push_back(x);
    } // Input taken
    reverseString(s);
    for (char i : s)
    {
        cout << i;
    }
    return 0;
}