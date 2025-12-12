// Example of a Class
#include <iostream>
using namespace std;
// Data used in structures can be accessed from anywhere, very easily.
// Functions Cannot be used in structures.
class Employee
{
private:
    int a, b, c;
    void swap(int *a1, int *a2);

public:
    int d, e;
    void setdata(int a1, int b1, int c1); // Declaration Only
    void getdata();
};
void Employee ::getdata()
{
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;
    cout << "The value of c is " << c << endl;
    cout << "The value of d is " << d << endl;
    cout << "The value of e is " << e << endl;
    cout << "After Swapping a and b" << endl;
    swap(&a, &b);
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;
};
void Employee ::swap(int *a1, int *a2)
{ // Swapping using pointers
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
void Employee ::setdata(int a1, int b1, int c1)
{ //:: is called Scope resolution Operator.
    a = a1;
    b = b1;
    c = c1;
}
int main()
{
    Employee Abhay;
    // Abhay.a=134; Will give an error as variable a is private.These variable can only be assessed by the functions of the class.
    Abhay.d = 620;
    Abhay.e = 49;
    Abhay.setdata(1, 2, 3); // We can set the values of the private variables here.
    Abhay.getdata();
    return 0;
}