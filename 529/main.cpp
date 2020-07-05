#include <iostream>
#include <vector>

using namespace std;

int eight_direction[8][2] = {
    {-1, -1}, // 左上
    {-1, 0},  // 上
    {-1, 1},  // 右上
    {0, -1},  // 左
    {0, 1},   // 右
    {1, -1},  // 左下
    {1, 0},   // 下
    {1, 1}    // 右下
};

class Solution
{
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, int x, int y)
    {
        visit[x][y] = true;

        int w = board.size();
        int h = board[0].size();

        int mine = 0;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + eight_direction[i][0];
            int ny = y + eight_direction[i][1];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) // 超出边界
                continue;
            if (board[nx][ny] == 'M')
                mine++;
        }

        if (mine > 0)
        {
            board[x][y] = '0' + mine;
            return;
        }

        board[x][y] = 'B';

        for (int i = 0; i < 8; i++)
        {
            int nx = x + eight_direction[i][0];
            int ny = y + eight_direction[i][1];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) // 超出边界
                continue;
            if (visit[nx][ny]) // 已经访问过了
                continue;
            visit[nx][ny] = true;
            dfs(board, visit, nx, ny);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        int w = board.size();
        int h = board[0].size();

        vector<vector<bool>> visit(w, vector<bool>(h, false)); 
        dfs(board, visit, x, y);
        return board;
    }
};

int main(int argc, char *argv[])
{
    // vector<vector<char>> board = {
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'E', 'M', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'},
    //     {'E', 'E', 'E', 'E', 'E'}};
    // vector<int> click = {3, 0};

    vector<vector<char>> board = {
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'M', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'}};
    vector<int> click = {1, 2};

    Solution s;
    vector<vector<char>> ret = s.updateBoard(board, click);
    for (auto &row : ret)
    {
        for (auto &col : row)
            cout << col << '\t';
        cout << endl;
    }
    return 0;
}