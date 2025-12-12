#include <iostream>
using namespace std;
class A
{
public:
    void greet()
    {
        cout << "Good Morning Everyone!" << endl;
    }
};
class B
{
public:
    void greet()
    {
        cout << "Good Afternoon Everyone!" << endl;
    }
};
class C : public A, public B
{
public:
    void greet()
    {
        int consent;
        cout << "Enter the time of the day:" << endl
             << "1 for Morning" << endl
             << "2 for Afternoon" << endl;
        cin >> consent;
        if (consent == 1)
        {
            A::greet();
        }
        else
        {
            B::greet();
        }
    }
};
int main()
{
    B o3;
    o3.greet();
    A o2;
    o2.greet();
    C o1;
    o1.greet();
    return 0;
}