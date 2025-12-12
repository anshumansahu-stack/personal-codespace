#include<iostream>
using namespace std;
class Base1{
    protected:
    int baseint1;
    public:
    void set_baseint1(){
        int a;
        cout<<"Enter the value of baseint1"<<endl;
        cin>>a;
        baseint1=a;
    }
};
class Base2{
    protected:
    int baseint2;
    public:
    void set_baseint2(){
        int a;
        cout<<"Enter the value of baseint2"<<endl;
        cin>>a;
        baseint2=a;
    }
};
class Base3{
    protected:
    int baseint3;
    public:
    void set_baseint3(){
        int a;
        cout<<"Enter the value of baseint3"<<endl;
        cin>>a;
        baseint3=a;
    }
};
class derived: public Base1, public Base2, public Base3{
    public:
    void show(){
        cout<<"The value of baseint 1 is "<<baseint1<<endl;
        cout<<"The value of baseint 2 is "<<baseint2<<endl;
        cout<<"The value of baseint 3 is "<<baseint3<<endl;
        int value=baseint1*baseint2*baseint3;
        cout<<"The product is "<<value<<endl;
        if(value>100000){
            cout<<"user ladka hai mera";
        }
        else{
            cout<<"user pakka ladka hai mera";
        }
    }
};
int main(){
    derived prince;
    prince.set_baseint1();
    prince.set_baseint2();
    prince.set_baseint3();
    prince.show();

    return 0;
}