#include <iostream>

using namespace std;

namespace hongfu01 {
class Solution
{
public:
    int hanmingWight(uint32_t n)
    {
        int count = 0;
        while(n)
        {
            if(n%2)
                ++count;
            n = n >> 1;
        }
        return count;
    }
};
}

int main(int argc, char *argv[])
{
    hongfu01::Solution s;
    cout << s.hanmingWight(11) << endl;
}