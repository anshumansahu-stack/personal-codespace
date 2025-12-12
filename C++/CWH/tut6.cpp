// There are two types of header files:
// 1. System Header files: it comes with the compiler
#include<iostream>
// 2. User defined header files:It is written by the programmer 
#include "this.h"
// #include"this.h". this will produce an error if this.h is not included in the current directory.
using namespace std;
//The other types of header files are unnecessary to remember, you can search for it in google by typing cpp reference for header files.
//The above website also contains some deprecated header files, means that we cannot use those in our code anymore. Rather new files are included in the given list.
//The shortcut to move down a line /up a line in vscode is alt + up arrow/down arrow.
//The shortcut to Copy a line automatically in vscode is to use alt +shift + up/down arrow.
//The shortcut to create multiple cursors in vscode is to use alt + shift + clicks at the required places.
int main(){
    int a=4,b=5;
    cout<<"Operators in C++"<<endl;
    //Instead of \n, you can type endl at the end of the line to produce a new line in the code.
    cout<<"Following are the types of operators in c++"<<endl;
    //Arithmetic Operators
    cout<<"The value of a+b is "<<a+b<<endl;
    cout<<"The value of a-b is "<<a-b<<endl;
    cout<<"The value of a*b is "<<a*b<<endl;
    cout<<"The value of a/b is "<<a/b<<endl;
    cout<<"The value of a%b is "<<a%b<<endl;
    cout<<"The value of a++ is "<<a++<<endl;
    cout<<"The value of a-- is "<<a--<<endl;
    cout<<"The value of ++a is "<<++a<<endl;
    cout<<"The value of --a is "<<--a<<endl;
    cout<<endl;

    // Assignment operators
    // int a=6,b=5,c=8;
    // here = is an assignment operator.

    //Comparision operators
    cout<<"Given below are the examples of comparision operators:"<<endl;
    cout<<"The value of a==b is "<<(a==b)<<endl;
    cout<<"The value of a<b is "<<(a<b)<<endl;
    cout<<"The value of a>b is "<<(a>b)<<endl;
    cout<<"The value of a<=b is "<<(a<=b)<<endl;
    cout<<"The value of a>=b is "<<(a>=b)<<endl;
    cout<<"The value of a!=b is "<<(a!=b)<<endl;
    cout<<endl;
    //Here 1 denotes that the above statement is true and 0 denotes that the above statement is false in output code.

     //Logical operators
    cout<<"Given below are the examples of logical operators:"<<endl;
    cout<<"The logical and operator (a==b) && (a<b) is"<<((a<<b)&&(a<b))<<endl;
    cout<<"The logical or operator (a==b) || (a<b) is"<<((a<<b)||(a<b))<<endl;
    cout<<"The logical and operator !(a<b) is"<<(!(a<b))<<endl;
    //Here 1 denotes that the above statement is true and 0 denotes that the above statement is false in output code.


    return 0;
}