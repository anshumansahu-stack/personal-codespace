#include<iostream>
using namespace std;
int main(){//inverted Pyramid
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;
    c=a;
    for(b=1;b<=a;b++){
        d=a-c;//Number of Gaps
        for(e=1;e<=d;e++){
            cout<<" ";
        }
        for(f=1;f<=c;f++){
            cout<<"* ";
        }
        c--;
        cout<<endl;
    }
    return 0;
}