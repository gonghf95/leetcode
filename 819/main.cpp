#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        int len = paragraph.length();
        for (int i = 0; i < len; i++)
            paragraph[i] = isalpha(paragraph[i]) ? tolower(paragraph[i]) : ' ';

        stringstream ss(paragraph);
        string word;
        map<string, int> msi;
        string ans;
        int max = 0;
        while (ss >> word)
        {
            if (find(banned.begin(), banned.end(), word) == banned.end())
            {
                if (msi.count(word) <= 0)
                    msi[word] = 0;
                msi[word]++;

                if(msi[word] > max)
                {
                    max = msi[word];
                    ans = word;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<string> banned = {"abc"};
    Solution s;
    cout << s.mostCommonWord("aBc, Sss, sdf", banned) << endl;
    return 0;
}