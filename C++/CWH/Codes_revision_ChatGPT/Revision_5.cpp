#include <iostream>
using namespace std;
// Create a class Complex which:

// Stores two int members: real and imag.

// Has a constructor to initialize them.

// Overloads the + operator to add two complex numbers.

// Has a function display() to print the number in a + bi format.

class Complex
{
    int real, imag;

public:
    friend Complex add(Complex, Complex);
    Complex()
    {
        real = 0, imag = 0;
    }
    Complex(int x, int y)
    {
        real = x, imag = y;
    }
    void printNumber()
    {
        cout << "The Number is " << real << " + " << imag << " i." << endl;
    }
};
Complex add(Complex o1, Complex o2)
{
    Complex oa((o1.real + o2.real), (o1.imag + o2.imag));
    return oa;
}
int main()
{
    Complex o[2]; // Object Array
    o[0] = Complex(3, 5);
    o[0].printNumber();
    o[1] = Complex(-5, -8);
    o[1].printNumber();
    Complex o3 = add(o[0], o[1]); // Copy constructor (inbuilt) must be invoked
    o3.printNumber();
    return 0;
}