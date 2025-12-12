#include<iostream>
using namespace std;
int main(){
	int nrows,a,b;
	cout<<"Enter the number of rows"<<endl;
	cin>>nrows;
	for(a=1;a<=nrows;a++){
		b=nrows-a+1;
		for(int c=1;c<=b;c++){
			cout<<c<<" ";
		}
		cout<<endl;
	}
	return 0;
}
