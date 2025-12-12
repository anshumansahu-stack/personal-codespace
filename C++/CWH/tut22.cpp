#include <iostream>
#include <string>
using namespace std;
// OOPs- Classes and Objects
// C++--> initially called--> C with classes by stroustroff
// class--> extension of Structures(in C)
// Structures had limitations--> Members are public, No methods
// Classes -->Structures + more
// Classes can have methods and properties.
// Classes --> can make few members as private and few as public.
// Structures in c++ are typedefed. Means even if you dont apply the typedef command, you can directly call the structure by the name you want.
// You can declare objects alongwith the class declaration.
/* Class employee{
Class definition
} sonu,abhay,anshuman;*/
// abhay.salary=8 makes no sense if salary is private.

//****Nesting of member functions*****
class binary
{
    // private:
    string s; // By default all members mentioned in a class are private.

public:
    void read(void);
    void chk_bin(void);
    void ones_compliment(void);
    void display(void);
};

void binary::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "The number is not in binary" << endl;
            exit(0);
            // Here this command is used to illustrate the peaceful termination of the program without errors.
            // if the given condition is not satisfied.

            // Else if the command were exit(1) or any other integer in the brackets, that would indicate an error formation in the
            // code and the code has terminated with an error.
            // Please research on this topic.
        }
    }
}

void binary::ones_compliment(void)
{
    for (int i = 0; i < s.length(); i++) // s.length() function outputs the length of the string s.
    {
        if (s.at(i) == '0') // s.at(i) outputs the string character at position i.
        {
            s.at(i) = '1';
            continue;
        }
        if (s.at(i) == '1')
        {
            s.at(i) = '0';
            continue;
        }
    }
}

void binary::display(void)
{
    chk_bin(); // Function nested instead of being used in the main function.
    cout << "Displaying your binary number" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
}
int main()
{

    binary b;
    b.read();
    // b.chk_bin();// This function is being nested.This function can be used by other functions if this is made private.
    // This is the use of nesting of member functions.
    cout << endl;
    b.display();
    cout << endl;
    b.ones_compliment();
    cout << endl;
    b.display();

    return 0;
}