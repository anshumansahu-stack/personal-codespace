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
  int m;
  cout<<"Enter the number of rows you want"<<endl;
  cin>>m;//Number of rows
  for(int i=1;i<=m;i++){
  	for(int j=1;j<=m-i+1;j++){
  		cout<<"*";
	  }
	  cout<<endl;
  }

  return 0;
}
