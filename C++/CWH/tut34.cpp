#include <iostream>
using namespace std;

class Number
{
    int a;

public:
    Number() // This default constructor is required to initialize an object
    {
        a = 0;
    };
    Number(int num)
    {
        a = num;
    }
    //When no copy constructor is found, compiler supplies its own copy constructor.
    Number(Number &obj)
    {
        cout << "Copy Constructor called!!" << endl;
        a = obj.a;
    }

    void display()
    {
        cout << "The number is " << a << endl;
    }
};
int main()
{
    Number x(30), y(69), z(45), z2;
    x.display();
    y.display();
    z.display();
    Number z1(z), x1(x), y1(y); // Copy constructor runs here three times because it is being initialised.
    x1.display();
    y1.display();
    z1.display();
    // z1 or x1 or y1 should exactly resemble z or x or y.Copy constructors are used for the same purpose.

    // If the copy constructor is commented out and then the value of the number is initialized, will there be a runtime error?
    // No! there will be no error invoked, since the compiler itself assigns a separate default copy constructor for the object
    // parameters you apply in the arguments. Copy constructor, as the name suggests, will be run by default by the compiler ONLY
    //  when an object is created and Not, when a value is assigned to the object, i.e.

    z2 = z;
    // The above line will not invoke the copy constructor, since the value of an object is ASSIGNED to another object.

    Number z3 = z;
    // The above line WILL trigger the copy constructor, since a new object is being CREATED here.
    return 0;
}