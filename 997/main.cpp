#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        int *in = new int[N + 1];
        int *out = new int[N + 1];

        memset(in, 0, sizeof(int) * (N + 1));
        memset(out, 0, sizeof(int) * (N + 1));

        for (auto &row : trust)
        {
            int vertex = row[0];
            for (unsigned int i = 1; i < row.size(); i++)
            {
                // a->b, a->c
                // in[b]++, in[c]++, out[a]++
                out[vertex]++;
                in[row[i]]++;
            }
        }

        int cnt = 0;
        int ans = -1;
        for (int i = 1; i <= N; i++)
        {
            if (out[i] > 0)
                continue;

            if (in[i] != N - 1)
                continue;

            if (cnt > 1)
                break;

            ans = i;
            ++cnt;
        }

        delete[] in;
        delete[] out;

        return cnt == 1 ? ans : -1;
    }
};

int main(int argc, char *argv[])
{
    // vector<vector<int>> trust = {{1, 2}};
    // int N = 2;

    // vector<vector<int>> trust = {{1, 3}, {2, 3}};
    // int N = 3;

    // vector<vector<int>> trust = {{1, 3}, {2, 3}, {3, 1}};
    // int N = 3;

    // vector<vector<int>> trust = {{1, 2}, {2, 3}};
    // int N = 3;

    vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    int N = 4;

    Solution s;
    cout << s.findJudge(N, trust) << endl;
    return 0;
}