// Find the sum natural numbers under n that are a multiple of x and y. Here x=3 and y=5.
// Optimal Approach.
#include<iostream>
using namespace std;
long long int Sum_of_multiples(long long int limit, long long int factor){
    long long int intermed=(limit-1)/factor;
    return (factor*intermed*(intermed+1)/2);
}
int main(){
    int n;
    cin>>n;
    int result=Sum_of_multiples(n,3)+Sum_of_multiples(n,5)-Sum_of_multiples(n,15);
    cout<<result<<endl;
    return 0;
}