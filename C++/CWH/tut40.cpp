// tut39 is plain notes.
#include <iostream>
using namespace std;
class student
{
protected:
    int roll_number;

public:
    void set_roll_number(int r)
    {
        roll_number = r;
    };
    void get_roll_number(int)
    {
        cout << "The roll number is " << roll_number << endl;
    };
};
class exam : public student
{
protected:
    int maths;
    int physics;
    int chemistry;

public:
    void set_marks()
    {
        cout << "Enter the marks entered in maths " << endl;
        cin >> maths;
        cout << "Enter the marks entered in physics " << endl;
        cin >> physics;
        cout << "Enter the marks entered in chemistry " << endl;
        cin >> chemistry;
    };
    void get_marks()
    {
        cout << "The marks obtained in maths is " << maths << endl;
        cout << "The marks obtained in physics is " << physics << endl;
        cout << "The marks obtained in chemistry is " << chemistry << endl;
    };
};
class result : public exam
{
protected:
    float percentage;

public:
    void get_percentage()
    {
        percentage = (maths + physics + chemistry) / 3;
        cout << "The percentage obtained by the student is " << percentage << endl;
    };
};
int main()
{
    result Anshuman;
    Anshuman.set_roll_number(03);
    Anshuman.set_marks();
    Anshuman.get_marks();
    Anshuman.get_percentage();
    return 0;
}
//Great example of multilevel inheritance.