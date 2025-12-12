/*Objective: To Print The given pattern using nested while loops

    *
   **
  ***
 ****
*****
Also known as Inverted Half Pyramid.*/
#include<iostream>
using namespace std;
int main(){
    int i,j,k,l,m,n,o,p;
    cout<<"Enter The number of rows you want"<<endl;
    cin>>i;
    for(j=1;j<=i;j++){
        m=i;
        l=m-j;//no.of spaces
        for(k=1;k<=l;k++){
            cout<<" ";
        }
        for(n=1;n<=j;n++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}