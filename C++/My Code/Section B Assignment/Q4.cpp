#include<iostream>
using namespace std;
int main(){
    int i,n,sum=0;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        sum=sum+(i*i);
    }
    cout<<"The required sum of squares is "<<sum<<endl;
    
    return 0;
}