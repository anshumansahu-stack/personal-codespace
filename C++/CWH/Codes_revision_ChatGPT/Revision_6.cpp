#include <iostream>
using namespace std;
class Animal
{
public:
    Animal() // Even if you dont explicitly call this constructor,
    // This runs First whenever Derived class is called
    {
        cout << "Animal Created!" << endl;
    }
};
class Dog : public Animal
{
public:
    Dog() // This constructor runs after the Base class Constructor is executed.
    {
        cout << "Dog Created!" << endl;
    }
};
int main()
{
    Dog Tommy;
    return 0;
}