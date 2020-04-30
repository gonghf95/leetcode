#include <iostream>
#include <stack>

#define local

using namespace std;

namespace hongfu01 {
class Solution
{
public:
	bool isValid(string s)
	{
		char ch, top;
		stack<char> sc;
		for(unsigned int i=0; i<s.length(); i++)
		{
			ch = s[i];
			if(ch == '(' || ch == '[' || ch == '{')
				sc.push(ch);
			else
			{
				if(sc.empty())
					return false;
				top = sc.top();
				sc.pop();
				if((top=='(' &&ch==')') || (top=='['&&ch==']') || (top=='{'&&ch=='}'))
					continue;
				return false;
			}

		}
		return sc.empty();
	}
};
}

int main(int argc, char *argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	string data;
	hongfu01::Solution solution;
	while(cin>>data)
	{
		cout << solution.isValid(data) << endl;
	}
	return 0;
}
