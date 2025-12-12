#include <iostream>
using namespace std;
class Employee
{
    int id;
    static int count; // This variable associates with classes. For this to be a static variable, you have
    //  to declare it outside the class as well. It is declared again in row 35.
    // ----> By default this variable is initialized from zero. No need of further Initialization.
    // A static count is defined outside the class and any editing in its initialization value is carried out outside the class
    // Here it is row 35.

    // int count; // This variable cannot pass amongst objects, i.e. cannot count the number of objects correctly.
    // The variables declared here have the memory associated with individual objects only and not the entire class.
    //----> The output lines will be " The id of this employee is blah and this is employee number 1" For all the three objects.
    // Because all the three objects have their distinct counting variables that cannot be initialized simultaneously.
public:
    void setData()
    {
        cout << "Enter the id:" << endl;
        cin >> id;
        count++;
    }
    void getData()
    {
        cout << "The id of this Employee is " << id << " and this is employee number " << count << endl;
    }

    static void getcount()
    {
        cout << "The value of count is " << count << endl;
        // cout<<id;//This line will throw an error as the static member function uses the static variables only.
    }
};

int Employee ::count=1; // Default value is zero. Any Initialization in the number is supported in this line.

int main()
{
    Employee Abhay, sonu, anshuman;
    // Count is the static data member of class Employee.
    // Abhay.id=1;
    // Abhay.count=1; // Cannot do this as id and count are private

    Employee::getcount();
    Abhay.setData();
    Abhay.getData();

    Employee::getcount();
    sonu.setData();
    sonu.getData();

    Employee::getcount();
    anshuman.setData();
    anshuman.getData();

    return 0;
}