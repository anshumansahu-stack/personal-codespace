#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,fn,sn;
    cout<<"Enter the number of numbers in the list"<<endl;
    cin>>a;
    if(a<2){
        cout<<"Error: Atleast 2 numbers are required "<<endl;
    }
    if(a>=2){
        cout<<"Enter the 1st number"<<endl;
        cin>>b;
        cout<<"Enter the 2nd number"<<endl;
        cin>>c;
        if(b<c){
            fn=c,sn=b;
        }
        else{
            fn=b;sn=c;
        }
        for(d=3;d<=a;d++){
            cout<<"Enter the "<<d<<"th number"<<endl;
            cin>>e;
            if(e>fn){
                sn=fn;
                fn=e;
            }
            else if((e<fn)&&(e>sn)){
                sn=e;
            }
            else{
                continue;
            }
        }
    cout<<"The second largest number is "<<sn<<endl;
    }
    cout<<"OK Thank you"<<endl;

    return 0;
}