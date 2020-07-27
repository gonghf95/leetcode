#include <iostream>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == t)
            return true;
        if (s.length() > t.length())
            return false;

        int i, j;
        int slen = s.length();
        int tlen = t.length();

        i = j = 0;
        while (i < slen && j < tlen)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }

        if (i == slen)
            return true;
        return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}