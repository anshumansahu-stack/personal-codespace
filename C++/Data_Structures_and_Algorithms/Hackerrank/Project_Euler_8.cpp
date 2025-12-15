#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n >> k;
    string num;
    cin >> num;
    // BASIC BRUTEFORCE: Double iterate; since we only need greatest product
    int product = 1, max_product = 0;
    for (int i = 0; i < num.length() - k; i++)
    {
        for (int j = i; j < i + k; j++)
        {
            int factor = int(num[j]) - 48;
            // cout << factor << endl;
            product *= factor;
            // cout << "Product is " << product << endl;
        }
        max_product = max(max_product, product);
        // cout << "Max Product is " << max_product << endl;
        product = 1;
    }
    cout << max_product << endl;
    return 0;
}