/*Objective: To Print The given pattern using nested while loops

*
**
***
****
*****
Also known as Half Pyramid.*/
#include<iostream>
using namespace std;
int main(){
    int i,j,k,l,m,n,p;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>i;
    m=i;
    j=1;
    k=1;
    while(j<=i){
        n=1;
        while(n<=k){
            cout<<"*";
            n++;
        }
        k++;
        cout<<endl;
        j++;
    }

    return 0;
}