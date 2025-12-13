void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void reverse(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    swap(nums[start], nums[end]);
    reverse(nums, start + 1, end - 1);
}
bool check(vector<int> &nums)
{
    // for reversing
    int endindex;
    bool isnondescending = false;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            endindex = i;
            reverse(nums, 0, endindex - 1);
            reverse(nums, endindex, nums.size() - 1);
            reverse(nums, 0, nums.size() - 1);
            break;
        }
        else
        {
            isnondescending = true;
        }
    }
    // for checking if the array is in non descending order
    if (isnondescending)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i + 1] < nums[i])
            {
                return false;
            }
        }
        return true;
    }
}