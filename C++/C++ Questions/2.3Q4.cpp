#include<iostream>
using namespace std;
int main(){
    int side1,side2,side3;
    cout<<"Enter the sides in order"<<endl;
    cin>>side1>>side2>>side3;
    if((side1==side2)&&(side1==side3)&&(side2==side3)){
        cout<<"The triangle is equilateral"<<endl;
    }
    else if((side1!=side2)&&(side1!=side3)&&(side2!=side3)){
    	cout<<"The triangle is scalene"<<endl;
	}
	else{
		cout<<"The triangle is isosceles"<<endl;
	}
    return 0;
}
