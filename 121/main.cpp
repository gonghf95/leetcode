#include <iostream>
#include <vector>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int maxProfit(vector<int> &prices)
        {
            if(prices.size() <= 0)
                return 0;

            int mp = 0;
            vector<int> dp(prices.size(), 0);
            // 第i天最佳价格=max(dp[i-1], 第i天价格-(i-1)天前最低价格)
            for (unsigned i = 1; i < prices.size(); i++)
            {
                dp[i] = max(dp[i - 1], prices[i] - prices[mp]);
                if(prices[i] < prices[mp])
                    mp = i;
            }
            return dp[prices.size() - 1];
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        int maxProfit(vector<int> &prices)
        {
            int ans = 0;
            for (unsigned int i = 1; i < prices.size(); i++)
                for (int j = i - 1; j >= 0; j--)
                    if ((prices[i] - prices[j]) > ans)
                        ans = prices[i] - prices[j];
            return ans;
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    hongfu01::Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}