#include <iostream>// This is the logic, its implementation need to be fixed
#include <string>
using namespace std;
template <class T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
string reverse(string s, int start, int end)
{
    if (start <= end)
        return s;
    Swap(s[start], s[end]);
    reverse(s, start + 1, end - 1);
}
string decimalToBinary(int n)
{
    string result;
    int k = n;
    while (k > 0)
    {
        int i = k % 2; // 0
        result += i;   // 0
        k /= 2;        // 2
    }
    return reverse(result, 0, result.length() - 1);
}
int main()
{
    long long int N;
    cout << "Enter the decimal Number: " << endl;
    cin >> N;
    cout << "Its Decimal Representation is: " << decimalToBinary(N) << endl;
    return 0;
}