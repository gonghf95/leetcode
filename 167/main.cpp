#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            lower_bound(numbers.begin(), numbers.end(), target);
            int size = numbers.size();
            for (int i = 0; i < size; i++)
                for (int j = i + 1; j < size && (numbers[i] + numbers[j] <= target); j++)
                    if ((numbers[i] != numbers[j]) && ((numbers[i] + numbers[j]) == target))
                        return {i + 1, j + 1};
            return {};
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            int left = 0;
            int right = numbers.size() - 1;
            while (left < right)
            {
                int sum = numbers[left] + numbers[right];
                if (sum == target)
                    return {left + 1, right + 1};
                else if (sum < target)
                    left += 1;
                else
                    right -= 1;
            }
            return {};
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;

    // vector<int> nums = {1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    // int target = 4;

    // vector<int> nums = {-1, 0};
    // int target = -1;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 4;

    hongfu02::Solution s;
    vector<int> ret = s.twoSum(nums, target);
    if (ret.size() >= 2)
        cout << ret[0] << ", " << ret[1] << endl;
    else
        cout << "none\n";
    return 0;
}