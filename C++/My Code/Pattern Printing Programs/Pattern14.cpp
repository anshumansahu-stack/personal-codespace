#include<iostream>
using namespace std;
int main(){//Triangular Pyramid
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    for(b=1;b<=a;b++){
        c=a-b;//number ofgaps
        for(d=1;d<=c;d++){
            cout<<" ";
        }
        for(e=1;e<=b;e++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}