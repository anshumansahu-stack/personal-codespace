#include <iostream>
using namespace std;
// Create a base class Person with:

// A protected member age.

// A derived class Student that sets and prints the age.

// 👉 Task: Use inheritance to access the protected variable correctly.
class Person
{
protected:
    int age;
};
class Student : public Person
{
    // Inherited Members:
    // Protected: int age
public:
    void setAge(int x)
    {
        age = x;
    }
    void printAge()
    {
        cout << "The age of the student is " << age << endl;
    }
};
int main()
{
    Student Anshuman;
    Anshuman.setAge(21);
    Anshuman.printAge();
    return 0;
}
