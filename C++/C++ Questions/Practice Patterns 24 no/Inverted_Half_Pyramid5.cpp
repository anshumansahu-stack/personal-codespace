#include<iostream>
using namespace std;
int main(){
	int nrow,a,b,c;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=nrow;a>0;a--){
		for(b=nrow,c=a;b>0,c>0;b--,c--){
			cout<<b<<" ";
		}
		cout<<endl;
	}
}
