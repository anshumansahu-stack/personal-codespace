#include<iostream>
using namespace std;
int main(){
    int Ah,Am,At,Dh,Dm,Dt,hour,min,sec,sum=0;
    cout<<"Enter the Arrival time in Hour minute and second :";
    cin>>Ah;
    cin>>Am;
    cin>>At;
    cout<<"Arrival time: "<<Ah<<":"<<Am<<":"<<At<<endl;
    cout<<"Enter the Departure time in Hour minute and second :";
    cin>>Dh;
    cin>>Dm;
    cin>>Dt;
    cout<<"Departure time: "<<Dh<<":"<<Dm<<":"<<Dt<<endl;
    if(Ah<=Dh){
        hour=Dh-Ah;
    }
    else{
        hour=(Dh+24)-Ah;
    }
    if(Am<=Dm){
        min=Dm-Am;
    }
    else{
        min=(Dm+60)-Am;
        hour=hour-1;
    }
    if(At<=Dt){
        sec=Dt-At;
    }
    else{
        sec=(Dt+60)-At;
        min=min-1;
    }
    sum=sum+(hour*60*60)+(min*60)+sec;
    int a,b,c,d,e,f,g,h,i,j;
    a=sum%60;//seconds
    b=sum-a;
    c=b/60;
    d=c%60;//minutes
    e=c-d;
    f=e/60;//hours
    cout<<"Waiting Time: "<<f<<":"<<d<<":"<<a<<endl;
    g=sum%600;
    h=sum-g;
    i=h/600;
    if(g==0){
        cout<<"Cost incurred is "<<i*100<<" rupees"<<endl;
    }
    else{
        cout<<"Cost incurred is "<<(i+1)*100<<" rupees"<<endl;
    } 
    cout<<"OK Thank You"<<endl;   

    return 0;
}