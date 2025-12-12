#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the first number"<<endl;
    cin>>a;
    cout<<"Enter the second number"<<endl;
    cin>>b;
    if(a>b){
        c=a;
        d=b;
    }
    else{
        c=b;
        d=a;//c=greatest and d=smallest
    }
    i=1;
    while(i<=d){
        e=c*i;
        if(e%d==0){
            cout<<"The LCM of the two numbers is "<<e<<endl;
            break;
        }
        else{
            e=c/i;
            i++;
        }
    }
    int k,l;
    k=c;
    l=d;
    while(c>d){
        if(k%l==0){
            cout<<"The HCF of the two numbers is "<<l<<endl;
            break;
        }
        else{
            k=l;
            l=k%l;
        }

    }
    int LCM=e,GCD=l;
    for(f=GCD;f<=LCM;f++){
        if(f==2){
            cout<<f<<",";
        }
        for(g=3;g<=f-1;g++){
            if(f%g!=0){
                continue;
            }
            if((f%g!=0)&&(g==f-1)){
                cout<<g<<",";
                break;
            }
            if(f%g==0){
                break;
            }
        }
    }
    return 0;
}