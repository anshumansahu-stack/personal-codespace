#include <iostream>
#include <vector>
using namespace std;
template <class T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
void Quicksort(vector<int> &nums, int start, int end)
{ // Recursive
	if (start >= end)
		return;
	cout << "Recursive call" << endl;
	int pivot = nums[start];
	int startptr = start + 1, endptr = end;
	while (startptr <= endptr)
	{
		if (nums[startptr] > pivot)
		{
			// greater than zone
			Swap(nums[startptr], nums[endptr]);
			endptr--;
		}
		else
		{
			// smaller than or equal to zone
			startptr++;
		}
	}
	Swap(nums[start], nums[endptr]);
	Quicksort(nums, start, endptr - 1);
	Quicksort(nums, endptr + 1, end);
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
	Quicksort(nums, 0, nums.size() - 1);
	cout << "[";
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << "]" << endl;
	return 0;
}