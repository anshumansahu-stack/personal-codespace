#include <iostream>
#include <vector>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    // One lemonade costs 5 rupees.
    int count5 = 0, count10 = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        { // This can always be collected
            count5++;
            // cout << "5 in" << endl;
        }
        else if (bills[i] == 10)
        { // 10 rupees bill
            count5--;
            count10++;
            if (count5 < 0)
            {
                return false;
            }
            // cout << "10 in, 5 out" << endl;
        }
        else
        { // 20 rupees bill
            if (count5 >=1 && count10>=1)
            {
                count5--;
                count10--;
                if (count5 < 0 || count10 < 0)
                {
                    return false;
                }
                // cout << "20 in, 5 out, 10 out" << endl;
            }
            else
            {
                count5 -= 3;
                if (count5 < 0)
                {
                    return false;
                }
                // cout << "20 in, 3x5 out" << endl;
            }
        }
    }
    return true;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> bills;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        bills.push_back(x);
    } // Input taken
    if (lemonadeChange(bills))
    {
        cout << "I can satisfy all customers" << endl;
    }
    else
    {
        cout << "I cannot satisfy all customers" << endl;
    }
    return 0;
}