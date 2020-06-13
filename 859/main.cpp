#include <iostream>

using namespace std;

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        int alen = A.length();
        int blen = B.length();
        if (alen < 2 || blen < 2)
            return false;

        if (alen != blen)
            return false;

        int diff_pos[3];
        int diff_count = 0;
        int alp_a[26] = {0};
        int alp_b[26] = {0};
        for (int i = 0; i < alen; i++)
        {
            if (diff_count > 2)
                return false;

            if (A[i] != B[i])
                diff_pos[diff_count++] = i;
    
            alp_a[A[i] - 'a']++;
            alp_b[B[i] - 'a']++;
        }

        if (diff_count == 2)
            return (A[diff_pos[0]] == B[diff_pos[1]]) && (A[diff_pos[1]] == B[diff_pos[0]]);
        else if (diff_count < 2)
        {
            for (int i = 0; i < 26; i++)
                if (alp_a[i] > 1)
                    return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.buddyStrings("abcd", "badc") << endl;
    return 0;
}