#include<iostream>
using namespace std;
int main(){
	int nrow,a,b;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=nrow;a>0;a--){
		for(b=a;b>0;b--){
			cout<<b<<" ";
		}
		cout<<endl;
	}
	return 0;
}
