// Topic: Friend Function
// Task:
// Create a class Box with a private member length.
// Write a friend function printLength(Box b) that prints its length.
#include <iostream>
using namespace std;

class Box
{
    int length;

public:
    friend void printLength(Box o1);
    Box()
    {
        length = 0;
    }
    Box(int l)
    {
        length = l;
    }
    ~Box() {};
};
void printLength(Box o1)
{
    cout << "The length of the box is " << o1.length << " metres" << endl;
}
int main()
{
    Box Mango_juice(5);
    printLength(Mango_juice);
    return 0;
}