#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void swap( int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void Insertionsortasc(int arr[], int n){//Ascending Order
int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<n-1;j++){
            if(arr[i]<=arr[j]){
                swap(arr[i],arr[j]);
            }
            else{
                continue;
            }
        }
    }
}
void Merge(int arr[],int first, int mid, int last){
    int first1=first,last1=mid,first2=mid+1,last2=last;
    int temp[last-first+1],index=0;
    while((first1<=last1)&&(first2<=last2)){
        if(arr[first1]<arr[first2]){
            temp[index++]=arr[first1++];
        }
        else if(arr[first1]>arr[first2]){
            temp[index++]=arr[first2++];
        }
        else{
            temp[index++]=arr[first1++];
            temp[index++]=arr[first2++];
        }
    }
    while(first1<=last1){
        temp[index++]=arr[first1++];
    }
    while(first2<=last2){
        temp[index++]=arr[first2++];
    }
    for(int i=0;i<index;i++){
        arr[first+i]=temp[i];
    }
}
void Mergesort(int arr[],int first,int last){
    if(first<last){
        int mid=(first+last)/2;
        Mergesort(arr,first,mid);
        Mergesort(arr,mid+1,last);
        Merge(arr,first,mid,last);
    }
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
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// A function to perform counting sort based on the digit represented by exp (10^0, 10^1, etc.)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array to store sorted elements
    int count[10] = {0}; // There are only 10 possible digits (0-9)
    
    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that it now contains actual positions of digits in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to do Radix Sort
void Radixsort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit. The exp is 10^i, where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}
void randGen(int arr[], int n) {
    // Seed the random number generator with the current time
    srand(time(0));

    // Fill the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void copyValues(int brr[],int& m,int arr[],int& n){
	n=m;
	for(int i=0;i<n;i++){
		arr[i]=brr[i];
	}
}
void menu(){
	int response;
	cout<<"Enter the response corresponding to the function required:"<<endl;
	do{
		cout<<"1: Generate and Print Random array"<<endl;
		cout<<"2: Sort array using Insertion Sort"<<endl;
		cout<<"3: Sort array using Merge Sort"<<endl;
		cout<<"4: Sort array using Quick Sort"<<endl;
		cout<<"5: Sort array using Radix Sort"<<endl;
		cout<<"6: Print the sorted Array"<<endl;
		cout<<"7: Exit"<<endl;
		cin>>response;
		int n,arr[n];
		switch(response){
			case 1:{
				int m;
				cout<<"Enter the number of elements in the array"<<endl;
				cin>>m;
				int brr[n];
				randGen(brr,m);
				copyValues(brr,m,arr,n);
				cout<<"The Generated Array having "<<n<<" elements is:"<<endl;
				print(brr,m);
				break;
			}
			case 2:{
				Insertionsortasc(arr,n);
				cout<<"The array has been sorted. Press 6 to print."<<endl;
				break;
			}
			case 3:{
				Mergesort(arr,0,n-1);
				cout<<"The array has been sorted. Press 6 to print."<<endl;
				break;
			}
			case 4:{
				Quicksort(arr,0,n-1);
				cout<<"The array has been sorted. Press 6 to print."<<endl;
				break;
			}
			case 5:{
				Radixsort(arr,n);
				cout<<"The array has been sorted. Press 6 to print."<<endl;
				break;
			}
			case 6:{
				cout<<"The array is:"<<endl;
				print(arr,n);
				break;
			}
			case 7:{
				cout<<"The program has been successfully terminated. Thank you for using the program."<<endl;
				break;
			}
		}
	}while(response!=7);
	
}
int main(){
	menu();
	return 0;
}
