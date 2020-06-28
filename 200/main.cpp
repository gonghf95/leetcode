#include <iostream>
#include <vector>

using namespace std;

int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        if (row <= 0)
            return 0;
        int col = grid[0].size();

        cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>> &G, int x, int y)
    {
        G[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            unsigned int nx = x + direction[i][0];
            unsigned int ny = y + direction[i][1];
            if ((nx < G.size() && nx >= 0) && (ny < G[nx].size() && ny >= 0) && G[nx][ny] == '1')
            {
                dfs(G, nx, ny);
            }
        }
    }

private:
    int cnt;
};

int main(int argc, char *argv[])
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}