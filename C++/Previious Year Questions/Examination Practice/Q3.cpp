#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,n,sum;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;//number of odd terms
    a=0;b=1;sum=0;
    c=(2*n)-2;
    for(d=1;d<=c;d++){
        e=a+b;
        if(d%2!=0){
            sum=sum+e;
        }
        a=b;
        b=e;

    }
    cout<<"The sum of odd terms is "<<sum<<endl;
    cout<<"OK Thank u";
    return 0;
}