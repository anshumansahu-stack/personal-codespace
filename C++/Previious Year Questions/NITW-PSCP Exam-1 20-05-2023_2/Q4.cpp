#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    for(b=1;b<=a;b++){
        if(b%2!=0){
            cout<<1;
            c=b-1;
            for(d=1;d<=c/2;d++){
                cout<<" 0 1";
            }
        }
        else{
            c=b/2;
            for(d=1;d<=c;d++){
                cout<<"0 1 ";
            }
        }
        cout<<endl;
    }
    return 0;
}