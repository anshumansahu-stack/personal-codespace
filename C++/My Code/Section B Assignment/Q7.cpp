#include<iostream>
using namespace std;
int main(){
    int n,a,i,b,c,d,e,f,g,h,num,sum=0;
    cout<<"Enter the smaller number "<<endl;
    cin>>a;
    cout<<"Enter the larger number "<<endl;
    cin>>b;
    for(i=a;i<=b;i++){
        num=i;
        c=num%10;
        for(e=1;num!=0;e++){
            sum=sum+(c*c*c);
            d=num-c;
            num=d/10;
            c=num%10;
        }
        if(sum==i){
            cout<<i<<",";
        }
    }
    cout<<num<<endl;
    return 0;
}