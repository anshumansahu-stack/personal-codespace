#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,n1,n2,x;
    cout<<"Enter the first year"<<endl;
    cin>>n1;
    cout<<"Enter the second year"<<endl;
    cin>>n2;
    cout<<"Enter the digit x"<<endl;
    cin>>x;
    cout<<"The years between "<<n1<<" and "<<n2<<" that contain the digit "<<x<<" are"<<endl;
    for(b=n1;b<=n2;b++){
        if(b%4==0){
            c=b;

            for(e=1;e>0;){
                d=c%10;
                if(x==d){
                    cout<<b<<endl;
                    break;
                }
                e=c-d;
                c=e/10;
            }
        }
        else{
            continue;
        }
    }
    return 0;
}