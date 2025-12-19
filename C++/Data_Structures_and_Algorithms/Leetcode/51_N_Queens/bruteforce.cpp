#include <iostream>
#include <vector>
using namespace std;
void trajectoryMarker(int n, vector<vector<string>>& result, int row,int col){
    for(int i=0;i<result[row].size();i++){
        
    }
}
void HelperFunction(int n,vector<vector<string>>& result,int rowind,int colind){
    if(rowind==n-1 && colind==n-1){//0-indexed
        cout<<"Final board returned!"<<endl;
        return;
    }
    //we check probabilities on rows
    while(rowind<n){
        if(result[rowind][colind]!="."){
            result[rowind][colind]="Q";//Place the Queen
            cout<<"Queen placed!"<<endl;
            // Marking the queens trajectory

            HelperFunction(n,result,rowind+1,colind);
        }
        rowind++;//Updation condition
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result(n,vector<string>(n,"0"));
    int rowind=0,colind=0;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> nums;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    } // Input taken
    return 0;
}