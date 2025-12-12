// #include<iostream>
// using namespace std;
// // BRUTEFORCE
// int main(){
//     long long n;
//     cin>>n;
//     long long sum1=0,sum2=0;
//     for(long long i=1;i<=n;i++){
//         sum1+=i*i;// Sum of squares
//         sum2+=i;// well square this sum at last
//     }
//     cout<<((sum2*sum2)-sum1)<<endl;
//     return 0;// TC=O(n)
// }

#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long sum1 = (n * (n + 1) * ((2 * n) + 1)) / 6;
    long long sum2 = ((n * (n + 1)) / 2) * ((n * (n + 1)) / 2);
    cout << sum2 - sum1 << endl;
    return 0;
}// Constant Time Complexity