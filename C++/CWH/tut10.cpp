#include<iostream>
using namespace std;
int main(){
    /*Loops in C++
    There are three types of loops in C++:
    1. For Loop
    2. While Loop
    3. Do-While Loop
    */
    /*For Loop in C++*/
    // int i=1;
    // cout<<i;
    // i++;

    // //Syntax for For loop:
    // for(initialization;condition;updation){
    //     loop body(C++ Code)
    // }Runs until the condition becomes false.

    // for(int i=1;i<40;i=(2*i)+1){
    //     cout<<i<<endl;
    // }
    // return 0;

    //***Example of infinite for loop****
    // for(int i=1;24<40;i=i+1){
    //     cout<<i<<endl;
    // }

    /*While Loop in C++*/
    /*Syntax for while loop:
    while(condition){
        C++ statements
    }*/

    //Printing 1 to 40 using while loop
    // int i=1;
    // while(i<=40){
    //     cout<<i<<endl;
    //     i++;
    // }
    
    //Example of infinite while loop
    // int i=1;
    // while(true){
    //     cout<<i<<endl;
    //     i++;
    // }

    
    /*Do-While Loop in C++*/
    //Syntax of Do-While loop
    /*do{
        C++ Codes
    }while(condition)
    */
   //This code runs this code body once, and then checks the condition if it is true or not.
    // int i=1;
    // do{
    //     cout<<i<<endl;
    //     i++;
    // }while(i<=40);

    //Q: Write the multiplication table of 6 using loop.
    int a,b;
    cout<<"Enter the number of which table you want"<<endl;
    cin>>a;
    cout<<"Enter the number till which you want a table"<<endl;
    cin>>b;
    int i=1;
    while(i<=b){
        cout<<a<<"X"<<i<<"="<<(a*i)<<endl;
        i++;
    }

    return 0;
}