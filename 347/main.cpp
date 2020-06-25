#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

struct elem
{
    int num;
    int cnt;
    elem(int n, int c) : num(n), cnt(c) {}
};

struct cmp
{
    bool operator()(elem &e1, elem &e2)
    {
        return e1.cnt > e2.cnt;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umii;
        for (int &num : nums)
        {
            if (umii.count(num) <= 0)
                umii[num] = 0;
            umii[num]++;
        }

        priority_queue<elem, vector<elem>, cmp> pq;
        for (auto &ii : umii)
        {
            pq.push(elem(ii.first, ii.second));
            if (pq.size() > (unsigned int)k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().num);
            pq.pop();
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    // vector<int> nums = {1, 1, 1, 2, 2, 3};
    // int k = 2;
    vector<int> nums = {1};
    int k = 1;
    Solution s;
    vector<int> ret = s.topKFrequent(nums, k);
    for (auto &num : ret)
        cout << num << ',';
    cout << endl;
    return 0;
}