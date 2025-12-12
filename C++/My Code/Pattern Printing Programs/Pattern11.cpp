#include<iostream>
using namespace std;
int main(){
/*input=5 then output
a
bb
ccc
dddd
eeeee
*/
    char alpha='a';
    int p,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>p;
    for(b=1;b<=p;b++){
        for(c=1;c<=b;c++){
            cout<<alpha;
        }
        alpha++;
        cout<<endl;
    }
    return 0;
}