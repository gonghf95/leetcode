#include <iostream>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int strStr(string haystack, string needle)
        {
            int i = 0;
            int j = 0;
            int hlen = haystack.length();
            int nlen = needle.length();

            while (i < hlen && j < nlen)
            {
                if (haystack[i] == needle[j])
                {
                    ++i;
                    ++j;
                }
                else
                {
                    i = i - j + 1;
                    j = 0;
                }
            }
            if (j == nlen)
                return i - j;
            return -1;
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        void GetNext(string pattern, int next[])
        {
            next[0] = -1;
            int i = 0;
            int j = 0;
            int plen = pattern.length();
            while (i <= plen)
            {
                if (j == 0 || pattern[i] == pattern[j])
                {
                    ++i;
                    ++j;
                    next[i] = j;
                }
                else
                    j = next[j];
            }
        }

        int strStr(string haystack, string needle)
        {
            int *next = new int[needle.length()];
            GetNext(needle, next);

            int i = 0;
            int j = 0;
            int hlen = haystack.length();
            int nlen = needle.length();

            while (i < hlen && j < nlen)
            {
                if (haystack[i] == needle[j])
                {
                    ++i;
                    ++j;
                }
                else
                    j = next[j];
            }

            delete[] next;

            if (j == nlen)
                return i - j;
            return -1;
        }
    };
} // namespace hongfu02
int main(int argc, char *argv[])
{
    hongfu02::Solution s;
    cout << s.strStr("sdf", "abaabcac") << endl;
    return 0;
}