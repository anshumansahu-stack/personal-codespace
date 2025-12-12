#include<iostream>
using namespace std;
int main(){
    int a,n1,n2,x,b,c,d,e,f,g,h,i,j,count;
    cout<<"Enter the first year"<<endl;
    cin>>n1;
    cout<<"Enter the second year"<<endl;
    cin>>n2;
    cout<<"Enter the digit x"<<endl;
    cin>>x;
    cout<<"The years are"<<endl;
    for(b=n1;b<=n2;b++){
        c=b;
        for(d=1;d>0;){
            d=c%10;
            if(d==x){
                cout<<b<<endl;
                count=count+1;
                break;
            }
            f=c-d;
            d=f/10;
        }
    }
    cout<<"The number of such years is "<<count<<endl;
    return 0;
}