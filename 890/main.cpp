#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (unsigned int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if (word.length() != pattern.length())
                continue;

            int flag = 1;
            int wm[26];
            int pm[26];
            for (int j = 0; j < 26; j++)
            {
                wm[j] = -1;
                pm[j] = -1;
            }

            for (unsigned int j = 0; j < pattern.length(); j++)
            {
                int p1 = pattern[j] - 'a';
                int p2 = word[j] - 'a';
                if (wm[p1] == -1)
                    wm[p1] = p2;
                if (pm[p2] == -1)
                    pm[p2] = p1;
                if (wm[p1] != p2 || pm[p2] != p1)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    Solution s;
    vector<string> ret = s.findAndReplacePattern(words, "abb");
    for (unsigned int i = 0; i < ret.size(); i++)
        cout << ret[i] << endl;
    return 0;
}