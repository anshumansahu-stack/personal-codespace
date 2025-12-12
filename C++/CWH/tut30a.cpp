#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    Complex();             // Default Constructor
    Complex(int x, int y); // Parameterized Constructor

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i " << endl;
        ;
    }
};
Complex ::Complex() // This function is a default constructor and runs automatically upon formation.
// This accepts no parameters.
{
    a = 0;
    b = 0;
    cout << "Hello World" << endl;
}
Complex ::Complex(int x, int y) // This function is a parameterized constructor.
// This accepts two parameters.
// Helps in easy initialization of values.
{
    a = x;
    b = y;
    cout << "Hello World" << endl;
}
int main()
{
    // Using Default Constructor
    Complex a;
    a.printNumber();
    // Implicit Call of Parametrized Constructor
    Complex b(3, 7);
    b.printNumber();
    // Explicit Call of Parametrized Constructor
    Complex c = Complex(5, -7);
    c.printNumber();
    return 0;
}
//I accidentally Overloaded Two Constructors.