#include<iostream>
#include<cmath>
using namespace std;
void pythagorean(int a[],int b[]){
    double output;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            output=sqrt((i*i)+(j*j));
            if(output-floor(output)!=0){
                continue;
            }
            else{
                continue;
            }
        }
    }
}
void swap (int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int limit;
    cout<<"Enter the limit till which you want to find the pythagorean triplets"<<endl;
    cin>>limit;
    int a[limit],b[limit];
    pythagorean(a[limit],b[limit]);
    return 0;
}