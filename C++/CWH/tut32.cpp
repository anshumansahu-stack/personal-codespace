//Constructor with default Arguments

//Between previous and this code, the difference lies in just the way the default arguments
//(whose values are already initialized themselves while being declared as parameters)
//are provided. The code works the same as previous.
#include<iostream>
using namespace std;

class Complex{
	int a,b;
	public:
		Complex(int x=3,int y=5){
			a=x,b=y;
		}
		void printdata(){
			cout<<"The value of the complex number is: "<<a<<" + "<<b<<"i"<<endl;
		}
};

//NOTE: Overloading works only with functions having different sets of parameters. 
// Hence the below written code throws an error saying the functions of same arguments cannot be overloaded.

//class Complex{
//	int a,b;
//	public:
//		Complex(int x=0,int y=0){
//			a=x,b=y;
//		}
//		Complex(int x,int y=0){
//			a=x,b=y;
//		}
//		Complex(int x,int y){
//			a=x,b=y;
//		}
//		void printdata(){
//			cout<<"The value of the complex number is: "<<a<<" + "<<b<<"i"<<endl;
//		}
//};
int main(){
	Complex c1;
	c1.printdata();
	
	Complex c2(5);
	c2.printdata();
	
	Complex c3(5,8);
	c3.printdata();
	return 0;
}
