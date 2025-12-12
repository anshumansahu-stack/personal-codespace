#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int maxprofit = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        for (int j = i - 1; j > -1; j--)
        {
            int profit = prices[i] - prices[j];
            if (profit > maxprofit)
            {
                maxprofit = profit;
            }
        }
    }
    return maxprofit;
}
int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    vector<int> prices;
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        prices.push_back(x);
    } // Input taken
    cout << "The maximum profit is: " << maxProfit(prices) << endl;
    return 0;
}