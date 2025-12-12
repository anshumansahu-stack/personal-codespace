/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,p,space;
    space=1;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>a;//Number of rows
    for(b=1;b<=a;b++){
        p=65;
        c=(a-b)+1;
        for(d=1;d<=c;d++){
            cout<<char(p);
            p++;
        }
        if(b>=2){
            for(e=1;e<=space;e++){
                cout<<" ";
            }
            space=space+2;
        }
        if(b==1){
            p=p-2;
            c=c-2;
            for(d=c;d>=0;d--){
                cout<<char(p);
                p--;
            }
        }
        else{
            p=p-1;
            c=c-1;
            for(d=c;d>=0;d--){
                cout<<char(p);
                p--;
            }
        }
        cout<<endl;
    }
    
    return 0;
}