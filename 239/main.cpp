#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        /**
     * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
     * 输出: [3,3,5,5,6,7]
    */
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            int size = nums.size();
            if (size < k)
                return nums;

            vector<int> ans;
            for (unsigned int i = 0; i <= nums.size() - k; i++)
            {
                int val = nums[i];
                for (int j = 0; j < k; j++)
                {
                    val = max(val, nums[i + j]);
                }
                ans.push_back(val);
            }

            return ans;
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            if (nums.size() < (unsigned int)k)
                return nums;

            vector<int> ans;
            deque<int> deq;
            for (unsigned int i = 0; i < nums.size(); i++)
            {
                while (!deq.empty() && nums[deq.back()] <= nums[i])
                    deq.pop_back();
                deq.push_back(i);
                if (deq.front() == (int)(i - k))
                    deq.pop_front();
                if ((int)i >= k - 1)
                    ans.push_back(nums[deq.front()]);
            }
            return ans;
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    hongfu02::Solution s;
    vector<int> ret = s.maxSlidingWindow(nums, k);
    for (auto &num : ret)
    {
        cout << num << ',';
    }
    cout << endl;
    return 0;
}