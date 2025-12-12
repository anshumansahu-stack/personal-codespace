#include<iostream>
using namespace std;
int main(){
    int M,N,p=0,q=0,r=0,s=0,t=0,sum=0,u,v,w,x,y,a,b,c,d,e;
    cout<<"Enter the no of chapatis"<<endl;
    cin>>M;
    cout<<"Enter the no of guests"<<endl;
    cin>>N;
    for(a=1;a<=N;a++){
        cout<<"Enter the Chapati for "<<a<<"th guest"<<endl;
        cin>>b;
        if(b==1){
            p=p+1;
        }
        if(b==2){
            q=q+1;
        }
        if(b==3){
            r=r+1;
        }
        if(b==4){
            s=s+1;
        }
        if(b==5){
            t=t+1;
        }
    }
    u=p*1;
    v=q*2;
    w=r*3;
    x=s*4;
    y=t*5;
    sum=u+v+w+x+y;
    a=sum%M;
    d=M-a;
    b=sum-a;
    c=b/M;
    e=(c+1)*M;
    cout<<"Total no of chapatis"<<e<<endl;
    cout<<"No. of Times of preparation"<<c+1<<endl;
    cout<<"No. of chapatis left"<<d<<endl;
    cout<<"Total no. of guest ate 1 chapatis "<<p<<endl;
    cout<<"Total no. of guest ate 2 chapatis "<<q<<endl;
    cout<<"Total no. of guest ate 3 chapatis "<<r<<endl;
    cout<<"Total no. of guest ate 4 chapatis "<<s<<endl;
    cout<<"Total no. of guest ate 5 chapatis "<<t<<endl;
    int maximum=0;
    if(u>maximum){
        maximum=p;
    }
    if(v>maximum){
        maximum=q;
    }
    
    if(w>maximum){
        maximum=r;
    }
    
    if(x>maximum){
        maximum=s;
    }
   
    if(y>maximum){
        maximum=t;
    }
    cout<<"The number of guests that ate maximum chapatis "<<maximum<<endl;
    return 0;
}