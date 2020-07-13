#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
        {
            vector<int> ans;

            int size1 = nums1.size();
            int size2 = nums2.size();
            vector<bool> visit(size2, false);

            for (int i = 0; i < size1; i++)
                for (int j = 0; j < size2; j++)
                    if (!visit[j] && nums1[i] == nums2[j])
                    {
                        ans.push_back(nums1[i]);
                        visit[j] = true;
                        break;
                    }
            return ans;
        }
    };
} // namespace hongfu01

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // vector<int> nums1 = {4, 9, 5};
    // vector<int> nums2 = {9, 4, 9, 8, 4};

    hongfu01::Solution s;
    vector<int> ret = s.intersect(nums1, nums2);
    for (auto &num : ret)
        cout << num << ", ";
    cout << endl;
    return 0;
}