#include<iostream>
using namespace std;
int main(){
    int n,a,i,sum=0;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Enter the value of number"<<endl;
        cin>>a;
        sum=sum+a;
    }
    cout<<"The average of the numbers is "<<sum/n<<endl;
    return 0;
}