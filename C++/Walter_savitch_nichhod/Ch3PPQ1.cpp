#include <iostream>
using namespace std;
int main()
{
    char user1, user2, consent = 'y';
    do
    {
        cout << "Enter the hand of user 1" << endl;
        cin >> user1;
        cout << "Enter the hand of user 2" << endl;
        cin >> user2;
        if (user1 == user2)
        {
            cout << "Nobody wins" << endl;
            cout << "Dono mar gaye khatam kahani" << endl;
        }
        else
        {
            if (((user1 == 'P') || (user1 == 'p')) && ((user2 == 'R') || (user2 == 'r')))
            {
                cout << "user1 wins" << endl;
                cout << "Paper Covers Rock" << endl;
            }
            else if (((user1 == 'R') || (user1 == 'r')) && ((user2 == 'P') || (user2 == 'p')))
            {
                cout << "user2 wins" << endl;
                cout << "Paper Covers Rock" << endl;
            }
            else if (((user1 == 'R') || (user1 == 'r')) && ((user2 == 'S') || (user2 == 's')))
            {
                cout << "user1 wins" << endl;
                cout << "Rock Breaks Scissors" << endl;
            }
            else if (((user1 == 'S') || (user1 == 's')) && ((user2 == 'R') || (user2 == 'r')))
            {
                cout << "user2 wins" << endl;
                cout << "Rock Breaks Scissors" << endl;
            }
            else if (((user1 == 'S') || (user1 == 's')) && ((user2 == 'P') || (user2 == 'p')))
            {
                cout << "user1 wins" << endl;
                cout << "Scissors Cut Paper" << endl;
            }
            else if (((user1 == 'P') || (user1 == 'p')) && ((user2 == 'S') || (user2 == 's')))
            {
                cout << "user2 wins" << endl;
                cout << "Scissors Cut Paper" << endl;
            }
            else
            {
                cout << "Invalid Input. Please enter the right Character." << endl;
                cout << "Nobody wins" << endl;
            }
        }
        cout << "Do you want to play again?" << endl;
        cin >> consent;
    } while (consent == 'y');
    cout << "Thanks for playing the game!" << endl;
    return 0;
}