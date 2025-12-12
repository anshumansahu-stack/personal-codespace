#include<iostream>
using namespace std;
int main(){
    int spaces, stars,rows, a,b,c,e,d,f;
    cout<<"Enter the number of rows"<<endl;
    cin>>rows;
    spaces=rows-1;
    b=1;
    for(a=1;a<=(rows+1)/2;a++){
        for(c=1;c<=spaces;c++){
            cout<<" ";
        }
        for(d=1;d<=b;d++){
            cout<<" *";
        }
        spaces=spaces-2;
        b=b+2;
        cout<<endl;
    }
    //spaces=0, b=7
    b=b-4;
    spaces=2;
    for(a=1;a<=(rows-1)/2;a++){
        for(c=1;c<=spaces;c++){
            cout<<" ";
        }
        for(d=1;d<=b;d++){
            cout<<" *";
        }
        spaces=spaces+2;
        b=b-2;
        cout<<endl;
    }
    return 0;
}
