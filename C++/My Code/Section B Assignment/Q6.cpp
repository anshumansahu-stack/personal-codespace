#include<iostream>
using namespace std;
int main(){
float a,b,c,d,e;
cout<<"Enter the cost price"<<endl;
cin>>a;
cout<<"Enter the MRP"<<endl;
cin>>b;
cout<<"Enter the discount in %"<<endl;
cin>>c;
d=b-((c/100)*b);
e=d-a;
if(e>=0){
		cout<<"The profit from the above transaction is"<<e<<endl;	
}
else{
		cout<<"The loss from the above transaction is"<<-e<<endl;	
}

return 0;


}
