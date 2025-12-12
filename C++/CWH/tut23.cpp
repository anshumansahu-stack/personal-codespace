#include <iostream>
using namespace std;
class Shop
{
    int itemID[100];
    int itemPrice[100];
    int counter;

public:
    void initcounter()
    {
        counter = 0;
    }
    void displayPrice();
    void setPrice();
};
void Shop ::setPrice()
{
    cout << "Enter ID of item number " << counter + 1 << endl;
    cin >> itemID[counter];
    cout << "Enter Price of your item:" << endl;
    cin >> itemPrice[counter];
    counter++;
}
void Shop ::displayPrice()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The ID of your item is: " << itemID[i] << endl;
        cout << "The price of your item is: " << itemPrice[i] << endl
             << endl;
    }
}
int main()
{
    Shop kumti;
    kumti.initcounter();
    int items;
    cout << "Enter the number of items in the shop:" << endl;
    cin >> items;
    for (int i = 0; i < items; i++)
    {
        cout << "Enter the details of your " << i + 1 << "th item" << endl;
        kumti.setPrice();
    }
    cout << endl;
    kumti.displayPrice();

    return 0;
}

// Memory Allocation Procedure for classes:

// All the functions that are required for serving a common purpose for all the objects is
// stored at a single memory location.
// While the different object characteristic features like the name of the object, its properties are
// assigned different memory locations.
// The procedure of storing the memory of a c++ compiler is very smart.