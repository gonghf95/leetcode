#include <iostream>
#include <stack>

#define local

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

namespace hongfu01 {
class Solution 
{
public:
	bool isValidBST( TreeNode *root )
	{
		if( root==NULL )
			return true;

		stack<TreeNode *> st, last;
		TreeNode *ptr = root, *ptr2;

		while( ptr!=NULL || !st.empty() )
		{
			if( ptr!=NULL )
			{
				st.push(ptr);
				ptr = ptr->left;
			}
			else
			{
				ptr = st.top();
				st.pop();
				if(!last.empty())
				{
					ptr2 = last.top();
					if(ptr2->val >= ptr->val)
						return false;
					last.pop();
				}
				last.push(ptr);
				ptr = ptr->right;
			}
		}
		return true;
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
	TreeNode *c1 = new TreeNode(1);
	TreeNode *c2 = new TreeNode(3);
	root->left = c1;
	root->right = c2;
	hongfu01::Solution s;
	cout << s.isValidBST(root) << endl;
	delete root;
	delete c1;
	delete c2;
	return 0;
}
