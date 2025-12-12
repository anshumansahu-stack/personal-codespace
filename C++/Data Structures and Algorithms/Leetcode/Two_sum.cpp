/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <iostream>
using namespace std;
bool Sumcheck(int n, int nums[], int &num1, int &num2, int target)
{
    bool truth = false;
    for (int i = 0; i < n - 1; i++)
    {
        num1 = i;
        for (int j = i + 1; j < n && truth == false; j++)
        {
            if (nums[num1] + nums[j] == target)
            {
                num2 = j;
                truth = true;
            }
            else
            {
                continue;
            }
        }
        if (truth == true)
        {
            break;
        }
    }
    return truth;
}

int main()
{
    int target;
    cout << "Enter the target value" << endl;
    cin >> target;
    int n;
    cout << "Enter the number of elements in the array num" << endl;
    cin >> n;
    int nums[n];
    cout << "Enter an array of integers" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int num1, num2;
    if (Sumcheck(n, nums, num1, num2, target) == true)
    {
        cout << "The required indices are:" << endl;
        cout << "[" << num1 << "," << num2 << "]" << endl;
    }
    else
    {
        cout << "No solution is found." << endl;
    }

    return 0;
}