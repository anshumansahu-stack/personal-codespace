#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    cout<<"Enter the 6 digit number"<<endl;
    cin>>a;
    b=(a-(a%100000))/100000;//Lakhs
    c=a-(b*100000);//5 digit now
    d=(c-(c%1000))/1000;//thousands
    e=c-(d*1000);//3 digit now
    f=(e-(e%100))/100;//hundreds
    g=e-(f*100);//2 digit now
    h=(g-(g%10))/10;//tens
    i=g-(h*10);//ones
    cout<<"The number is: Lakhs: "<<b<<" Thousands: "<<d<<" Hundreds: "<<f<<" Tens: "<<h<<" Ones: "<<i<<endl;
    a=((i*100000)+(b*10000)+(d*100)+(f*10)+(h));
    cout<<"The resulted number is "<<a<<endl;
    b=(a-(a%100000))/100000;//Lakhs
    c=a-(b*100000);//5 digit now
    d=(c-(c%1000))/1000;//thousands
    e=c-(d*1000);//3 digit now
    f=(e-(e%100))/100;//hundreds
    g=e-(f*100);//2 digit now
    h=(g-(g%10))/10;//tens
    i=g-(h*10);//ones
    cout<<"The number is: Lakhs: "<<b<<" Thousands: "<<d<<" Hundreds: "<<f<<" Tens: "<<h<<" Ones: "<<i<<endl;
    return 0;
}