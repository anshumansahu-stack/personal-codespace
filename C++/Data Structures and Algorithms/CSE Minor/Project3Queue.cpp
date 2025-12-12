#include<iostream>
using namespace std;

class Queue{
    private:
    int frontindex;
    int rearindex;
    int countVal;

    public:
    void Order(){
        frontindex=-1;
        rearindex=-1;
        countVal=0;
    }

    bool isEmpty(){
        return (countVal==0);
    }

    bool isFull(){
        return (countVal==5);
    }

    int countVal(){
        return countVal;
    }

};

int main(){
    
    return 0;
}