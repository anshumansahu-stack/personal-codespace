#include<iostream>
using namespace std;
int main(){
	int nrow, a,b;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=nrow;a>0;a--){
		for(int c=1;c<=a;c++){//or for( int c=nrow;c>0;c--) Also works effectively.
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
