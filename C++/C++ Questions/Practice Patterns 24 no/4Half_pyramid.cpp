#include<iostream>
using namespace std;
int main(){
	int nrows,a,b;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrows;
	for(a=1;a<=nrows;a++){
		for(b=1;b<=a;b++){
			cout<<b<<" ";
		}
		cout<<endl;
	}
	return 0;
}
