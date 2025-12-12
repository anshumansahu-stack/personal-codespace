#include<iostream>
#include<climits>
using namespace std;
class stack{
	private:
		int arr[100];
		int initvalue,maxint;
	public:
		stack(int n){
			initvalue=0;
			maxint=n;
		}
		void push(int n){
			if(initvalue>=maxint){
				cout<<"Push unsuccessful: stack is full!"<<endl;
				return;
			}
			arr[initvalue++]=n;
		}
		int pop(){
			if(initvalue<=0){
				cout<<"Pop unsuccessful: stack is empty!"<<endl;
				return INT_MIN;
			}
			return arr[--initvalue];
		}
		int peek(){
			if(initvalue<=0){
				cout<<"Peek unsuccessful: stack is empty!"<<endl;
				return INT_MIN;
			}
			return arr[initvalue-1];
		}
		bool isEmpty(){
			if(initvalue<=0){
				return true;
			}
			return false;
		}
		bool isFull(){
			if(initvalue>=maxint){
				return true;
			}
			return false;
		}
};
int main(){
	//Whatever code is required... leave empty for now
	return 0;
}
