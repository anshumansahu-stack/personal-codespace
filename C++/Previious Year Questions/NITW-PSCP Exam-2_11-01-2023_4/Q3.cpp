#include<iostream>
using namespace std;
int main(){
    int a,b,c,f,g,N;
    float e,d,rn;
    cout<<"Enter the number of batches"<<endl;
    cin>>N;
    float sum;
    for(b=1;b<=N;b++){
        cout<<"Enter the number of students in "<<b<<"th batch"<<endl;
        cin>>c;
        cout<<"The roll numbers for this batch are ";
            if(b==1){
                sum=1;
                for(e=1;e<=c;e++){
                d=e/10;
                rn=sum+d;
                cout<<rn<<",";}
                sum=sum+c;
                
            }
            else{
                for(e=1;e<=c;e++){
                d=e/10;
                rn=sum+d;
                cout<<rn<<",";}
                sum=sum+c;
                
            }
        cout<<endl;
    }
    return 0;
}