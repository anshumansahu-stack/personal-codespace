// The following code takes input of two points and output their distance
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void displayPoint()
    {
        cout << "The point is (" << x << "," << y << ")." << endl;
    }
    friend double Distance(Point P, Point Q);
};
double Distance(Point P, Point Q)
{
    return sqrt(((Q.x) - (P.x)) * ((Q.x) - (P.x)) + ((Q.y) - (P.y)) * ((Q.y) - (P.y)));
}
int main()
{
    int a, b, c, d;
    cout << "Enter the x and y coordinates of point P respectively." << endl;
    cin >> a >> b;
    cout << "Enter the x and y coordinates of point P respectively." << endl;
    cin >> c >> d;
    Point P(a, b);
    Point Q(c, d);
    P.displayPoint();
    Q.displayPoint();
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "The distance between two points P and Q is " << Distance(P, Q) << " units." << endl;
    return 0;
}