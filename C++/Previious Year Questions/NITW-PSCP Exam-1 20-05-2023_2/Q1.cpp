#include<iostream>
using namespace std;
int main(){
    int a,b,c,e,d,f,g,h,i,j,sum=0;//1 bag=76kgs
    cout<<"Enter the number of farmers in the village"<<endl;
    cin>>a;
    for(b=1;b<=a;b++){
        cout<<"Enter the number of bags and kgs respectively of "<<b<<"th farmer"<<endl;
        cin>>c;//bags
        cin>>d;//kgs
        sum=sum+((c*76)+d);//total kgs
    }
    e=sum%76;//no of kgs
    f=sum-e;
    g=f/76;//no.of bags
    cout<<"The total amount of paddy from this village is "<<g<<" bags "<<e<<"kgs"<<endl;
    return 0;
}