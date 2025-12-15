#include <iostream>
#include <algorithm> // required for reverse()
#include <cctype>    //required for tolower() and isalnum()
#include <string>
using namespace std;
int main()
{
    string name;
    cout << "Enter your name:" << endl;
    // cin >> name; // Only the first word
    // cout << "Hi " << name << "!" << endl;
    getline(cin, name);
    // cout << "Hi " << name << "!" << endl;
    // reverse(name.begin(), name.end());
    // cout << "Hi " << name << "!" << endl;

    // // Determining the length of a string
    // cout << "The length of whatever you just said is " << name.length() << endl;
    // int i = name.length();

    // //String Concatenation
    // string comments;
    // cout << "What else do you wanna tell?" << endl;
    // getline(cin, comments);
    // name += " ";
    // name += comments;
    // cout << name << endl;
    // cout << "The length of whatever you just said is " << name.length() << endl;

    // // Reversing a string
    // reverse(name.begin(), name.end());
    // cout << name << endl;
    // reverse(name.begin(), name.end());
    // // erasing letters
    // // name.erase(name.begin() + i,name.end());//erasing last words
    // name.erase(name.begin(), name.begin() + i); // Erasing early words
    // cout << name << endl;

    // // Pushing and popping back characters
    // i = 1;
    // while (i <= 10)
    // {
    //     name.push_back('x');
    //     i++;
    // }
    // cout << name << endl;
    // while (i > 1)
    // {
    //     name.pop_back();
    //     i--;
    // }
    // cout << name << endl;

    // // Converting uppercase chars to LOWERCASE
    // int i = 0;
    // while (i < name.length())
    // {
    //     name[i] = tolower(name[i]); // WOULD HAVE BEEN GREAT USE IN VALID PALINDROME
    //     i++;
    // }
    // cout << name << endl;

    // Knowing if the character is an alphanumeric or not
    // string temp_name;
    // int i = 0;
    // while (i < name.length())
    // {
    //     if (isalnum(name[i]) == false)
    //     {
    //         i++;
    //         continue;
    //     }
    //     temp_name.push_back(name[i]);//very helpful in valid palindrome
    //     i++;
    // }
    // cout << temp_name << endl;

    

    return 0;
}