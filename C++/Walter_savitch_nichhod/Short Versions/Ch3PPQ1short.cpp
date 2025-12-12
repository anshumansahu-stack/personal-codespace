#include <iostream>
using namespace std;

int main()
{
    char user1, user2, consent = 'y';
    do
    {
        cout << "Enter the hand of user 1 (R, P, S): ";
        cin >> user1;
        cout << "Enter the hand of user 2 (R, P, S): ";
        cin >> user2;

        user1 = tolower(user1);// This function is inbuilt in iostream library. Used to convert uppercase letters to lowercase.
        user2 = tolower(user2);

        if (user1 == user2)
        {
            cout << "Nobody wins" << endl;
            cout << "Dono mar gaye khatam kahani" << endl;
        }
        else if ((user1 == 'p' && user2 == 'r') || (user1 == 'r' && user2 == 's') || (user1 == 's' && user2 == 'p'))
        {
            cout << "user1 wins" << endl;
            if (user1 == 'p')
                cout << "Paper Covers Rock" << endl;
            else if (user1 == 'r')
                cout << "Rock Breaks Scissors" << endl;
            else if (user1 == 's')
                cout << "Scissors Cut Paper" << endl;
        }
        else if ((user2 == 'p' && user1 == 'r') || (user2 == 'r' && user1 == 's') || (user2 == 's' && user1 == 'p'))
        {
            cout << "user2 wins" << endl;
            if (user2 == 'p')
                cout << "Paper Covers Rock" << endl;
            else if (user2 == 'r')
                cout << "Rock Breaks Scissors" << endl;
            else if (user2 == 's')
                cout << "Scissors Cut Paper" << endl;
        }
        else
        {
            cout << "Invalid Input. Please enter the right character." << endl;
            cout << "Nobody wins" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> consent;
    } while (tolower(consent) == 'y');

    cout << "Thanks for playing the game!" << endl;
    return 0;
}
// What all i learnt from this short code
// If a single condition contains multiple subconditions, they can be easily nested in an if else statement.