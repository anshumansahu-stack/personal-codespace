#include<iostream>
using namespace std;
int main(){
    int a=5;
    int* ptr=&a;
    int** pptr=&ptr;
    cout<<*ptr;
    cout<<endl;
    cout<<sizeof(a);
    cout<<endl;
    cout<<*(ptr+1);//Why does this line return Garbage value and a regular array declaration doesnot?
    return 0;
}