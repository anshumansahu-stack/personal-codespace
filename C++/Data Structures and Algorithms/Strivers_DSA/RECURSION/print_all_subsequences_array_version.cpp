#include <iostream>
using namespace std;

void printAllSubsequences(int index, int nums[], int temp[], int n, int tempSize)
{
    if (index == n)
    {
        cout << "[";
        for (int i = 0; i < tempSize; i++)
            cout << temp[i] << " ";
        cout << "]" << endl;
        return;
    }

    // Pick
    temp[tempSize] = nums[index];
    printAllSubsequences(index + 1, nums, temp, n, tempSize + 1);

    // Not Pick
    printAllSubsequences(index + 1, nums, temp, n, tempSize);
}

int main()
{
    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;

    int nums[100]; // assuming max input size
    cout << "Enter " << N << " elements:" << endl;

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    int temp[100]; // storage for subsequence
    printAllSubsequences(0, nums, temp, N, 0);

    return 0;
}
