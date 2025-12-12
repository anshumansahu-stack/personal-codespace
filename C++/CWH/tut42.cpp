//Assignment provided
#include<iostream>
#include<cmath>
using namespace std;
long double pi=3.14159263;
class Calculator{
    protected:
    double num1,num2;
    public:
    void getnums(){
        double n1,n2;
        cout<<"Enter the first and second numbers respectively"<<endl;
        cin>>n1>>n2;  
        num1=n1;
        num2=n2;
    }
    double addition(){
        return num1+num2;
    }
    double subtraction(){
        return num1-num2;
    }
    double multiplication(){
        return num1*num2;
    }
    double division(){
        return num1/num2;
    }

};
class Scientific_calculator{
    protected:
    int num1,num2;
    public:
    double power(){
        return num1,num2;
    }
    double logarithm(){
        return log(num1)/log(num2);
    }
    double sine_product(){
        return sin(num1*pi/180)*sin(num2*pi/180);
    }
    double cosine_product(){
        return cos(num1*pi/180)*cos(num2*pi/180);
    }

};
class Hybrid_calculator: public Calculator,public Scientific_calculator{
    public:
    void showresults(){
       cout<<"The result of the addition function is "<<addition()<<endl;
       cout<<"The result of the subtraction function is "<<subtraction()<<endl;
       cout<<"The result of the multiplication function is "<<multiplication()<<endl;
       cout<<"The result of the division function is "<<division()<<endl;
       cout<<"The result of the power function is "<<power()<<endl;
       cout<<"The result of the logarithm function is "<<logarithm()<<endl;
       cout<<"The result of the sine_product function is "<<sine_product()<<endl;
       cout<<"The result of the cosine_product function is "<<cosine_product()<<endl;
    }
};
int main(){
    Hybrid_calculator nums;
    nums.getnums();
    nums.showresults();
    //although this can be made more operational.
    return 0;
}