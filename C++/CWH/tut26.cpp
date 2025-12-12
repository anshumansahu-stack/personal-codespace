#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    friend Complex sumComplex(Complex o1, Complex o2); // This declaration
    // is intended to make a friendly function that can access private
    // data freely from outside the class. This is allowed to do anything
    // with the private variables (members).
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i " << endl;
        ;
    }
};

Complex sumComplex(Complex o1, Complex o2) // This is just a function which has the permissions to use the private data from the class. This is called a friend function.
{                                          // This is a function that returns
    // an object in the return value.
    Complex o3;
    // o3.setNumber((o1.a+o2.a),(o1.b+o2.b));//Since this line uses
    // Parameters that are private in the object declaration; it throws an error.
    // without the friend declaration.

    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{

    // The friendly declaration is just a permission to use the function
    // from outside the class and not making the stated function a member
    // function of the class.

    // Which means if you use the function from the main function in the
    // name of any object, it  throws an error.
    // e.g.; here c1.sumcomplex(); throws an error.
    Complex c1, c2, sum;
    c1.setNumber(1, 4);
    c2.setNumber(7, 5);
    c1.printNumber();
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();
    return 0;
}

// Properties of a friend function:
// 1. Not in the scope of class
// 2. Since it is not in the scope of the class, it cannot be called
//    from the object of the class.
// 3. can be invoked without the help of any object.
// 4. Usually contains objects as arguments.
// 5. Can be declared inside public or private sections of the class.
// 6. It cannot access the members directly by their names and need
//    object_name.member_name syntax to access any member.
