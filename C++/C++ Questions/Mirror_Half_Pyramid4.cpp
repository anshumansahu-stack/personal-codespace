#include<iostream>
using namespace std;
int main(){
	int nrow,a,b,c,d;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=nrow;a>0;a--){
		c=nrow-a;
		for(d=1;d<=c;d++){
			cout<<"  ";
		}
		for(b=a;b>0;b--){
			cout<<" "<<b;
		}
		
	cout<<endl;
	}
	return 0;
}
