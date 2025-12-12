#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    /*Pattern Required to print
    11111
    2222
    333
    44
    5
    */
   cout<<"Enter the number of rows you want"<<endl;
   cin>>a;//number of rows
   cout<<endl;
   
   for(e=0,b=1;b<=a;b++,e++){
    d=a-e;
    for(c=1;c<=d;c++){
        cout<<b;
    }
    cout<<endl;
   }
    return 0;
}