#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visit, int x, int y, int step)
        {
            if (matrix[x][y] == 0)
            {
                // if (step < matrix[x][y])
                //     matrix[x][y] = step;
                return step;
            }

            int w = matrix.size();
            int h = matrix[0].size();
            int direction[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for (int i = 0; i < 4; i++)
            {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                    continue;

                if (visit[nx][ny])
                    continue;

                visit[nx][ny] = true;
                int ret = dfs(matrix, visit, nx, ny, step + 1);
                if (matrix[nx][ny] > ret)
                    matrix[nx][ny] = ret;
                visit[nx][ny] = false;
            }
            // return step;
        }

        vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
        {
            int w = matrix.size();
            int h = matrix[0].size();

            for (int i = 0; i < w; i++)
                for (int j = 0; j < h; j++)
                    if (matrix[i][j] != 0)
                    {
                        matrix[i][j] = 0x3f3f3f3f;
                        vector<vector<bool>> visit(w, vector<bool>(h, false));
                        visit[i][j] = true;
                        matrix[i][j] = dfs(matrix, visit, i, j, 0);
                    }
            return matrix;
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
        {
            queue<pair<int, int>> que;

            int w = matrix.size();
            int h = matrix[0].size();

            for (int i = 0; i < w; i++)
                for (int j = 0; j < h; j++)
                    if (matrix[i][j] == 0)
                        que.push({i, j}); // 把所有0点加进去
                    else
                        matrix[i][j] = -1; // 设置未访问

            int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

            while (!que.empty())
            {
                pair<int, int> pos = que.front();
                que.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = pos.first + direction[i][0];
                    int ny = pos.second + direction[i][1];

                    if (nx < 0 || nx >= w || ny < 0 || ny >= h || matrix[nx][ny] != -1)
                        continue;

                    matrix[nx][ny] = matrix[pos.first][pos.second] + 1;
                    que.push({nx, ny}); // 扩展新节点
                }
            }

            return matrix;
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    // vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    // vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    // vector<vector<int>> matrix = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> matrix = {{0}, {0}, {0}, {0}, {0}};

    hongfu02::Solution s;
    vector<vector<int>> ret = s.updateMatrix(matrix);
    for (auto row : ret)
    {
        for (auto col : row)
            cout << col << '\t';
        cout << endl;
    }
    return 0;
}