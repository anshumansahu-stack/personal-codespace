#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j,count,scount;
    char u='y',v;
    cout<<"Enter the number of coaches:";
    cin>>a;// Number of coaches
    cout<<endl;
    scount=0;
    for(b=1;b<=a;b++){
        cout<<"Coach-"<<b<<":"<<endl;
        count=0;
        u='y';
        for(c=1;u=='y';c++){
            cout<<"Passenger-"<<c<<" Berth Number: ";
            cin>>d;//Berth Number
            if((d>72)||(d<1)){
                cout<<"ERROR: Seat Invalid"<<endl;
                continue;
            }
            else{
                e=d%8;
                if((e==1)||(e==4)){
                    cout<<"----->Informed his/her berth position as: "<<"Lower Berth"<<endl;
                }
                if((e==2)||(e==5)){
                    cout<<"----->Informed his/her berth position as: "<<"Middle Berth"<<endl;
                }
                if((e==3)||(e==6)){
                    cout<<"----->Informed his/her berth position as: "<<"Upper Berth"<<endl;
                }
                if(e==7){
                    cout<<"----->Informed his/her berth position as: "<<"Side Lower"<<endl;
                }
                if(e==0){
                    cout<<"----->Informed his/her berth position as: "<<"Side Upper"<<endl;
                }
            }
            cout<<"Next Passenger?"<<endl;
            count=count+1;
            cin>>u;
        }
        cout<<"Total number of requests received from coach-"<<b<<" are "<<count<<endl;
        scount=scount+count;
    }
    cout<<"The total number of requests received for this train are: "<<scount<<endl;
    cout<<"OK Thank You"<<endl;
    
    return 0;
}