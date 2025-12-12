#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    char alpha='a';
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    for(b=1;b<=a;b++){
        for(c=1;c<=b;c++){
            cout<<alpha;
            alpha++;
        }
        cout<<endl;
    }
    return 0;
}