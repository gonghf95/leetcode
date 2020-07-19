#include <iostream>
#include <string>

using namespace std;

namespace hongfu01
{
    enum CHECK_STATE
    {
        OPEN,
        CLOSE
    };

    class Solution
    {
    public:
        int myAtoi(string str)
        {
            CHECK_STATE state = OPEN;
            int sign = 1;
            long ans = 0;
            for (auto &ch : str)
            {
                if (state == OPEN && ch == ' ')
                    continue;

                if (state == OPEN && (ch == '-' || ch == '+'))
                {
                    sign = (ch == '-') ? -1 : 1;
                    state = CLOSE;
                }
                else if (ch >= '0' && ch <= '9')
                {
                    state = CLOSE;
                    ans *= 10;
                    ans += (int)(ch - '0');
                    if (ans > INT32_MAX)
                        break;
                }
                else
                    break;
            }

            ans *= sign;
            if (ans > INT32_MAX)
                ans = INT32_MAX;
            else if (ans < INT32_MIN)
                ans = INT32_MIN;
            return ans;
        }
    };
} // namespace hongfu01

int main(int argc, char *argv[])
{
    // string s("     21");
    // string str("    -21");
    // string str("-91283472332");
    // string str("4193 with words");
    // string str("words and 987");
    // string str("99-99");
     string str("+-99-99");
    hongfu01::Solution s;
    cout << s.myAtoi(str) << endl;
    return 0;
}
