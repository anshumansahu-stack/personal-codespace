#include<iostream>
using namespace std;
int main(){
    int a,b=1,c,d,e,swap=0,n=1,f,g;
    cout<<"Enter a number"<<endl;
    cin>>a;
    for(;d>0;b=b*10){
        c=a%b;
        d=a-c;

    }
    b=b/100;
    for(;b>=1;b=b/10,n=n*10){
        c=a%b;
        d=a-c;
        e=d/b;
        f=e%10;
        g=f*n;
        swap=swap+g;

    }
    cout<<"The swapped number is "<<swap<<endl;
    return 0;
}