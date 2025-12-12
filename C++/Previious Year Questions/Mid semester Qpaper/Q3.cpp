#include<iostream>
using namespace std;
int main(){
    int n,a,b,c,d,e,f,g,h,i,j,fl,sl;
    cout<<"Enter the number of numbers "<<endl;
    cin>>n;//Number of Numbers

    cout<<"Enter the first number"<<endl;
    cin>>b;
    cout<<"Enter the second number"<<endl;
    cin>>c;
    if(b>c){
        fl=b;sl=c;
    }
    else{
        fl=c;sl=b;
    }
    for(a=3;a<=n;a++){
        cout<<"Enter the "<<a<<"th number"<<endl;
        cin>>d;
        if(d>fl){
            sl=fl;
            fl=d;
        }
        else if((d<a)&&(d>b)){
            sl=d;
        }
        else{
            continue;
        }
    }
    cout<<"The first largest number is "<<fl<<endl;
    cout<<"The second largest number is "<<sl<<endl;
    return 0;
}