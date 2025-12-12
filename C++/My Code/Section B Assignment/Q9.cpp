#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout<<"Enter the number:";
    cin>>a;
    cout<<endl;
    for(int sum=0;;sum=sum+b){
        b=a%10;
        c=a-b;
        a=c/10;
        if(c==0){
            sum=sum+b;
            d=sum;
            break;
        }
    }
    cout<<"The sum of digits is: "<<d<<endl;
    return 0;
}