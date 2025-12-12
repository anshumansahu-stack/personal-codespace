#include <iostream>
using namespace std;
class c2;
class c1
{
    int val1;

public:
    void indata(int a)
    {
        val1 = a;
    }
    void display()
    {
        cout << val1;
    }
    friend void exchange(c1 &val1, c2 &val2);
};
class c2
{
    int val2;

public:
    void indata(int a)
    {
        val2 = a;
    }
    void display()
    {
        cout << val2;
    }
    friend void exchange(c1 &val1, c2 &val2);
};
void exchange(c1 &x, c2 &y) // Using Call by reference
{
    int temp = x.val1; // Always use x.variable to declare a variable outside any given function of the object.
    x.val1 = y.val2;
    y.val2 = temp;
}
int main()
{
    c1 oc1;
    c2 oc2;
    oc1.indata(156);
    oc2.indata(89);

    cout << "The value of the variables before swapping is ";
    oc1.display();
    cout << " & ";
    oc2.display();
    cout << endl;

    exchange(oc1, oc2);

    cout << "The value of the variables before swapping is ";
    oc1.display();
    cout << " & ";
    oc2.display();
    cout << endl;

    cout << " USN Raju Touch: OK Thankyou!!"; // He was a fav lecturer!
    return 0;
}