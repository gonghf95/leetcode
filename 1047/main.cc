#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution
{
public:
	string removeDuplicates(string S)
	{
		bool skip;
		deque<char> que;
		for(size_t i=0; i<S.length(); ++i)
		{
			skip = false;
			while(!que.empty() && que.back() == S[i])
			{
				que.pop_back();
				skip = true;
			}

			if(!skip)
				que.push_back(S[i]);
		}

		string result;
		while(!que.empty())
		{
			result += que.front();
			que.pop_front();
		}
		return result;
	}
};

#define local

int main(int argc, char* argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	string S;
	cin >> S;

	Solution s;
	cout << s.removeDuplicates(S) << endl;
	return 0;
}
