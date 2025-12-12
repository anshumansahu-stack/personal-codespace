#include<iostream>
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
void Insertionsortdesc(int arr[], int n){//Descending Order
int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<n-1;j++){
            if(arr[i]>=arr[j]){
                swap(arr[i],arr[j]);
            }
            else{
                continue;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements to be sorted"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers to be sorted"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The unsorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    Insertionsortasc(arr,n);
    cout<<"The sorted array in ascending order is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    Insertionsortdesc(arr,n);
    cout<<"The sorted array in descending order is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
}
