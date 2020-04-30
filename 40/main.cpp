#include <iostream>
#include <vector>
#include <algorithm>

#define local

using namespace std;

namespace hongfu01 {
class Solution
{
public:
	vector<int> getLeastNumbers(vector<int> &arr, int k)
	{
		vector<int> result;
		sort(arr.begin(), arr.end());
		for(unsigned int i=0; (int)i<k && i<arr.size(); i++)
		{
			result.push_back(arr[i]);
		}
		return result;
	}
};
}

namespace hongfu02{
class Solution
{
public:
	vector<int> getLeastNumbers(vector<int> &arr, int k)
	{
		vector<int> result;
		sort_bubble(arr);
		for(unsigned int i=0; (int)i<k && i<arr.size(); i++)
		{
			result.push_back(arr[i]);
		}
		return result;
		
	}
private:
	void sort_bubble(vector<int> &arr)
	{
		unsigned int i, j, tmp;
		for(i=0; i<arr.size(); i++)
		{
			for(j=i+1; j<arr.size(); j++)
			{
				if(arr[i] > arr[j])
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
};
}

int main(int argc, char *argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	int tmp, k;
	vector<int> data;
	clock_t beginTime;
	vector<int> result;

	cin >> k;
	while(cin>>tmp)
		data.push_back(tmp);
	hongfu02::Solution s;

	beginTime = clock();
	result = s.getLeastNumbers(data, k);
	cout << "time cost: " << clock()-beginTime << endl;
	for(auto it=result.begin(); it!=result.end(); it++)
		cout << " " << *it;
	cout << endl;
	return 0;
}
