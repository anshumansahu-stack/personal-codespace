#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x,y,r,p,z=1,eps=0.00001,sqr,theta;
    const float pi=3.14159;
    cout<<"Enter the abscissa and ordinate respectively"<<endl;
    cin>>x>>y;
    sqr=(x*x)+(y*y);
    p=sqr;
    while(p-z>eps){
        p=(p+z)/2;
        z=sqr/p;
    }
    r=p;
    double C;
    C=2*pi*r;
    theta=atan2(y,x);
    cout<<"The polar coordinates are ("<<r<<","<<theta<<")"<<endl;
    return 0;
}