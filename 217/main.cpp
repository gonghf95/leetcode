#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace hongfu01 {
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> si;
        for(auto it=nums.begin(); it!=nums.end(); it++) {
            if(si.count(*it) > 0)
                return true;
            si.insert(*it);
        }
        return false;
    }
};
}

int main(int arg, char *argv[]) {
    return 0;
}