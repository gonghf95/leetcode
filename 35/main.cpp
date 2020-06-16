#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int middle;
        while (left < right)
        {
            middle = (left + right) / 2;
            if (middle >= size - 1)
                break;
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
                return middle;
        }

        return nums[left] < target ? left + 1 : left;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 3) << endl;
    return 0;
}