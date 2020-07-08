#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
        {
            int ans = 0;
            for (unsigned int i = 0; i < needs.size(); i++)
                ans += needs[i] * price[i]; // 直接单个商品买，算总价格

            for (auto &choice : special)
            {
                int size = choice.size();
                int money = choice[size - 1];
                if (money >= ans) // 如果组合装价格已经比单个单个商品买价格高的话就排除掉
                    continue;

                int total = money;
                unsigned int i = 0;
                while (i < needs.size()) // 数量计算，把组合装的数量不足的用单件商品补上
                {
                    int diff = needs[i] - choice[i];
                    if (diff < 0)
                        break;

                    if (diff > 0) // 组合装数量不够
                    {
                        total += diff * price[i];
                        if (total > ans) // 如果组合装加上数量不足，补上不足商品的价格超过最小ans，不继续算了, 下一种方案
                            break;
                    }
                    i++;
                }
                if (total < ans && i == needs.size()) // 更新最低消费
                    ans = total;
            }
            return ans;
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        int minCost;

        int dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
        {
            int sum = 0;
            for (unsigned int i = 0; i < needs.size(); i++)
                sum += needs[i] * price[i]; // 直接单个商品买，算总价格

            int total = sum; // 当前方案总花费

            for (unsigned int i = 0; i < special.size(); i++)
            {
                bool suitable = true;
                vector<int> choice = special[i];
                vector<int> new_need(needs.size(), 0);

                for (unsigned int j = 0; j < needs.size(); j++)
                {
                    int diff = needs[j] - choice[j];
                    if (diff < 0)
                    {
                        suitable = false;
                        break;
                    }
                    else
                        new_need[j] = diff;
                }

                if (!suitable)
                    continue;

                int ret = dfs(price, special, new_need);
                total = min(total, ret + choice[choice.size() - 1]);
            }

            return total;
        }

        int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
        {
            return dfs(price, special, needs);
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    vector<int> price = {2, 5};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};

    // vector<int> price = {2, 3, 4};
    // vector<vector<int>> special = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    // vector<int> needs = {1, 2, 1};

    // vector<int> price = {9, 9};
    // vector<vector<int>> special = {{1, 1, 1}};
    // vector<int> needs = {2, 2};

    hongfu02::Solution s;
    cout << s.shoppingOffers(price, special, needs) << endl;
    return 0;
}