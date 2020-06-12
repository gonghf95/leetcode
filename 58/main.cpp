#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.length();
        int end = len - 1;
        int begin;
        while (end >= 0 && isspace(s[end]))
            end--;
        if (end < 0)
            return 0;
        begin = end - 1;
        while (begin >= 0 && !isspace(s[begin]))
            begin--;
        return end - begin;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.lengthOfLastWord("a  ") << endl;
    return 0;
}