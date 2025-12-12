#include<iostream>
using namespace std;
int main(){
    int a,b,c,m,n,fl,sl,tl,e,f;
    cout<<"Enter the number of lists"<<endl;
    cin>>n;//Number of lists
    for(a=1;a<=n;a++){
        cout<<"Enter the number of terms you want in "<<a<<"th list"<<endl;
        cin>>m;
        if(m<3){
            cout<<"ERROR: Entered numbers must be more than 3"<<endl;
        }
        else{            
            cout<<"Enter the 1st number"<<endl;
            cin>>f;
            cout<<"Enter the 2nd number"<<endl;
            cin>>b;
            cout<<"Enter the 3rd number"<<endl;
            cin>>c;
            if(f>b){
                if(f>c){
                    fl=f;
                    if(b>c){
                        sl=b;
                        tl=c;
                    }
                    else{
                        sl=c;
                        tl=b;
                    }
                }
                else{
                    fl=c;
                    if(f>b){
                        sl=f;tl=b;
                    }
                    else{
                        sl=b;tl=f;
                    }
                }
            }
            else{
                if(b>c){
                    fl=b;
                    if(c>f){
                        sl=c;tl=f;
                    }
                    else{
                        sl=f;tl=c;
                    }
                }
                else{
                    fl=c;
                    if(f>b){
                        sl=f;tl=b;
                    }
                    else{
                        sl=b;tl=f;
                    }
                }
            }
            for(int d=4;d<=m;d++){
                cout<<"Enter the "<<d<<"th number"<<endl;
                cin>>e;
                if(e>fl){
                    tl=sl;
                    sl=fl;
                    fl=e;
                }
                else if((e<=fl)&&(e>sl)){
                    tl=sl;
                    sl=e;
                }
                else if((e<=sl)&&(e>tl)){
                    tl=e;
                }
                else{
                    continue;
                }
            }
        }
        cout<<"The third largest number in the list is "<<tl<<endl;
    }
    cout<<"OK Thank You"<<endl;
    return 0;
}