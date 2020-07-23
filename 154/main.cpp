#include <iostream>
#include <vector>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int findMin(vector<int> &nums)
        {
            int ans = nums[0];
            for (auto &num : nums)
                if (num < ans)
                    ans = num;
            return ans;
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        int findMin(vector<int> &nums)
        {
            int left = 0;
            int right = nums.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] < nums[right])
                    right = mid;
                else if (nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right--;
            }
            return nums[left];
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 2, 2, 0, 1};
    hongfu02::Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}