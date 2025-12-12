#include<iostream>
using namespace std;
int main(){
	int number,lumber,digit,cubesum=0;
	cin>>lumber;
	number=lumber;
	while(number>0){
		digit=number%10;
		cubesum+=(digit*digit*digit);
		number=(number-digit)/10;
	}
	if(lumber==cubesum){
		cout<<"The Number is an Armstrong Number"<<endl;
	}
	else{
		cout<<"The Number is not an Armstrong number"<<endl;
	}
	cout<<"OK Thank You"<<endl;
	return 0;
}
