//tut44.cpp is pure notes, refer the youtube video for the same.
#include<iostream>
using namespace std;
//Virtual base class is a class from where inherited data members will only be inherited once, no matter how many times they are inherited into
// the same function in the future.
// for instance the function set_number will only be inherited once into the function result, which is a multiply inherited from the base classes 
// sports and test.
class Student{
    protected:
        int roll_number;
    public:
        void set_roll_number(int a){
            roll_number=a;
        }
};
class Test: virtual public Student{
    protected:
    float maths,CRE;
    public:
        void set_number(float m1,float m2){
            maths=m1;
            CRE=m2;
        }
        void print_number(){
            cout<<"The numbers obtained are as follows:"<<endl<<"Maths: "<<maths<<endl<<"CRE: "<<CRE<<endl;
        }
};
class Sports: virtual public Student{
    protected:
    float score;
    public:
        void set_score(float n1){
            score=n1;
        }
        void print_score(){
            cout<<"The score obtained in EAA is "<<score<<endl;
        }
};
class Result: public Sports, public Test{
    public:
    void display(){
        print_number();
        print_score();
        cout<<"The total score obtained from 210 is "<<maths+CRE+score<<endl;
    }
};
int main(){
    Result Anshuman;
    Anshuman.set_roll_number(05);
    Anshuman.set_number(98.5,89.5);
    Anshuman.set_score(7.5);
    Anshuman.display();
    return 0;
}