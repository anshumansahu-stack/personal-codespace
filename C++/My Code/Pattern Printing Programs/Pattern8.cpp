#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    /*Pattern to print
    11111
     2222
      333
       44
        5*/
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;//number of rows
    cout<<endl;
    for(c=0,b=1;b<=a;b++,c++){
        for(d=1;d<=c;d++){
            cout<<" ";
        }
        f=a-c;
        for(e=1;e<=f;e++){
            g=b;
            cout<<g;
        }
        cout<<endl;
    }

    return 0;
}