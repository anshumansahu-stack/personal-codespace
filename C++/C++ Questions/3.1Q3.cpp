#include<iostream>
using namespace std;
int main(){
	int num,slim,elim;
	cout<<"PLEASE Enter positive numbers only\n Enter the starting and ending limits respectively:"<<endl;
	cin>>slim>>elim;
	cout<<"The prime numbers are"<<endl;
	for(int i=slim;i<=elim;i++){
		if(i<=2){
			cout<<2<<",";
			i=2;
			continue;
		}
		for(int n=2;n<=i-1;n++){
			if(n==i-1){
				cout<<i<<",";
				break;
			}
			if(i%n==0){
				break;
			}
			else{
				continue;
			}
		}
	}
	cout<<endl;
	cout<<"OK Thank you"<<endl;
	return 0;
}
