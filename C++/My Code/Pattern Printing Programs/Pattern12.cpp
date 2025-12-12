#include<iostream>
using namespace std;
int main(){
    /*input=5 then output
    a
    ab
    abc
    abcd
    abcde*/
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    for(b=1;b<=a;b++){
        char alpha='a';
        for(c=1;c<=b;c++){
            cout<<alpha;
            alpha++;
        }
        cout<<endl;
    }
    return 0;
}