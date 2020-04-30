#include <iostream>
#include <stdlib.h>
#include <vector>

#define local

using namespace std;

namespace test01{
class Solution
{
public:
	vector<int> TowSum(vector<int> &nums, int target) 
	{
		int sum;
		unsigned int i, j;
		vector<int> result;
		int found;

		i = j = sum = found = 0;
		for(i=0; i<nums.size(); i++)
		{
			found = 0;
			sum = nums[i];
			for(j=i+1; j<nums.size(); j++)
			{
				sum += nums[j];
				if(sum == target)
				{
					result.clear();
					result.push_back(i);
					result.push_back(j);
					found = 1;
					break;
				}
				else
				{
					sum -= nums[j];
				}
			}

			if(found)
				break;
		}
		return result;
	}
};

void test(vector<int> &nums, int target)
{
	Solution s;
	vector<int> result;
	vector<int>::iterator it;

	result = s.TowSum(nums, target);
	cout << "[";
	for(it=result.begin(); it!=result.end(); it++)
	{
		if(it != result.begin())cout << ',';
		cout << *it;
	}
	cout << "]\n";
}

void run() 
{
	int n;
	int data;
	int target;
	vector<int> vi;
	while((cin>>n>>target) &&(n!=-1)&&(target!=-1))
	{
		vi.clear();
		for(int i=0; i<n; i++)
		{
			cin >> data;
			vi.push_back(data);
		}
		test(vi, target);
	}

}
}

namespace test02 {

int *read(int *size, int *target)
{
	int *nums;
	cin >> *size >> *target;
	if(*size <= 0)
		return NULL;
	nums = (int *)malloc(sizeof(int)*(*size));
	for(int i=0; i<*size; i++)
		cin >> nums[i];
	return nums;
}

void pr_nums(int *nums, int size)
{
	cout << '[';
	for(int i=0; i<size; i++)
	{
		if(i!=0) cout << ',';
		cout << nums[i];
	}
	cout << ']' << endl;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int i, j, sum;
	int found;
	int *result = NULL;

	*returnSize = i = j = sum = found = 0;
	for(i=0; i<numsSize; i++)
	{
		found = 0;
		sum = nums[i];
		for(j=i+1; j<numsSize; j++)
		{
			sum += nums[j];
			if(sum == target)
			{
				*returnSize = 2;
				result = (int *)malloc(sizeof(int) * (*returnSize));
				result[0] = i;
				result[1] = j;
				found = 1;
				break;
			}
			else
			{
				sum -= nums[j];
			}
		}

		if(found)
			break;
	}
	return result;
}

void run()
{
	int *nums, size, target, *result, returnSize, round;
	round = 1;
	while((nums = read(&size, &target)) != NULL)
	{
		cout << "round " << round++ << ':' << endl;
		returnSize = 0;
		result = twoSum(nums, size, target, &returnSize);
		if(returnSize >= 0)
		{
			pr_nums(result, returnSize);
			free(result);
		}
		free(nums);
	}
}
}

int main(int argc, char *argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	test02::run();
	return 0;
}
