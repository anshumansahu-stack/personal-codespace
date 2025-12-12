#include <iostream>
using namespace std;
// ✍️ Your Task:
// Create two classes:
// Employee (Base class):
// int id
// float salary
// Constructor that takes both and prints them.
// Programmer (Derived class):
// int languageCode (e.g., 9 for C++, 10 for Java)
// Constructor that takes all three values and prints a message:
class Employee
{ // Base Class
protected:
    int id;
    float salary;

public:
    Employee()
    {
        cout << "Employee Constructor Executed!" << endl;
        cout << "Enter The Employee ID:" << endl;
        cin >> id;
        cout << "Enter The Salary of the Employee(in LPA):" << endl;
        cin >> salary;
    }
    void printData()
    {
        cout << "Employee ID: " << id << " Salary in LPA: " << salary << endl;
    }
};
class Programmer : public Employee
{
protected:
    int languageCode;

public:
    Programmer()
    {
        cout << "Programmer Constructor called!" << endl;
        cout << "Enter the Language ID: " << endl;
        cin >> languageCode;
        printData();
        cout << "Language Code: " << languageCode;
    }
};
int main()
{
    Programmer Abhay;
    return 0;
}