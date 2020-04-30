#include <iostream>
#include <vector>
#include <stack>

#define local

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

namespace hongfu01 {
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		TreeNode *ptr=root;
		stack<TreeNode *> st;

		while(ptr!=NULL || !st.empty())
		{
			if(ptr!=NULL)
			{
				st.push(ptr);
				ptr = ptr->left;
			}
			else
			{
				ptr = st.top();
				st.pop();
				result.push_back(ptr->val);
				ptr = ptr->right;
			}
		}

		return result;
	}
};
}

int main(int argc, char *argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	TreeNode *root = new TreeNode(2);
	TreeNode *lchild = new TreeNode(1);
	TreeNode *rchild = new TreeNode(3);

	root->left = lchild;
	root->right = rchild;

	hongfu01::Solution s;
	vector<int> ret = s.inorderTraversal(root);
	for(auto it=ret.begin(); it!=ret.end(); it++)
		cout << " " << *it;
	cout << endl;

	delete root;
	delete lchild;
	delete rchild;
	return 0;
}
