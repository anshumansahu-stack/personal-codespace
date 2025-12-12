//****** CONSTRUCTORS IN DERIVED CLASSES IN C++
// We can use constructors in derived class in C++.
// If the base class constructor does not have any arguments, then there is no need of any constructor in derived class.
// If there are one or more than one arguments in the base class constructor then derived class need to pass arguments tothe base class constructor.
// If both base and derived class have constructors then base class constructor is called first. (VVVVV imp.)

//***** CONSTRUCTORS IN MULTIPLE INHERITANCE
// In multiple Inheritance, Base classes are constructed in the order in which they appear in the class declaration.
// In multilevel Inheritance, Constructors are executed in the order of inheritance.

// SPECIAL SYNTAX:
// C(a1,a2,b1,b2,c1,c2):A(a1,a2),B(b1,b2){
// Basically Variables of their respective constructors passed down to the respective base classes... Stay tuned to find out,
// }

// SPECIAL CASE OF VIRTUAL BASE CLASS:
// The constructors of Virtual Base class Invoked before the Nonvirtual Base Class
// If there are multiple virtual base classes then they are invoked in the order declared.
// Any non virtual base class are constructed before the derived class is constructed.
