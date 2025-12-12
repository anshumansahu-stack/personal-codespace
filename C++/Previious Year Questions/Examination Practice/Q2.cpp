#include<iostream>
using namespace std;
int main(){
    int a,b,c,m,n;
    cout<<"Enter the number of lists"<<endl;
    cin>>n;//number of lists
    for(b=1;b<=n;b++){
        if(b%2!=0){
            cout<<"Enter the number of elements in the "<<b<<" th list"<<endl;
            cin>>m;
            int sum=0;
            for(c=1;c<=m;c++){
                cout<<"Enter the "<<c<<" th number"<<endl;
                cin>>a;
                if(c%2!=0){
                    sum=sum+a;
                }
                else{
                    continue;
                }
            }
            cout<<"The required sum is "<<sum<<endl;
        }
        else{
            cout<<"Enter the number of elements in the "<<b<<" th list"<<endl;
            cin>>m;
            int sum=0;
            for(c=1;c<=m;c++){
                cout<<"Enter the "<<c<<" th number"<<endl;
                cin>>a;
                if(c%2==0){
                    sum=sum+a;
                }
                else{
                    continue;
                }
            }
            cout<<"The required sum is "<<sum<<endl;
        }
    }
    cout<<"OK Thank you"<<endl;
    return 0;
}