#include <iostream>
using namespace std;

// Forward Declaration
class Complex; // This line declares that the stated class is present ahead.

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumRealComplex(Complex o1, Complex o2);
    int sumCompComplex(Complex o1, Complex o2);
};

class Complex
{
    int a, b;

    // INDIVIDUALLY DECLARING THE FUNCTIONS AS FRIENDS
    //  friend int Calculator::sumRealComplex(Complex o1, Complex o2); // This still throws an error when the
    //  given function is still inside a class. Hence the function has to be declared separately
    //  outside of the class. A function can only be declared as a friend of another class if it is
    //  present outside the class, because if you want to use the variables that are private from the class
    //  then you cannot access those veriables directly from inside the class.
    //  friend int Calculator::sumCompComplex(Complex o1, Complex o2);

    // ALTERNATIVE: DECLARING THE ENTIRE CALCULATOR CLASS AS FRIEND.
    friend class Calculator; // This is called a friend class.
public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i " << endl;
        ;
    }
};
int Calculator::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a); // Class complex cannot provide the private data directly
    // to this class.Hence the above line throws an error when used directly.
}
int Calculator::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(6, -3);
    Calculator Calc;
    cout << "The sum of real part of o1 and o2 is " << Calc.sumRealComplex(o1, o2) << endl;
    cout << "The sum of complex part of o1 and o2 is " << Calc.sumCompComplex(o1, o2) << endl;
    return 0;
}