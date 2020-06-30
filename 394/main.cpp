#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /**
     * 输入：s = "3[a2[c]]"
     * 输出："accaccacc"
     * 
     * 1、数字，字母， [， ]
     * 
    */
    string decodeString(string s)
    {
        stack<int> si;
        stack<char> sc;
        int num = 0;
        for (unsigned int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0'); // 计算压缩个数
            }
            else if (isalpha(s[i]))
            {
                sc.push(s[i]);
            }
            else if (s[i] == '[')
            {
                si.push(num); // 获取个数，清空
                num = 0;
                sc.push(s[i]);
            }
            else if (s[i] == ']')
            {
                vector<char> vc;
                char ch;
                while ((ch = sc.top()) != '[')
                {
                    vc.push_back(ch);
                    sc.pop();
                }
                reverse(vc.begin(), vc.end());
                sc.pop();

                int cnt = si.top();
                si.pop();
                while (cnt--)
                {
                    for (unsigned int k = 0; k < vc.size(); k++)
                        sc.push(vc[k]);
                }
            }
        }

        string ans;
        while (!sc.empty())
        {
            ans += sc.top();
            sc.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char *argv[])
{
    // string str("3[a2[c]]");
    // string str("2[abc]3[cd]ef");
    string str("abc3[cd]xyz");
    Solution s;
    cout << s.decodeString(str) << endl;
    return 0;
}