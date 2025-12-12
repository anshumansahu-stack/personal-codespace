#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    /*Pattern to print
    1
    12
    123
    1234
    12345*/
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    cout<<endl;
    for(b=1;b<=a;b++){
        for(c=1;c<=b;c++){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}