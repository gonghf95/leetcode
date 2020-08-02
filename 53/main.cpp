#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return 0;

        int ans = INT32_MIN;
        vector<int> dp(nums.size() + 1, 0);
        for (unsigned int i = 1; i <= nums.size(); i++)
        {
            dp[i] += max(0, dp[i - 1]) + nums[i - 1];
            if (dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {-1};
    vector<int> nums = {1};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}