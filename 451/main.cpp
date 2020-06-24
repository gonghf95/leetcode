#include <iostream>
#include <unordered_map>
#include <queue>
#include <string.h>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        int len = s.length();
        unordered_map<char, int> mci;
        for (int i = 0; i < len; i++)
            mci[s[i]]++;

        priority_queue<pair<int, char>> pq;
        for (unordered_map<char, int>::iterator it = mci.begin(); it != mci.end(); it++)
            pq.push(pair<int, char>(it->second, it->first));

        string ret;
        while (!pq.empty())
        {
            pair<int, char> pic = pq.top();
            pq.pop();
            ret.append(pic.first, pic.second);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.frequencySort("sklfjlskkk") << endl;
    return 0;
}