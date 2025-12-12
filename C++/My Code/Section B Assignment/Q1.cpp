#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e;
    cout<<"Enter a 4 digit number"<<endl;
    cin>>a;
    b=a%10;//Last Number
    c=a%1000;
    d=a-c;
    e=d/1000;//First Number
    cout<<"The Sum of first and last digits is "<<b+e<<endl;
    return 0;
}