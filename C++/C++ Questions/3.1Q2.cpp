#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter the number"<<endl;
	cin>>num;

	if(num<0){
		cout<<"The number is negative"<<endl;
	}
	else{
		switch(num){
		case 2:
			cout<<"The number is prime"<<endl;
			break;
		case 1:
			cout<<"The number is neither prime nor composite"<<endl;
			break;
		case 0:
			cout<<"The number is not divisible by any number"<<endl;
			break;
		default:
			for(int i=2;i<=num-1;i++){
				if(num%i==0){
					cout<<"The number is composiite"<<endl;
					break;
				}
				else{
					if(i==num-1){
						cout<<"The number is prime"<<endl;
						break;
					}
					if(num%i!=0){
						i++;
					}
				}
			}
	}
	}
	cout<<"OK Thank you"<<endl;
	return 0;
}
