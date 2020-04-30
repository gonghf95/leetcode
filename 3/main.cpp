#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <string.h>

#include <time.h>

#define local

using namespace std;

namespace hongfu01 {
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int max=0, round=0;
		int len=s.length();
		bool tick[128] = {0};
		int pos;
		
		for(int i=0; i<len; i++)
		{
			memset(tick, 0, sizeof(tick));
			round = 0;
			for(int j=i; j<len; j++)
			{
				pos = s[j];
				if(tick[pos] == true)
					break;
				round++;
				tick[pos] = true;
			}
			if(round > max)
				max = round;
		}
		return max;
	}
};
}

namespace hongfu02 {
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int max = 0;
		unordered_set<char> usc;
		usc.insert('d');
		usc.insert('a');
		usc.insert('b');
		usc.insert('a');
		usc.insert('c');
		unordered_set<char>::iterator it;
		it = usc.find('a');
		usc.erase('a');
		if(it != usc.end())
			cout << ' ' << *it;
		cout << endl;
		for(it=usc.begin(); it!=usc.end(); it++)
			cout << " " << *it;
		cout << endl;
		return max;
	}
};
}

int main(int argc, char *argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	clock_t beginTime = clock();
	string data;
	hongfu02::Solution solution;
	while(cin >> data)
	{
		cout << solution.lengthOfLongestSubstring(data) << endl;
	}
	cout << "time: " << clock() - beginTime << "ms\n";
	return 0;
}
