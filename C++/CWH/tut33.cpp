//*****Dynamic Initialization of objects*****
#include <iostream>
using namespace std;
class Bankdeposit
{
    int principal;
    int years;
    float Interestrate;
    float ReturnValue;

public:
    Bankdeposit() {}// This default constructor must be provided... else a runtime error appears stating no constructor for the particular object.
    Bankdeposit(int p, int y, float r); // Principal,Time and Interestrate; Here r must be in a decimal value; r=0.04
    Bankdeposit(int p, int y, int r);   // Rate must be in percentage value; e.g r=4% ==> r=4
    void show();
};
Bankdeposit ::Bankdeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    Interestrate = r;

    ReturnValue = p;
    for (int i = 0; i < y; i++)
    { // Compound Interest
        ReturnValue = ReturnValue * (1 + Interestrate);
    }
}
Bankdeposit ::Bankdeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    Interestrate = float(r) / 100; // Converting percentage to decimal

    ReturnValue = p;
    for (int i = 0; i < y; i++)
    { // Compound Interest
        ReturnValue = ReturnValue * (1 + Interestrate);
    }
}
void Bankdeposit ::show()
{
    cout << endl
         << "Principal amount was " << principal << endl;
    cout << "Return value after " << years << " years"
         << " is " << ReturnValue << endl;
}
int main()
{
    Bankdeposit bd1,bd2,bd3;
    int p, y;
    float r;
    int R;
    cout << "Enter the value of Principal, Time in years and rate in decimal" << endl;
    cin >> p >> y >> r;
    bd1= Bankdeposit(p, y, r);
    bd1.show();
    cout << "Enter the value of Principal, Time in years and rate in percentage" << endl;
    cin >> p >> y >> R;
    bd2= Bankdeposit(p, y, R);
    bd2.show();
    // bd3.show();
    return 0;
}
/* The catch here is that the objects are first initialised by default, and then reinitialised by the parametrized constructors that are 
provided in the code. this is known as initialization of dynamic objects, i.e. the objects are generated while the code is running.
This is useful when the parameters provided can be different and different functions must be initiated to execute the code in a different manner.
*/