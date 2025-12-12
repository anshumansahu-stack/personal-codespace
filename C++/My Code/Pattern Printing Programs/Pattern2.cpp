/*Objective: To Print The given pattern using nested while loops

*****
 ****
  ***
   **
    *
Also known as Inverted Half Pyramid.*/
#include<iostream>
using namespace std;
int main(){
    int i,j,k,l,m,n,p;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>i;//8
    m=i;//8
    j=1;
    while(j<=i){
         p=1;
        l=i-m;//number of spaces 0
         while(p<=l){
             cout<<" ";
             p++;
         }
         k=1;
         while(k<=m){
            cout<<"*";
            k++;
         }
         m--;
        cout<<endl;
        j++;
    }


    return 0;
}