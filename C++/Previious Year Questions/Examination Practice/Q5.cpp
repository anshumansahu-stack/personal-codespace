#include<iostream>
using namespace std;
int main(){
    float a,b,c,d,e,f,g,h,i,j,perc;
    cout<<"Enter the total marks for theory part"<<endl;
    cin>>a;//To be considered out of 100; maximum 75
    if(a>75){
        cout<<"ERROR: The maximum weightage is 75%"<<endl;
    }
    else{
        b=(a/75)*100;
        cout<<"Enter the total number of exams in theory part"<<endl;
        cin>>c;
        for(d=1;d<=c;d++){
            cout<<"Enter the marks for "<<d<<"th exam"<<endl;
            cin>>e;
            perc=(e/b)*100;
            cout<<"The contribution of x"<<d<<" exam is "<<perc<<"%"<<endl;
        }

    }
    cout<<"Enter the total marks for lab part"<<endl;
    cin>>a;//To be considered out of 100; maximum 25
    if(a>25){
        cout<<"ERROR: The maximum weightage is 25%"<<endl;
    }
    else{
        b=(a/25)*100;
        cout<<"Enter the total number of exams in theory part"<<endl;
        cin>>c;
        for(d=1;d<=c;d++){
            cout<<"Enter the marks for "<<d<<"th exam"<<endl;
            cin>>e;
            perc=(e/b)*100;
            cout<<"The contribution of y"<<d<<" exam is "<<perc<<"%"<<endl;
        }

    }
    return 0;
}