#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,m,n;
    cout<<"Enter the number of UG Programs"<<endl;
    cin>>a;//No. of Programs
    for(b=1;b<=a;b++){
        cout<<"Enter the number of students in batch "<<b<<endl;
        cin>>c;//No of students
        int maxr=0,minr=0;
        for(d=1;d<=c;d++){
            cout<<"Enter the JEE Rank of "<<d<<"th student"<<endl;
            cin>>e;
            if(d==1){
                minr=e;maxr=e;
            }
            else{
                if(e>maxr){
                    maxr=e;
                }
                if(e<minr){
                    minr=e;
                }
            }
        }
        cout<<"The opening and closing rank for program "<<b<<" are "<<minr<<" and "<<maxr<<" respectively"<<endl;
    }
    return 0;
}