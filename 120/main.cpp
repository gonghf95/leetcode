#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 0)
            return 0;

        if (triangle.size() == 1)
            return triangle[0][0];

        for (unsigned int i = 1; i < triangle.size(); i++)
            triangle[i][0] += triangle[i - 1][0];

        for (unsigned int i = 1; i < triangle.size(); i++)
        {
            triangle[i - 1].push_back(0x3f3f3f3f);
            for (unsigned int j = 1; j < triangle[i].size(); j++)
                triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
        }

        int ans = 0x3f3f3f3f;
        int lastRow = triangle.size() - 1;
        for (unsigned int i = 0; i < triangle[lastRow].size(); i++)
            if (triangle[lastRow][i] < ans)
                ans = triangle[lastRow][i];

        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}