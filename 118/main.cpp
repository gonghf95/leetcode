#define local
#include <iostream>
#include <vector>

using namespace std;

namespace hongfu01 {
class Solution {
public:
    vector< vector<int> > generate(int numRows)
    {
        if(numRows == 0)
            return vector< vector<int> >();
        if(numRows == 1)
            return vector< vector<int> >{vector<int>{1}};
        if(numRows == 2)
            return vector< vector<int> >{vector<int>{1}, vector<int>{1,1}};
        vector< vector<int> > all = generate(numRows-1);
        vector<int> prevLevel = all.back();
        vector<int> thisLevel = {1};
        for(unsigned int i=1; i<=prevLevel.size()-1; i++)
            thisLevel.push_back(prevLevel[i-1]+prevLevel[i]);
        thisLevel.push_back(1);
        all.push_back(thisLevel);
        return all;
    }
};
}

int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif
    int numRows;
    cin >> numRows;
    hongfu01::Solution s;
    clock_t beginTime = clock();
    vector< vector<int> > result = s.generate(numRows);
    cout << "time: " << clock() - beginTime << endl;
    for(unsigned int i=0; i<result.size(); i++)
    {
        vector<int> vi = result[i];
        for(unsigned int j=0; j<vi.size(); j++)
            cout << vi[j] << ' ';
        cout << endl;
    }
    return 0;
}