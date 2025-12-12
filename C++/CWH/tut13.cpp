#include<iostream>
using namespace std;
int main(){
    // //Examples of Arrays in C++
    // int marks[4]={54,68,987,125};
    // cout<<"The maks of value "<<0<<" is "<<marks[0]<<endl;
    // cout<<"The maks of value "<<1<<" is "<<marks[1]<<endl;
    // cout<<"The maks of value "<<2<<" is "<<marks[2]<<endl;
    // cout<<"The maks of value "<<3<<" is "<<marks[3]<<endl;

    // int russian_aukaat[10]={500,1000,2000,3000,5000,6000,10000,15000,18000,20000};
    // for(int i=0;i<10;i++){
    //     cout<<i<<"  bra numbri Russian maal ki keemat "<<russian_aukaat[i]<<" hai."<<endl;
    //     if(i==9){
    //         cout<<"Behn te lundh autaat me!"<<endl;
    //     }
    // }

    // //Do the same work using while and do while loops. Challenge accepted.

    // int i=0;
    // cout<<endl;
    // while(i<10){
    //     cout<<i<<"  bra numbri Russian maal ki keemat "<<russian_aukaat[i]<<" hai."<<endl;
    //     if(i==9){
    //         cout<<"Behn te lundh autaat me!"<<endl;
    //     }
    //     i++;
    // }

    // i=0;
    // cout<<endl;
    // do{
    //     cout<<i<<"  bra numbri Russian maal ki keemat "<<russian_aukaat[i]<<" hai."<<endl;
    //     if(i==9){
    //         cout<<"Behn te lundh autaat me!"<<endl;
    //     }
    //     i++;
    // }while(i<10);

    //An array is said to be a continuous block of memory.
    //It is used to assign variables to those types of data that cannot be stored in Normal data types.
    //Its syntax and use is shown above.
    //***Another way of representation of array***

    // int Mathmarks[6];
    // Mathmarks[0]=122;
    // Mathmarks[1]=2;
    // Mathmarks[2]=12;
    // Mathmarks[3]=132;
    // Mathmarks[4]=422;
    // Mathmarks[5]=5122;
    // for(int a=0;a<6;a++){
    //     cout<<Mathmarks[a]<<endl;
    // }

    //The numbers 0,1,2,...6 are called the indices(singular index) for the array above.

    //****Pointers and Arrays; Pointer arithmetics.****

    /*In General life, pointers are depicted as:
    
    int*p=&a;
    
    but if array is in the format marks[x]
    
    the corresponding pointer notation would be:
    
    int*p=marks; //No Ampersand in front of the name.
    
    Now for Pointer Arithmetic there is the important formula: 

    Address(new)=Address(old)+(i*size of data type)
    For instance;
    for the array, say marks[4];
    int*p=marks;
    (p+i)=(p)+i*4.
    further elaboration is in the code.
    
    */

   int marks[5]={11,22,33,44,55};
   int*p=marks;
   cout<<*p<<endl;//11
   cout<<*(p+2)<<endl;//22
   cout<<*(p+1)<<endl;//33
   cout<<*(p+3)<<endl;//44
   cout<<*(p+4)<<endl;//55

   cout<<p<<endl;//0x61fef8
   cout<<(p+2)<<endl;//0x61fefc
   

    //The pointer address is being explained hexadecimally. 
    return 0;
}