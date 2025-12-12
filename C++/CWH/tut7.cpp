#include<iostream>
using namespace std;
int c=45;
int main(){
    //**********Built in data types**********
    int a,b,c;
    cout<<"Enter the value ofa"<<endl;
    cin>>a;
    cout<<"Enter the value ofb"<<endl;
    cin>>b;
    c=a+b;
    cout<<"The sum is"<<c<<endl;
    cout<<"The global value of c is"<<::c<<endl;
    // :: is called the scope resolution operator.

    // *****Float, double and long double literals*********
    // float d=98.6F;
    // long double e=98.6L;
    // cout<<"The value of d is "<<d<<endl<<"The value of e is "<<e<<endl;

    // cout<<"The size of 98.6 is"<<sizeof(98.6)<<endl;
    // cout<<"The size of 98.6f is"<<sizeof(98.6f)<<endl;
    // cout<<"The size of 98.6F is"<<sizeof(98.6F)<<endl;
    // cout<<"The size of 98.6l is"<<sizeof(98.6l)<<endl;
    // cout<<"The size of 98.6L is"<<sizeof(98.6L)<<endl;

    //*****Reference variables*****
    //Humaare jaise anek naam hai, waise ek computer code me ek variable ko anek naam dene ke liye hum reference variables ka concept use karte hain.
    // int x=45;
    // int &y=x;
    // cout<<"The value of x is"<<x<<endl;
    // cout<<"The value of y is"<<y<<endl;

    //*****Typecasting*****
    //Computer code ke beech me ek data type ko dusre data type me convert karne ke liye Typecasting ka istemaal kiya jaata hai.
    int p=45;
    float q=45.987;
    cout<<"The value of p is "<<p<<endl;
    cout<<"The value of q is "<<q<<endl;
    cout<<"The value of (float)p is "<<(float)p<<endl;
    cout<<"The value of float(p) is "<<float(p)<<endl;
    cout<<"The value of (int)q is "<<(int)q<<endl;
    cout<<"The value of int(q) is "<<int(q)<<endl;
    cout<<"The expression p+q is"<<p+q<<endl;
    cout<<"The expression p+int(q) is"<<p+int(q)<<endl;
    cout<<"The expression float(p)+q is"<<float(p)+q<<endl;


    return 0;

}