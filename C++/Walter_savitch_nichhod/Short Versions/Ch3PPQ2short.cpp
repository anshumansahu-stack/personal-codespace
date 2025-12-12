#include <iostream>
using namespace std;

int main()
{
    double interest_due, total_amount, min_payment, AccBalance;
    char consent;
    do
    {
        cout << "Enter the account balance: ";
        cin >> AccBalance;

        // Interest calculation
        if (AccBalance <= 1000)
        {
            interest_due = (1.5 / 100) * AccBalance;
        }
        else
        {
            interest_due = 15 + (AccBalance - 1000) * (1.0 / 100);
        }

        // Total Amount
        total_amount = AccBalance + interest_due;

        // Minimum Payment
        if (total_amount <= 10)
        {
            min_payment = total_amount;
        }
        else
        {
            min_payment = max(10.0, total_amount * 0.1);//Calculates the maximum of two values.
        }

        cout << "The interest due is $" << interest_due << " Dollars." << endl;
        cout << "The total amount due is $" << total_amount << " Dollars." << endl;
        cout << "The minimum payment is $" << min_payment << " Dollars." << endl;

        cout << "Do you want to repeat the calculation? (y/n): ";
        cin >> consent;
    } while (tolower(consent) == 'y');

    cout << "Thanks for using our services!" << endl;
    return 0;
}
