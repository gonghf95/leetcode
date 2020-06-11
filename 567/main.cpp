#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2)
            return false;

        int alphabet_save[26] = {0};
        int alphabet[26] = {0};

        for (int i = 0; i < len1; i++)
        {
            alphabet[s1[i] - 'a']++;
            alphabet_save[s1[i] - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < len2; right++)
        {
            alphabet_save[s2[right] - 'a']--;
            if ((right - left + 1) >= len1)
            {
                int i;
                for (i = 0; i < 26; i++)
                {
                    if (alphabet_save[i] != 0)
                    {
                        right = left++;
                        memcpy(alphabet_save, alphabet, sizeof(int) * 26);
                        break;
                    }
                }

                if (i == 26)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.checkInclusion("ab", "eidboaoo") << endl;
    return 0;
}