#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>

#define local

using namespace std;

namespace hongfu01
{
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mii;
        for(unsigned int i=0; i<nums.size(); i++)
        {
            if(mii.count(nums[i]) <= 0)
                mii[nums[i]] = 0;
            mii[nums[i]]++;
        }

        map<int, int>::iterator it = mii.begin();
        while(it!=mii.end())
        {
            if(it->second == 1)
                return it->first;
            it++;
        }
        
        return -1;
    }
}; // class Solution
} // namespace hongfu01


int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif
    int data;
    vector<int> nums;
    while(cin>>data && data!=-1)
        nums.push_back(data);

    hongfu01::Solution s;
    clock_t beginTime = clock();
    cout << s.singleNumber(nums) << endl;
    cout << "time: " << clock() - beginTime << endl;
    return 0;
}