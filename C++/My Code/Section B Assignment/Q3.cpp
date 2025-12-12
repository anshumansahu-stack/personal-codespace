#include<iostream>
using namespace std;
int main(){
    int a,b,c,n1,n2,n3;
    cout<<"Enter the three numbers"<<endl;
    cin>>a>>b;
    if(a>b){
        n1=a;n2=b;
    }
    else{
        n1=b;n2=a;
    }
    cin>>c;
    if(c>n1){
        n3=n2;n2=n1;n1=c;
    }
    else if((c<=n1)&&(c>n2)){
        n3=n2;n2=c;
    }
    else{
        n3=c;
    }
    cout<<"The maximum number is "<<n1<<endl;
    if(n1%2==0){
        cout<<"The maximum number is even"<<endl;
    }
    if(n1%2!=0){
        cout<<"The maximum number is odd"<<endl;
    }
    return 0;
}