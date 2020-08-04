#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 1,2,3,0,0,0
        // 2,5,6
        int i, j;
        for (i = 0; i < n; i++) // nums2
        {
            for (j = m - 1; j >= 0 && nums2[i] < nums1[j]; j--)
                nums1[j + 1] = nums1[j];
            nums1[j + 1] = nums2[i];
            m++;
        }
    }
};

int main(int argc, char *argv[])
{
    // vector<int> num1 = {1, 2, 3, 0, 0, 0};
    // int m = 3;
    // vector<int> num2 = {2, 5, 6};
    // int n = 3;

    vector<int> num1 = {1, 3, 5, 0, 0, 0};
    int m = 3;
    vector<int> num2 = {2, 4, 6};
    int n = 3;

    Solution s;
    s.merge(num1, m, num2, n);
    for (auto &num : num1)
        cout << num << ' ';
    cout << endl;
    return 0;
}