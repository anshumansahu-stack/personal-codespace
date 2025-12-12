#include<iostream>
using namespace std;
int main(){
    double x,y=1,num,eps=0.00001;
    cout<<"Enter the number you want the square root of:";
    cin>>num;
    x=num;
    cout<<endl;
    while(x-y>eps){
        x=(x+y)/2;
        y=num/x;
    }
    cout<<"Square root of "<<num<<" is "<<x<<endl;
    return 0;
}