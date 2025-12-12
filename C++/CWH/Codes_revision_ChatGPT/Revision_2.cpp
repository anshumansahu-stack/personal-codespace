// Topic: Static Data Members and Static Methods
// Task:
// Create a class Counter that:

// Has a static variable count that tracks how many objects are created.

// Has a method showCount() that displays current count.

// Test with 3 objects and show how count behaves.
#include <iostream>
using namespace std;
class Student // I am using the same class
{
private:
    string Name;
    int Roll_number;
    static int Student_count;

public:
    Student()
    { // Default Constructor
        Student_count++;
        cout << "This is the Time a Default constructor is called, for Student " << Student_count << endl;
        Name = "Unknown";
        Roll_number = 0;
    }
    Student(string x1, int x2)
    { // Parameterized Constructor
        Student_count++;
        cout << "This is the Time a Parameterized constructor is called, for Student " << Student_count << endl;
        Name = x1;
        Roll_number = x2;
    }
    void showCount()
    {
        cout << "The Current Count of the students is: " << Student_count << endl;
    }
    void printData()
    {
        cout << "The Name of the student is: " << Name << endl;
        cout << "The Roll Number of the student is: " << Roll_number << endl;
    }
    ~Student()
    {
        cout << "Object " << Student_count << " Destroyed!" << endl;
        Student_count--;
    }
};
int Student::Student_count = 0; // Redeclaration of the static Variable
int main()
{
    cout << "This is how CWH Taught Things to me. We are officially inside the main function." << endl;
    Student Anshuman("Anshuman", 3); // Implicit call
    Anshuman.printData();
    Anshuman.showCount();
    {
        cout << "We are officially Inside the block" << endl;
        Student Indrapal("Indrapal", 32); // Implicit call
        Indrapal.printData();
        Indrapal.showCount();
        Student Prince = Student("Prince", 33); // Explicit call
        Prince.printData();
        Prince.showCount();
    }
    cout << "We are Back into the main function. Here my Code ends. OK Thank you!" << endl;
    return 0;
}