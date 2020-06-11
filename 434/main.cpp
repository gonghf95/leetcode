#include <iostream>

using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        s += ' ';
        int cnt = 0;
        int len = s.length();
        for (int i = 0; i < len - 1; ++i)
        {
            if (!isspace(s[i]) && isspace(s[i + 1]))
                ++cnt;
        }
        return cnt;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.countSegments("Hello, my name is John") << endl;
    return 0;
}