#include<iostream>
using namespace std;
int main(){
    //What is a pointer? ----> Pointer is a data type that holds the address of other data types.
    int a=3;
    int*b=&a;
    //& Operator---> (Address of) operator
    cout<<"The address of value of a is "<<b<<endl;
    cout<<"The address of value of a is "<<&a<<endl;
    //* Operator---> (Value at) Address pointer {Also called Dereference operator}
    cout<<"The value of address of a is "<<*b<<endl;
    // Pointer to Pointer
    int **c=&b;
    cout<<"The address of value of b is "<<c<<endl;
    cout<<"The address of value of b is "<<&b<<endl;
    cout<<"The value of address of b is "<<*c<<endl;
    cout<<"The value of address of address of b is "<<**c<<endl;


    return 0;
}