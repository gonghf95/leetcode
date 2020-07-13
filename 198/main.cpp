#include <iostream>
#include <vector>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int rob(vector<int> &nums)
        {
            if (nums.size() == 0)
                return 0;

            if (nums.size() == 1)
                return nums[0];

            int *dp = new int[nums.size()];
            dp[0] = nums[0];
            dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
            unsigned int i;
            for (i = 2; i < nums.size(); i++)
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            int ans = dp[i - 1];
            delete[] dp;
            return ans;
        }
    };
} // namespace hongfu01

int main(int argc, char **argv)
{
    vector<int> nums = {1, 2, 3, 1};
    // vector<int> nums = {2, 7, 9, 3, 1};
    hongfu01::Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}
