#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _point_ {
    int x, y;
    _point_(int x, int y) : x(x), y(y) {};
    _point_(const _point_ & p)
    {
        this->x = p.x;
        this->y = p.y;
    }
} point_t;

int direction[][2] ={
    { -1, 0 }, // up
    { 0, 1 }, // right
    { 1, 0 }, // down
    { 0, -1 } // left
};

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int h = image.size();
        int w = image[0].size();

        queue<point_t> que;
        que.push(point_t(sr, sc));

        vector<vector<int>> ans(image);
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        visited[sr][sc] = true;
        while (!que.empty())
        {
            point_t point = que.front();
            que.pop();
            for (int i=0; i<4; i++)
            {
                int nx = point.x + direction[i][0];
                int ny = point.y + direction[i][1];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;

                if (visited[nx][ny]) // already visited
                    continue;

                if (image[nx][ny] != image[sr][sc])
                    continue;

                visited[nx][ny] = true; // mark
                que.push(point_t(nx, ny));
            }
            ans[point.x][point.y] = newColor;
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> image ={
        { 1, 1, 1 },
        { 1, 1, 0 },
        { 1, 0, 1 }
    };
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    Solution s;
    vector<vector<int>> ret = s.floodFill(image, sr, sc, newColor);
    for (int h=0; h<ret.size(); h++)
    {
        for (int w=0; w<ret[h].size(); w++)
            cout << ret[h][w] << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
}