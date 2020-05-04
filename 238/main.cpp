#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace hongfu01
{
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i, j;
        for(i=nums.size()-1; i>=0; i--)
        {
            j = i;
            while(j>=0 && nums[j]!=0)
                j--;
            
            if(j>=0)
            {
                while(j<i)
                {
                    nums[j] = nums[j+1];
                    j++;
                }
                nums[i] = 0;
            }
        }
    }
};
} // namespace hongfu01

namespace hongfu02
{
class Solution 
{
public:
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}
};
} // namespace hongfu02

int main(int argc, char *argv[])
{
    vector<int> data;
    data.push_back(1);
    data.push_back(0);
    data.push_back(2);
    data.push_back(3);
    data.push_back(12);

    hongfu02::Solution s;
    s.moveZeroes(data);

    vector<int>::iterator it = data.begin();
    while(it!=data.end())
    {
        cout << ' ' << *it;
        it++;
    }
    cout << endl;
    return 0;
}