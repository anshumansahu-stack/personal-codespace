int reverse(int n)
{
    int rev = 0, num = n;
    while (num > 0)
    {
        int i = num % 10;
        rev += i;
        rev *= 10;
        num = (num - i) / 10;
    }
    return rev / 10;
} // number reversing successful, O(n)
int minMirrorPairDistance(vector<int> &nums)
{
    int mindist = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int dist;
        int k = reverse(nums[i]);
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (k == nums[j])
            {
                dist = (j - i);
                break; // you need minimum
            }
        }
        mindist = min(mindist, dist);
    }
    if (mindist < 0)
    {
        return -1;
    }
    return mindist;
}