#include<iostream>
using namespace std;
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
int main(){
    int n,arr[n];
    cout<<"Enter the number of elements you want to sort:"<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Mergesort(arr,0,n-1);
    cout<<n<<" elements in ascending order are as follows:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
