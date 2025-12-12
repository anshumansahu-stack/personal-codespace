#include<iostream>
using namespace std;
int main(){
	int nrow,a,b;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=1;a<=nrow;a++){
		for(b=1;b<=a;b++){
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
