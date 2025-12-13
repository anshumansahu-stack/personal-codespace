#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Implementing hashing
    //  Array input
    vector<int> nums;
    char consent = 'y';
    cout << "WARNING: This code works on only positive integers between 0 to 99" << endl;
    do
    {
        int input;
        cout << "Enter the number: "; // 21 38 64 98 51
        cin >> input;
        nums.push_back(input);
        cout << "Do you want to enter another number?" << endl;
        cin >> consent;
    } while (consent == 'y');
    // Array input taken
    // Target element required
    int target_element;
    cout << "Enter the target element" << endl;
    cin >> target_element; // 51
    // Target element taken
    // Hashing procedure initiated
    int hash_array[100] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        hash_array[nums.at(i)]++; // hash_array[51]=1
    }
    // Hashing process terminated. Time complexity: O(N)
    // Finding the target value
    cout << "The number has occurred " << hash_array[target_element] << " times.";
    // for (int i : nums)
    // {
    //     cout << i << " ";
    // } Just for input Check, safe to comment out.
    cout << endl;
    cout << "OK Thank you!" << endl;
    return 0;
}