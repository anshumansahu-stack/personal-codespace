//Given an unsorted array arr containing only non-negative integers,
//your task is to find a continuous subarray (a contiguous sequence of elements)
//whose sum equals a specified value target. You need to return the 1-based indices
//of the leftmost and rightmost elements of this subarray.
#include<iostream>
using namespace std;
class Solution{
	int arr[10000],target_value;
	int maxsize,ind1,ind2;
	bool truth;
	public:
		void getarr(){
			cout<<"Enter the number of elements of the array ";
			cin>>maxsize;
			for(int i=0;i<maxsize;i++){
				cin>>arr[i];
			}
			cout<<"Enter the target value"<<endl;
			cin>>target_value;
		}//array me values aagayi, target value milgayi
		void returnindices(){
			for(int i=0;i<maxsize;i++){
				ind1=i;
				if(arr[ind1]==target_value){
					cout<<"["<<ind1+1<<","<<ind1+1<<"]"<<endl;
					break;
				}
				else{
					int sum=arr[ind1];truth=false;
					for(int j=ind1+1;j<maxsize;j++){
						sum+=arr[j];
						if(sum==target_value){
							ind2=j;
							truth=true;
							break;
						}
						else{
							continue;
						}
					}
					if(sum==target_value){
						break;
					}
					else{
						continue;
					}
				}
			}
			if(truth==true){
				cout<<"["<<ind1+1<<","<<ind2+1<<"]"<<endl;
			}
			else{
				cout<<"[-1]"<<endl;//error
			}
		}
};
int main(){
	Solution Array;
	Array.getarr();
	Array.returnindices();
	return 0;
}
