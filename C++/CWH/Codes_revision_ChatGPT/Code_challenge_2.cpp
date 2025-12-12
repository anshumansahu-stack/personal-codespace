#include <iostream>
#include <string>
using namespace std;
// Make a class Student that:

// Stores name and roll as private members

// Has a parameterized constructor to initialize both

// Has a display() function to print them
class Student
{
    string name;
    int roll;

public:
    Student(string n1, int n2) : name(n1), roll(n2) {};
    void printDetails()
    { // display name was low key lol
        cout << "The name of the student is " << name << endl;
        cout << "The Roll Number of the student is: " << roll << endl;
    }
};
int main()
{
    Student Abhay = Student("Abhay", 03);
    Abhay.printDetails();
    return 0;
}