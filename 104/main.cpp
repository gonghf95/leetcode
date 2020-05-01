#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

namespace hongfu01{
class Solution 
{
public:
	int maxDepth(TreeNode *root)
	{
		if(root==NULL)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};
}

namespace hongfu02{
class Solution
{
public:
	int maxDepth(TreeNode *root)
	{
		if(root==NULL)
			return 0;

		int depth = 0;
		queue<TreeNode *> que;
		que.push(root);
		while(!que.empty())
		{
			/*queue<TreeNode *> tmp;
			while(!que.empty())
			{
				TreeNode *ptr = que.front();
				que.pop();
				if(ptr->left!=NULL)
					tmp.push(ptr->left);
				if(ptr->right!=NULL)
					tmp.push(ptr->right);
			}
			while(!tmp.empty())
			{
				TreeNode *ptr = tmp.front();
				tmp.pop();
				que.push(ptr);
			}*/

			/* a much better implement than above. not use a temp queue. */
			int size = que.size();
			for(int i=0; i<size; i++)
			{
				TreeNode *ptr = que.front();
				if(ptr->left!=NULL)
					que.push(ptr->left);
				if(ptr->right!=NULL)
					que.push(ptr->right);
				que.pop();
			}
			++depth;
		}
		return depth;
	}
}; /* class Solution */
} /* namespace hongfu02 */

int main(int argc, char *argv[])
{
	TreeNode *root = new TreeNode(2);
	TreeNode *lchild = new TreeNode(1);
	TreeNode *rchild = new TreeNode(3);
	root->left = lchild;
	root->right = rchild;
	
	clock_t beginTime = clock();
	hongfu01::Solution s;
	cout << s.maxDepth(root) << endl;
	cout << "time: " << clock() - beginTime << endl;
	beginTime = clock();
	hongfu02::Solution s2;
	cout << s2.maxDepth(root) << endl;
	cout << "time: " << clock() - beginTime << endl;

	delete root;
	delete lchild;
	delete rchild;
	return 0;
}
