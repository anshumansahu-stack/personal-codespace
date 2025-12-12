#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout<<"Enter the present population:";
    cin>>a;
    cout<<endl<<"Enter the percentage growth:";
    cin>>b;
    cout<<endl;
    int sum=0,count=0;
    c=((a*b)/100);
    sum=sum+c;
    for(d=1,c=a;sum<=50000;c=((sum*b)/100),d++){
        cout<<"End of "<<d<<"th year"<<endl;
        sum=sum+c;
        cout<<"The population is "<<sum<<endl;
        count++;
    }
    cout<<"The number of years required for population to reach 50000 is "<<count<<endl;
    return 0;
}