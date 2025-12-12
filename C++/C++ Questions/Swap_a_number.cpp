#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int reverse;
	int lastdigit;
	while(n>0){
		lastdigit=n%10;
		reverse=reverse*10+lastdigit;
		n=(n-lastdigit)/10;
	}
	cout<<"The reverse is "<<reverse<<endl;
	return 0;
}
