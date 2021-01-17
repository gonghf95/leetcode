#include <iostream>
#include <deque>
#include <stdio.h>

#define local

using namespace std;

class Solution
{
public:
	string removeOuterParentheses(string S)
	{
		string result;
		if(S.length() <= 0)
			return result;

		deque<char> qc;

		int leftBracketNum = 0;
		int rightBracketNum = 0;
		for(size_t i=0; i<S.length(); i++)
		{
			if(S[i] == '(')
				++leftBracketNum;
			else if(S[i] == ')')
				++rightBracketNum;

			qc.push_back(S[i]);

			if(leftBracketNum == rightBracketNum)
			{
				if(!qc.empty())
					qc.pop_front();
				if(!qc.empty())
					qc.pop_back();

				while(!qc.empty())
				{
					result += qc.front();
					qc.pop_front();
				}
			}
		}
		
		return result;
	}
};

int main(int argc, char* argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	string S;
	Solution s;

	cin >> S;
	cout << s.removeOuterParentheses(S) << endl;
	return 0;
}
