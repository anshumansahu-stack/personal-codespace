#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    /*Pattern to be printed
        1
       22
      333
     4444
    55555
    */
   cout<<"Enter the number of rows you want"<<endl;
   cin>>a;//no. of rows
   for(b=1;b<=a;b++){
    c=a-b;//no.of spaces
    for(d=1;d<=c;d++){
        cout<<" ";
    }
    for(e=1;e<=b;e++){
        f=b;
        cout<<f;
    }
    cout<<endl;
   }

    return 0;
}