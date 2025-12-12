class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        vector<int> nums;
        int n1 = n;
        while (n > 01)
        {
            int i = n1 % 10;
            nums.push_back(i);
            n1 = (n1 - i) / 10;
        }
        long long mult = 1, result = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            sum += nums[i];
            result += mult * nums[i];
            mult *= 10;
        }
        return result * sum;
    }
};
©leetcode