#include<iostream>
using namespace std;
void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
void Partition(int arr[],int first,int last,int& loc){
	int piv_element=arr[first];//location of the pivot element
	int left=first+1;
	int right=last;
	while(left<right){
		while(arr[left]<piv_element){
			left++;
		}
		while(arr[right]>piv_element){
			right--;
		}
		if(left<right){
			swap(arr[left],arr[right]);
		}
	}
	loc=right;
	swap(arr[first],arr[right]);
}
void Quicksort(int arr[],int first,int last){
	if(first<last){
	int loc;//Just assuming to avoid the garbage value
	Partition(arr,first,last,loc);
	Quicksort(arr,first,loc-1);
	Quicksort(arr,loc+1,last);
	}
}
int main(){
    int n;
    cout<<"Enter the number of elements you want to sort:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Quicksort(arr,0,n-1);
    cout<<n<<" elements in ascending order are as follows:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
