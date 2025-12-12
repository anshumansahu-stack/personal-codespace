#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    /*Pattern to print
    1
    23
    456
    78910
    1112131415*/
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    cout<<endl;
    d=1;
    for(b=1;b<=a;b++){
        for(c=1;c<=b;c++){
            cout<<d;
            d=d+1;
        }
        cout<<endl;
    }
    return 0;
}