#define local
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace hongfu01
{
class Solution 
{
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> result;
        for(int i=1; i<=n; i++)
        {
            char buf[10] = {0};
            if(i%3==0 && i%5==0)
            {
                sprintf(buf, "FizzBuzz");
            }
            else if(i%3==0)
            {
                sprintf(buf, "Fizz");
            }
            else if(i%5==0)
            {
                sprintf(buf, "Buzz");
            }
            else
            {
                sprintf(buf, "%d", i);
            }
            result.push_back(buf);
        }
        return result;
    }
}; // class Solution
} // namespace hongfu01


int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif
    int n;
    hongfu01::Solution s;
    cin>>n;
    vector<string> result = s.fizzBuzz(n);
    vector<string>::iterator it = result.begin();
    while(it!=result.end())
    {
        if(it!=result.begin()) cout << ',';
        cout << *it;
        it++;
    }
    cout << endl;
    return 0;
}