#include<iostream>
using namespace std;
int main(){
    // for (int i = 0; i < 4; i++)
    // {
    //     if(i==2){
    //         break;
    //     }
    //     cout<<i<<endl;
    // }

    for (int i = 0; i < 15; i++)
    {
        if(i==2){
            continue;
        }
        cout<<i<<endl;
    }
    //continue command just skips the current iteration(the one that is going on, here in this case i=2) and directly goes to the next iteration without printing 2.
    return 0;
}
