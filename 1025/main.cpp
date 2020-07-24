#include <iostream>
#include <vector>

#define local

using namespace std;

class Solution
{
public:
    bool divisorGame(int N)
    {
        int who = 1;
        for (int i = 1; i < N; i++)
        {
            if (N % i == 0)
            {
                N -= i;
                i = 0;
                who = (who == 0) ? 1 : 0;
            }
        }
        return who == 0;
    }
};

int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int N;
    cin >> N;
    Solution s;
    cout << s.divisorGame(N) << endl;
    return 0;
}