#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    // Creating a constructor
    // Constructor is a special member function with the same name as of the class.
    // It is automatically invoked(called) whenever an object is created.
    // It is used to initialize the objects of the class.

    // Previously we had to make separate functions like Setdata, Getdata to initialize the private
    // Variables. we dont have to do it anymore with the help of constructors.

    Complex(); // Constructor Declaration. () can be replaced by (void).

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i " << endl;
        ;
    }
};

Complex ::Complex()
{   // This is a Default Constructor. This is automatically called upon the formation
    // of an object. It initializes the value of any object.It is called default since it takes no
    // Parameters.
    a = 0;
    b = 0;
    cout << "Hello World" << endl;
}
int main()
{
    Complex c1;
    c1.printNumber();
    Complex c2;
    c2.printNumber();
    Complex c3;
    c3.printNumber();
    return 0;
}

// Any other member function of the class must have a return type specified to it. e.g., int functionname
//  Constructor shouldnt have a return type attached to it.

// CHARACTERISTICS OF CONSTRUCTORS:

// 1. It should be declared at the public section of the class.
// 2. They are automatically invoked when the object is created.
// 3. They cannot return values and do not have return types.
// 4. It can have default arguments.
// 5. We cannot refer to their address.
