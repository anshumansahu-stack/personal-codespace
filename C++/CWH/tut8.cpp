#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    // int a=45;
    // cout<<"The value of a was "<<a<<endl;
    // a=67;
    // cout<<"The value of a is "<<a<<endl;

    //*****Constants in c++*****
    // const int a=98;
    // cout<<"The value of a was"<<a<<endl;
    // // a=76;//By running the code will show an error saying assignment of read only variable a
    // cout<<"The value of a was"<<a<<endl;

    //*****Manipulators*****(header file iomanip mandatory)
int a=5,b=76,c=115,d=7642;
cout<<"The value of a without setw is "<<a<<endl;
cout<<"The value of b without setw is "<<b<<endl;
cout<<"The value of c without setw is "<<c<<endl;
cout<<"The value of d without setw is "<<d<<endl;
cout<<endl;
cout<<"The value of a with setw is "<<setw(4)<<a<<endl;
cout<<"The value of b with setw is "<<setw(4)<<b<<endl;
cout<<"The value of c with setw is "<<setw(4)<<c<<endl;
cout<<"The value of d with setw is "<<setw(4)<<d<<endl;
// //The header file iomanip provides functionality for the setw function to work. setw function basically just makes sure that the given characters take that much assigned space only. As in the above function, we saw that the given numbers take 4 space, no matter the digit length. 

//*****Operator Precedences*****
// int a=3,b=4;
// int c=a*5+b;
// cout<<c;
//Operator precedences in c++ are as follows: Multiplication, modulo and division are more preferred than that of addition and subtraction, and when two are to be chosen in a single line, the precedences are from left to right.
//For more character precedences, you may search for google in the website cppreference. Jyada yaad rakhne ki bhi programmers ko jarurat nahi hoti!!
//If all the operators are of the same precedence, then associativity takes action.
    return 0;
}