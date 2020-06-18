#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> vs = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> ss;
        for (unsigned int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            string str;
            for (unsigned int j = 0; j < word.size(); j++)
                str += vs[word[j] - 'a'];
            ss.insert(str);
        }
        return ss.size();
    }
};

int main(int argc, char *argv[])
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution s;
    cout << s.uniqueMorseRepresentations(words) << endl;
    return 0;
}