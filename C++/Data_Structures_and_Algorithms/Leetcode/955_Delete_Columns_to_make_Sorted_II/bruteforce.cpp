#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Just the start matters
int minDeletionSize(vector<string> &strs)
{
    int len = strs[0].length();
    int count = 0;
    bool inOrder = false;
    for (int i = 0; i < len; i++)
    {
        if (inOrder == false)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (int(strs[j][i]) < int(strs[j - 1][i]))
                {
                    count++;
                    break;
                }
                if (j == strs.size())
                {
                    inOrder = true;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    return count;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<string> strs;
    cout << "Enter " << N << " strings:" << endl;
    for (int i = 0; i < N; i++)
    {
        string x;
        cin >> x;
        strs.push_back(x);
    } // Input taken
    cout << minDeletionSize(strs);
    return 0;
}