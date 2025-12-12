#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,i,j,k;
    /*Pattern Required to Print
    1
    22
    333
    4444
    55555*/
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;//number of rows
    cout<<endl;
    i=1;
    for(b=1;b<=a;b++){
        for(c=1;c<=b;c++){
            d=b;
            cout<<d;
        }
        cout<<endl;
    }
    return 0;
}