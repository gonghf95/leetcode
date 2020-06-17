#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string toLowerCase(string str)
    {
        string ans;
        for (unsigned int i = 0; i < str.length(); i++)
            ans += tolower(str[i]);
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.toLowerCase("AbC") << endl;
    return 0;
}