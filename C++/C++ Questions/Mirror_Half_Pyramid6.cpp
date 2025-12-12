#include<iostream>
using namespace std;
int main(){
	int nrow,a,b,c,d,e;
	cout<<"Enter the number of rows you want"<<endl;
	cin>>nrow;
	for(a=nrow;a>0;a--){
		c=a-1;
		for(d=1;d<=c;d++){
			cout<<" ";
		}
		for(b=nrow,e=1;b>0,e<=a;b--,e++){
			cout<<" "<<b;
		}
		cout<<endl;
	}
	return 0;
}
