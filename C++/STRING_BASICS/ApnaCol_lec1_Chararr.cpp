#include <iostream>
using namespace std;
void reverse(char arr[], int startind, int endind)
{
    if (startind >= endind)
        return;
    swap(arr[startind], arr[endind]);
    reverse(arr, startind + 1, endind - 1);
}
int main()
{
    // Strings made using Character Arrays
    char arr[100];
    cin >> arr;
    cout << arr << endl;
    ;
    // Reversing the array
    reverse(arr, 0, 7);
    cout << arr << endl;
    return 0;
}