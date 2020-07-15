#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        // 1, 2, 3, 4, 5
        int *dp = new int[n + 1];
        memset(dp, 0, sizeof(int) * (n + 1));

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        int ans = dp[n];
        delete[] dp;
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}