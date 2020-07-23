#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int h = grid.size();
        if (h == 0)
            return 0;
        int w = grid[0].size();

        int direction[][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        vector<vector<bool>> visit(h, vector<bool>(w, false));
        queue<pair<int, int>> que;
        que.push({0, 0});
        visit[0][0] = true;
        while (!que.empty())
        {
            pair<int, int> pos = que.front();
            que.pop();

            int min = INT32_MAX;
            for (int i = 0; i < 2; i++)
            {
                int px = pos.first + direction[i][0];
                int py = pos.second + direction[i][1];
                if (px < 0 || py < 0)
                    continue;

                if (min > grid[px][py])
                    min = grid[px][py];
            }
            if (min != INT32_MAX)
                grid[pos.first][pos.second] += min;

            int w = grid[pos.first].size();
            if ((pos.first == h - 1) && (pos.second == w - 1)) // 右下节点
                return grid[pos.first][pos.second];

            for (int i = 2; i < 4; i++)
            {
                int nx = pos.first + direction[i][0];
                int ny = pos.second + direction[i][1];
                if (nx >= h || ny >= w || visit[nx][ny])
                    continue;

                visit[nx][ny] = true;
                que.push({nx, ny});
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    // vector<vector<int>> grid = {
    //     {1, 2, 5},
    //     {3, 2, 1}};

    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}