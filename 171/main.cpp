#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cstdio>

#define local

using namespace std;

namespace hongfu01 {
class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0;
        int len = s.length();
        int val;
        unsigned int base = 1;
        for(int i=len-1; i>-1; i--)
        {
            val = (int)(tolower(s[i]) - 'a') + 1;
            result += base*val;
            base *= 26;
        }
        return result;
    }
};
}

int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    string data;
    hongfu01::Solution s;
    while(cin>>data)
    {
        cout << data << ":\t" << s.titleToNumber(data) << endl;
    }
    return 0;
}