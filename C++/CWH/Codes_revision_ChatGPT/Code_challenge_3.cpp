#include <iostream>
using namespace std;
// Create a class Rectangle with:

// Private members: length and breadth

// A constructor to initialize them

// Create a member function area() to calculate area.

// In main():

// Dynamically create a Rectangle object using a pointer (new)

// Call the area() function using the pointer

// Finally, free the memory using delete
class Rectangle
{
    int length, breadth;

public:
    Rectangle(int c, int d) : length(c), breadth(d) {};
    int area()
    {
        return length * breadth;
    }
};
int main()
{
    Rectangle *r1 = new Rectangle(3, 4);
    cout << "The area of the rectangle r1 is: " << (*r1).area() << endl;
    delete r1;
    return 0;
}