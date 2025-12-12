// Topic: Default & Parameterized Constructors
// Task:
// Write a class Student with:

// A name and roll as private data members.

// A default constructor that sets name as "Unknown" and roll as 0.

// A parameterized constructor to initialize both members.

// A function display() to print them.
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string Name;
    int Roll_number;

public:
    Student()
    { // Default Constructor
        Name = "Unknown";
        Roll_number = 0;
    }
    Student(string x1, int x2)
    { // Parameterized Constructor
        Name = x1;
        Roll_number = x2;
    }
    void print()
    {
        cout << "The Name of the student is: " << Name << endl;
        cout << "The Roll Number of the student is: " << Roll_number << endl;
    }
};
int main()
{
    Student Anshuman("Anshuman", 3); // Implicit call
    Anshuman.print();
    Student Prince = Student("Prince", 33); // Explicit call
    Prince.print();
    return 0;
}