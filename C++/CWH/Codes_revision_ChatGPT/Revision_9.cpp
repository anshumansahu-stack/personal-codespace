// Diamond Hybrid Inheritance
#include <iostream>
using namespace std;
// Dry run Prediction:
// First A, then Any one of B or C, then D will be called.

class A
{ // Base Class
public:
    A()
    {
        cout << "A's Constructor Called!" << endl;
    }
};
class B : virtual public A
{
public:
    B()
    {
        cout << "B's Constructor Called!" << endl;
    }
};
class C : virtual public A
{
public:
    C()
    {
        cout << "C's Constructor Called!" << endl;
    }
};
class D : public B, public C
{
public:
    D()
    {
        cout << "D's Constructor Called!" << endl;
    }
};
int main()
{
    D o1;
    return 0;
}
// Both the constructors called. Why?
// If virtual Inheritance then all of the Virtual Base Class Called only once, And all the Parent
// Constructors Called One by one.
// Virtual Class Constructor Order: A->B->C->D.
// Non Virtual Class Constructor Problem: Diamond Problem:
// Constructor Class Call: A->B->A->C->D
// Two declarations of class A, which is the Diamond Problem.