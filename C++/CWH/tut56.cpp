#include <iostream>
using namespace std;
class Base_class
{
public:
    int var_base;
    virtual void display() // This is a virtual function.
    // This function above allows itself to be overridden by the function of the derived class when called.
    {
        cout << "The base class variable is: " << var_base << endl;
    }
};
class Derived_class : public Base_class
{
    // INHERITED: var_base and display function
public:
    int var_derived;
    void display()
    {
        cout << "The base class variable is: " << var_base << endl;
        cout << "The derived class variable is: " << var_derived << endl;
    }
};
int main()
{
    // POINTERS TO DERIVED CLASS
    Base_class *base_class_pointer;
    Derived_class *derived_class_pointer;
    Base_class obj_base;
    Derived_class obj_derived;
    // We will first point the pointer of the base class to the derived class. That is allowed.
    // The pointer will point to the derived class object but trgger the base class object. lets see...
    base_class_pointer = &obj_derived;
    base_class_pointer->var_base = 47;
    // Derived class variable not defined here so its gonna throw a garbage value.
    base_class_pointer->display();
    // Above runs the display function for the base class.
    // Next were gonna make a derived class pointer point to the derived class.
    // No surprises, we are gonna have the var_base and var_derived in access and display() of derived class runs.
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 47322;
    derived_class_pointer->var_derived = 47091;
    derived_class_pointer->display();
    // What happens when derived class pointer pointe to base class?
    // derived_class_pointer=&obj_base;//This cannot happen.
    return 0;
}