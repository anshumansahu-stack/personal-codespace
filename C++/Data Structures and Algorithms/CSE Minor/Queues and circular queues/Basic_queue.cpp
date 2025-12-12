#include<iostream>
#include<climits>
using namespace std;
class queue{
	private:
		int arr[100];
		int front,rear,maxsize;
	public:
		queue(int n){
			maxsize=n;
			front=0;
			rear=0;
		}
		int size(){
			return rear-front;
		}
		void enqueue(int n){//Inserting at the rear
			if(size()>=maxsize){
				cout<<"Enqueue Unsuccessful: Queue is already full!"<<endl;
				return;
			}
			arr[rear++]=n;
		}
		int dequeue(){
			if(size()<=0){
				cout<<"Dequeue Unsuccessful: Queue is already empty!"<<endl;
				return INT_MIN;
			}
			return arr[front++];
		}
		int Front(){
			if(size()<=0){
				cout<<"Front Unsuccessful: Queue is already empty!"<<endl;
				return INT_MIN;
			}
			return arr[front];
		}
		int Rear(){
			if(size()<=0){
				cout<<"Rear Unsuccessful: Queue is already empty!"<<endl;
				return INT_MIN;
			}
			return arr[rear-1];
		}
		bool isFull(){
			if(size()>=maxsize){
				return true;
			}
			return false;
		}
		bool isEmpty(){
			if(size()<=0){
				return true;
			}
			return false;
		}
};
int main(){
	//Might Add later as per convenience.
	return 0;
}
