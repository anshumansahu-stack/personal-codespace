#include<iostream>
using namespace std;
int main(){
	int nrow,a,b,c;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=nrow;a>0;a--){
		for(b=nrow-a+1;b>0;b--){
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
