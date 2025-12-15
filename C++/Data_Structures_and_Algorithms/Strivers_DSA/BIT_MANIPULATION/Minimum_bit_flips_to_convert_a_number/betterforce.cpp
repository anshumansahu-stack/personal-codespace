#include <iostream>
using namespace std;
int decimalToBinary(int n)
{
    int result = 0;
    int factor = 1;
    int k = n;
    while (k > 0)
    {
        int i = k % 2;        // 0
        result += i * factor; // 0
        factor *= 10;
        k /= 2; // 2
    }
    return result;
}
int main()
{
    int target, goal;
    cout << "Enter the target: " << endl;
    cin >> target;
    cout << "Enter the goal: " << endl;
    cin >> goal;
    int result = decimalToBinary(target ^ goal), count = 0;
    while (result > 0)
    {
        if (result & 1 == 1)
        {
            count++;
        }
        result /= 10;
    }
    cout << "The minimum bit flips required is: " << count << endl;
    return 0;
}