//Ambiguity resolution in c++
//2 types of ambiguities:
// 1. when 2 classes are multiply inherited and both have a same function, ambiguity occurs and an error is thrown.
//this is resolved by using a scope resolution operator as commented in the below code.
// 2.when a class inherited and the derived class have the same functions designed in them, an ambiguity occurs,
//which function is to be run upon call of the derived class.
//compiler AUTOMATICALLY resolves this error by overwriting the same function of the base class with the function of the 
//derived class.
#include<iostream>
using namespace std;
class Base1{
    public:
    void cuss(){
        cout<<"madarchod"<<endl;
    }
};
class Base2{
    public:
    void cuss(){
        cout<<"bhosdike"<<endl;
    }
};
class Derived:public Base1, public Base2{
    public:
    void cuss(){
        Base1 :: cuss();//Ambiguity resolved by directing the function of base1, using scope resolution operator.
        //Above line is the solution of Ambiguity type 1.
    }
};

class Again_derived: public Base1{
    public:
    void cuss(){
        cout<<"Bhadwe"<<endl;
        //This cuss function overwrites the function which is in its base functions, in this case Base1.
        //If the cuss function is called from Again_derived class, then the function described here is used for execution, NOT the function from Base1.
    }
};
int main(){
    Base1 b;
    b.cuss();
    Base2 B;
    B.cuss();
    Derived Bb;
    Bb.cuss();//Throws an error of ambiguity without the commented line in derived class

    Again_derived BbB;
    BbB.cuss();
    return 0;
}