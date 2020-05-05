#include <iostream>

using namespace std;

namespace hongfu01
{
class Solution
{
public:
    int getSum(int a, int b) 
    {
        while (b) 
        {
            auto carry = ((unsigned int)(a & b)) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
} // namespace hongfu01

int main(int arc, char *argv[])
{
    hongfu01::Solution s;
    cout << s.getSum(3, 5) << endl;
    return 0;
}