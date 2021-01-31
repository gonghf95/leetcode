#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#define local

using namespace std;

class Solution
{
public:
	int calPoints(vector<string>& ops)
	{
		stack<int> si;
		for(vector<string>::const_iterator it=ops.begin(); it!=ops.end(); ++it)
		{
			if(*it == "+")
			{
				int a = si.top(); si.pop();
				int b = si.top(); 
				int sum = a + b;
				si.push(a);
				si.push(sum);
			}
			else if(*it == "D")
			{
				si.push(si.top()*2);
			}
			else if(*it == "C")
			{
				si.pop();
			}
			else
			{
				si.push(atoi(it->data()));
			}
		}

		int sum = 0;
		while(!si.empty())
		{
			sum += si.top();
			si.pop();
		}
		return sum;
	}
};

int main(int argc, char* argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
#endif
	vector<string> ops;
	string s;
	while(cin >> s)
		ops.push_back(s);

	Solution S;
	cout << S.calPoints(ops) << endl;
	return 0;
}
