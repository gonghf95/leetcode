#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Find(int a)
    {
        int fa = father[a];
        if (fa == a)
            return a;
        return father[a] = Find(fa);
    }

    void Union(int a, int b)
    {
        int fb = Find(b);
        int fa = Find(a);
        if (fa < fb)
            father[fb] = fa;
        else
            father[fa] = fb;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int size = graph.size();
        father = new int[size];
        for (int i = 0; i < size; i++)
            father[i] = i;

        for (int i = 0; i < size; i++) // 顶点
        {
            vector<int> edges = graph[i];
            for (auto &edge : edges)
            {
                if (Find(i) == Find(edge))
                    return false;
                Union(edges[0], edge);
            }
        }
        delete[] father;
        return true;
    }

private:
    int *father;
};

int main(int argc, char *argv[])
{
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    Solution s;
    cout << s.isBipartite(graph) << endl;
    return 0;
}