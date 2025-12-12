#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void linearsort(vector<int> &num)
{
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            if (num.at(i) > num.at(j))
            {
                swap(num.at(i), num.at(j));
            }
        }
    }
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> combine;
    for (int i = 0; i < nums1.size(); i++)
    { // 0 to n-1 pushed
        combine.push_back(nums1.at(i));
    }
    for (int i = 0; i < nums2.size(); i++)
    { // n to m-1 pushed
        combine.push_back(nums2.at(i));
    }
    linearsort(combine);
    if (combine.size() % 2 != 0)
    {
        return double(combine.at(((combine.size() + 1) / 2) - 1));
    }
    else
    {
        return double(combine.at((combine.size()/2)-1)+combine.at(combine.size()/2))/2;
    }
}
int main()
{
    char consent1 = 'n', consent2 = 'n';
    int n1, n2;
    vector<int> num1, num2;
    cout << "Enter the numbers of the 1st array " << endl;
    do
    {
        cin >> n1;
        num1.push_back(n1);
        cout << "Another number?" << endl;
        cin >> consent1;
    } while (consent1 == 'y');
    cout << "Enter the numbers of the 2nd array " << endl;
    do
    {
        cin >> n2;
        num2.push_back(n2);
        cout << "Another number?" << endl;
        cin >> consent2;
    } while (consent2 == 'y');
    cout << "The median is " << findMedianSortedArrays(num1, num2);
    return 0;
}
