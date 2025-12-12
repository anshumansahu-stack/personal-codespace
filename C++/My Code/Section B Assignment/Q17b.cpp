#include<iostream>
using namespace std;
int main(){
    int rows,coeff,space,a,b,c,d,e,f,g;
    cout<<"Enter the number of rows you want"<<endl;
    cin>>g;
    rows=g-((g-1)/2);
    for(a=1;a<=rows;a++){//3
        space=rows-a;//2
        for(b=1;b<=space;b++){
            cout<<" ";
        }
        coeff=1;
        for(c=1;c<=a;c++){
            cout<<" "<<coeff;
            coeff=(coeff*(a-c))/c;
        }
        cout<<endl;
    }
    for(b=1,c=rows-b,space=b;b<=a;b++,space=b,c=rows-b){
        for(d=1;d<=space;d++){
            cout<<" ";
        }
        coeff=1;
        for(e=1,f=c;f>0;f--,e++){
            cout<<" "<<coeff;
            coeff=(coeff*(c-e))/e;
        }
        cout<<endl;
    }
    return 0;
}