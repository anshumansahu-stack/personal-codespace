#include<iostream>
using namespace std;
int main(){
    int a[7][7];
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cin>>a[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}