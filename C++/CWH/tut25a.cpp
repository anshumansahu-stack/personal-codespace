#include <iostream>
using namespace std;

class Employee
{
    int id;
    int salary;

public:
    void setID(int i)
    {
        salary = 122; // Salary sets automatically upon setting id.
        cout << "Enter the id of employee " << i << endl;
        cin >> id;
    }
    void getID(int i)
    {
        cout << "The id of the employee " << i << " is " << id << endl;
        cout << "Their corresponding salary is: " << salary << " rupees." << endl;
    }
};
int main()
{
    // Employee abhay,sonu,ghusri,anshuman;
    // abhay.setID();
    // abhay.getID();

    // The above method is not feasible when you are adding the names of employees
    // which are large in number.

    Employee fb[4]; // This is an employee array, it creates the required number of
    // Employees that are stored in the square brackets.

    for (int i = 0; i < 4; i++)
    {
        fb[i].setID(i + 1);
    }
    for (int i = 0; i < 4; i++)
    {
        fb[i].getID(i + 1);
    }
    return 0;
}