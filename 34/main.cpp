#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};

        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        int flag = 0;
        while (left < right)
        {
            middle = (left + right) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                flag = 1;
                break;
            }
        }

        vector<int> ans = {-1, -1};
        if (left == right && nums[left] == target)
            ans[0] = ans[1] = left;
        if (flag)
        {
            int i = middle;
            while (i <= right && nums[i] == target)
                i++;
            ans[1] = i - 1;
            i = middle;
            while (i >= 0 && nums[i] == target)
                i--;
            ans[0] = i + 1;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 2};
    Solution s;
    vector<int> ret = s.searchRange(nums, 2);
    cout << ret[0] << ", " << ret[1] << endl;
    return 0;
}