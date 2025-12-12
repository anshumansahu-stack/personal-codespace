//#include<iostream>
//using namespace std;
//int main(){
//	int n,i;
//	cout<<"Enter the number:";
//	cin>>n;
//	cout<<endl;
//	if(n==0){
//		cout<<"The number is zero"<<endl;
//	}
//	else if(n<0){
//		cout<<"The number is negative "<<endl;
//	}
//	else if(n==1){
//		cout<<"The number is neither prime nor composite"<<endl;
//	}
//	else{
//		for(i=2;i<=n-1;i++){
//			if(n%i==0){
//				cout<<"The number is composite"<<endl;
//				break;
//			}
//			else{
//				if((n%i!=0)&&(i==n-1)){
//					cout<<"The number is prime"<<endl;
//				}
//				if(n%i!=0){
//					continue;
//				}
//			}
//		}
//	}
//	return 0;
//}
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool flag=0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			cout<<"The number is Non-Prime"<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"The Number is prime"<<endl;
	}
	return 0;
}
