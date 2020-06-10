#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() <= 0)
            return 0;
        vector<char> vc;
        int ans = 0;
        int offset;
        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int k = 0;
        unsigned int w = 0;
        unsigned int len = 0;
        for (j = 1; j < chars.size(); j++)
        {
            if (chars[i] != chars[j])
            {
                ans++;
                chars[w] = chars[i];
                offset = j - i;
                if (offset > 1)
                {
                    char buf[4] = {0};
                    sprintf(buf, "%d", offset);
                    len = strlen(buf);
                    for (k = 0; k < len; k++)
                        chars[++w] = buf[k];
                    ans += len;
                }
                i = j;
                ++w; // forward
            }
        }

        if (i != j - 1)
        {
            ans++;
            chars[w] = chars[i];
            offset = j - i;
            if (offset > 1)
            {
                char buf[4] = {0};
                sprintf(buf, "%d", offset);
                len = strlen(buf);
                for (k = 0; k < len; k++)
                    chars[++w] = buf[k];
                ans += len;
            }
        }
        else
        {
            ans++;
            chars[w] = chars[i];
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    // vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c'};
    // vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    // vector<char> chars = {'a'};
    // vector<char> chars = {'a', 'b', 'c', 'c'};
    // vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    // vector<char> chars = {'a', 'a'};
    vector<char> chars;
    Solution s;
    cout << s.compress(chars) << endl;

    vector<char>::iterator it = chars.begin();
    while (it != chars.end())
    {
        cout << *it << ' ';
        it++;
    }
    cout << endl;
    return 0;
}