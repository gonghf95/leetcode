#include <iostream>
#include <vector>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        void reverseString(vector<char> &s)
        {
            if(s.empty() || s.size()==1)
                return;
            
            int i = 0;
            int j = s.size() - 1;
            char ch;

            while (i<j)
            {
                ch = s[i];
                s[i] = s[j];
                s[j] = ch;
                i++;
                j--;
            }
        }
    }; // class Solution
} // namespace hongfu01

int main(int argc, char *argv[])
{
    hongfu01::Solution s;
    vector<char> data;
    data.push_back('a');
    data.push_back('b');
    data.push_back('c');
    data.push_back('d');
    data.push_back('e');

    clock_t beginTime = clock();
    s.reverseString(data);
    cout << "time: " << clock() - beginTime << endl;

    vector<char>::iterator it;
    for (it=data.begin(); it!=data.end(); it++) 
    {
        cout << " " << *it;
    }
    cout << endl;
    return 0;   
}