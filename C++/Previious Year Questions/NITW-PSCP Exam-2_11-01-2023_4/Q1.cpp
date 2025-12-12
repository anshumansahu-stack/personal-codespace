#include<iostream>
using namespace std;
int main(){
    int N,a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the Number N"<<endl;
    cin>>N;
    int fi=30;
    if((N>=1)&&(N<=5)){
        if(N<=3){
            for(a=0;a<=(N*2)-2;a=a+2){
                fi=fi+a;
                cout<<fi<<",";
            }
        }
        else{
            if(N==4){
                for(a=0;a<=6;a=a+2){
                    fi=fi+a;
                    cout<<fi<<",";
                }
                N=N-3;
                fi=fi+5;
                cout<<fi<<",";
            }
            if(N==5){
                for(a=0;a<=6;a=a+2){
                    fi=fi+a;
                    cout<<fi<<",";
                }
                N=N-3;
                fi=fi+5;
                cout<<fi<<",";
                N=N-1;
                fi=fi+2;
                cout<<fi<<",";
            }
            

        }
    }
    else{
        for(a=0;a<=6;a=a+2){
                fi=fi+a;
                cout<<fi<<",";
            }
        N=N-3;
        fi=fi+5;
        cout<<fi<<",";
        N=N-1;
        fi=fi+2;
        cout<<fi<<",";
        d=12;
        e=8;
        f=-2;
        h=-6;
        for(b=1;b<=N;b++,d=d*2,e=e+3,f=f+h,h=h-2){
            fi=fi+d;
            cout<<fi<<",";
            N=N-1;
            if(N==0){
                break;
            }
            fi=fi+e;
            cout<<fi<<",";
            N=N-1;
            if(N==0){
                break;
            }
            fi=fi+f;
            cout<<fi<<",";
            N=N-1;
            if(N==0){
                break;
            }
        }
    }
    return 0;
}