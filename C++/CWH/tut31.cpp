//Constructor Overloading in C++
#include<iostream>
using namespace std;
class Complex{
	int a,b;
	public:
		Complex(){
			a=0;b=0;
		}
		Complex(int x){
			a=x;b=0;
		}
		Complex(int x,int y){
			a=x,b=y;
		}
		void printdata(){
			cout<<"The value of the complex number is: "<<a<<" + "<<b<<"i"<<endl;
		}
};
int main(){
	Complex c1;
	c1.printdata();
	
	Complex c2(3);
	c2.printdata();
	
	Complex c3(3,5);
	c3.printdata();
	return 0;
}
