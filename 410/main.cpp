#include <iostream>

using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        long l, h;
        l = nums[0];
        h = 0;
        for (auto num : nums)
        {
            h += num;
            if (num > l)
                l = num;
        }

        while (l < h)
        {
            int mid = (l + h) / 2;
            long sum = 0;
            int cnt = 1;
            for (auto num : nums)
            {
                sum += num;
                if (sum > mid)
                {
                    sum = num;
                    cnt++;
                }
            }

            if (cnt > m)
                l = mid + 1;
            else
                h = mid;
        }

        return l;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}