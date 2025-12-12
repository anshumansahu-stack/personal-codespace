#include <iostream>
using namespace std;
class Complex
{

    int real, imaginary;

public:
    Complex() : real(0), imaginary(0) {};
    Complex(int a, int b) : real(a), imaginary(b) {}
    void getData()
    {
        cout << "The value of the Complex Number is: " << real << " + " << imaginary << "j." << endl;
    }
    // NEW: Addition of this operator.
    // this operator points to the object in which the member function is invoked.
    Complex &getObject()
    {
        return *this;
    }
};
int main()
{
    int n;
    cout << "Enter the number of Complex Numbers you want: " << endl;
    cin >> n;
    Complex *obj = new Complex[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter the value of real and imaginary parts of number " << i + 1 << ":" << endl;
        cin >> a >> b;
        obj[i] = Complex(a, b);
    }
    for (int j = 0; j < n; j++)
    {
        obj[j].getData();
    }
    delete[] obj; // Cleanup for memory
    return 0;
}