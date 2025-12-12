#include<iostream>
using namespace std;
int main(){
    // cout<<"This is tutorial 9"<<endl;
    int umar;
    cout<<"Beta apni umar batao"<<endl;
    cin>>umar;
    // 1. Control Structure: if-else ladder

    if(umar<-20){
        cout<<"Papa kabhi muth maar lenge gand fatt jayegi tumhari"<<endl;
    }
    else if(umar<0){
        cout<<"Itni bhi chull kya machi hai bsdk pehle paida toh hojao"<<endl;
    }
    else if(umar<18){
        cout<<"Tum Bhosadiwale"<<endl;
    }
    else if(umar<30){
        cout<<"Tumhare walid Bhosadiwale"<<endl;
    }
    else if(umar<60){
        cout<<"Tumhare pure Khandaan bhosadiwaale"<<endl;
    }
    else{
        cout<<"Chacha, are o Bhosadiwaale chacha!\nThoda rest kar lijiye, warna rest in peace ho jaayenge"<<endl;
    }
    
    // 2. Control Structure: Switch Case statement
// switch (umar)
// {
// case 10:
//     cout<<"Result Kitna?"<<endl;
//     break;
// case 18:
//     cout<<"CG Kitna?"<<endl;
//     break;
// case 25:
//     cout<<"Bank Balance kitna?"<<endl;
//     break;
// case 40:
//     cout<<"Bacche kitne?"<<endl;
//     break;
// case 60:
//     cout<<"Pension Kitna?"<<endl;
//     break;
// case 70:
//     cout<<"Aur kitna?"<<endl;
//     break;
// default:
//     cout<<"Bsdk tumhe kisne pucha?"<<endl;
//     break;

// cout<<"Beta hum toh tumhaara accha hi chahte hain..."<<endl;
// }
    return 0;
}