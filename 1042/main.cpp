#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths)
    {
        // 图的邻接表 G[0] = {1, 2} => 0->1, 1->0, 0->2, 2->0
        vector<int> G[N];
        for (auto &row : paths)
        {
            G[row[0] - 1].push_back(row[1] - 1);
            G[row[1] - 1].push_back(row[0] - 1);
        }

        // 构建结果
        vector<int> ans(N, 0);
        for (int i = 0; i < N; i++)
        {
            set<int> color = {1, 2, 3, 4};
            for (auto &edge : G[i])
                color.erase(ans[edge]);
            ans[i] = *(color.begin());
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    // vector<vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};
    // int N = 3;

    vector<vector<int>> paths = {{1, 2}, {3, 4}};
    int N = 4;

    Solution s;
    vector<int> ret = s.gardenNoAdj(N, paths);
    for (auto &color : ret)
        cout << color << ',';
    cout << endl;
    return 0;
}