#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minDeletionSize(vector<string> &strs)
{
    int colval=0;
    int length=strs[0].length();//Size of a string (row)
    // strs.size() is column
    for(int i=0;i<length;i++){//Row iteration
        for(int j=1;j<strs.size();j++){//colwise iteration
            if(int(strs[j][i])<int(strs[j-1][i])){
                colval++;
                break;
            }
        }
    }
    return colval;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<string> strs;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        string x;
        cin >> x;
        strs.push_back(x);
    } // Input taken
    cout<<"The minimum deletion size is: "<<minDeletionSize(strs)<<endl;
    return 0;
}