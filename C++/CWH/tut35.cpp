#include<iostream>
using namespace std;

// Destructor neither takes an argument nor does it return any value
int count=0;//Alternatively, you can make a static variable.

//
class num{
    public:
    num(){//This is automatically created when an object is created.
        count++;
        cout<<"This is the time when constructor is called, for object number "<<count<<endl;
    }
    ~num(){//This triggers when the object is destroyed and the memory allocated to the specific object is freed.
    //This is used when Dynamically Allocated memory is required to be freed, like in the previous code, creating dynamic objects.
    //We will also learn creating and allocating dynamic arrays, this is godlike useful in that.
        cout<<"This is the time when the destructor is called for object number "<<count<<endl;
        count--;
    }
};
int main(){
    cout<<"We are in our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2,n3;
        cout<<"Exiting this block"<<endl;
    }//This code is termed as a block. The objects created inside here are destroyed as soon as the block is executed to free the space of the memory.

    //The destructor for an object triggers itself when an object created is no longer required.
    //Compiler determines when the object is required anymore or not.
    cout<<"Back to main"<<endl;
    return 0;
}