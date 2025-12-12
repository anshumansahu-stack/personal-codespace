#include<iostream>
using namespace std;
int main(){//Pascals Triangle
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    for(b=1;b<=a;b++){
        d=a-b;//number of gaps
        for(e=1;e<=d;e++){
            cout<<" ";
        }
        for(c=1;c<=b;c++){
            
        }
        cout<<endl;
    }
    return 0;
}