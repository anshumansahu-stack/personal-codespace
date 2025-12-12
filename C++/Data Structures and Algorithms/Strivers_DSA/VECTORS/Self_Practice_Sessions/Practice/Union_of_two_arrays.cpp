#include <iostream>
#include <vector>
// This is the optimal two pointer approach. Bruteforce uses sets STL.
using namespace std;
int main()
{
    cout << "Enter the elements in sorted order:" << endl;
    //  Array 1 input
    vector<int> nums1;
    char consent = 'y';
    cout << "Enter the first array:" << endl;
    do
    {
        int input;
        cout << "Enter the number: ";
        cin >> input;
        nums1.push_back(input);
        cout << "Do you want to enter another number?" << endl;
        cin >> consent;
    } while (consent == 'y');
    // Array 1 input taken
    //  Array 2 input
    vector<int> nums2;
    consent = 'y';
    cout << "Enter the second array:" << endl;
    do
    {
        int input;
        cout << "Enter the number: ";
        cin >> input;
        nums2.push_back(input);
        cout << "Do you want to enter another number?" << endl;
        cin >> consent;
    } while (consent == 'y');
    // Array 2 input taken
    vector<int> union_array;
    int i = 0, j = 0;
    while ((i < nums1.size() && j < nums2.size()))
    {
        if (nums1[i] < nums2[j])
        {
            if (union_array.empty() || union_array.back() != nums1[i])
            {
                union_array.push_back(nums1[i]);
            }
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            if (union_array.empty() || union_array.back() != nums2[j])
            {
                union_array.push_back(nums2[j]);
            }
            j++;
        }
        else
        {
            if (union_array.empty() || union_array.back() != nums2[j])
            {
                union_array.push_back(nums2[j]);
            }
            j++;
            i++;
        }
    }
    while (i < nums1.size())
    {
        if (union_array.empty() || union_array.back() != nums1[i])
        {
            union_array.push_back(nums1[i]);
        }
        i++;
    }
    while (j < nums2.size())
    {
        if (union_array.empty() || union_array.back() != nums2[j])
        {
            union_array.push_back(nums2[j]);
        }
        j++;
    }
    for (int i : union_array)
    {
        cout << i << " ";
    }
    cout << endl
         << "OK Thank you!" << endl;
    return 0;
}