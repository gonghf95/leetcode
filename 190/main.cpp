#include <iostream>

using namespace std;

namespace hongfu01 {
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int bits = 32;
        while(bits--) {
            ans<<=1;
            ans|=n&1;
            n>>=1;
        }
        return ans;
    }
};
}

namespace hongfu02 {
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
        n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
        n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
        n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
        return n;
    }
};
}

int main(int argc, char *argv[]) {
    hongfu02::Solution s;
    cout << s.reverseBits(1) << endl;
    return 0;
}