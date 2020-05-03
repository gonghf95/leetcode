#define local
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace hongfu01
{
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
}; // class Solution
} // namespace hongfu01

namespace hongfu02
{
/**
 * Boyer-Moore 投票算法
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
} // namespace hongfu02

int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif
    int data;
    vector<int> nums;
    while(cin>>data && data!=-1)
        nums.push_back(data);

    hongfu02::Solution s;
    cout << s.majorityElement(nums) << endl;
    return 0;
}