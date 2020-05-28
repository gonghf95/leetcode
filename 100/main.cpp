#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) { }
};

class Solution
{
public:
	bool isSameTree( TreeNode* p, TreeNode* q )
	{
		if( p == NULL && q == NULL )
			return true;
		else if( p != NULL && q != NULL && p->val == q->val )
		{
			bool left = isSameTree( p->left, q->left );
			bool right = isSameTree( p->right, q->right );
			return left && right;
		}
		return false;
	}
};

int main( int argc, char* argv[] )
{
	TreeNode* n1 = new TreeNode( 10 );
	TreeNode* n2 = new TreeNode( 5 );
	TreeNode* n3 = new TreeNode( 15 );
	TreeNode* n4 = new TreeNode( 10 );
	TreeNode* n5 = new TreeNode( 5 );
	TreeNode* n6 = new TreeNode( 15 );
	n1->left = n2;
	n1->right = n3;
	n4->left = n5;
	n5->right = n6;

	Solution s;
	cout << s.isSameTree( n1, n4 ) << endl;
	return 0;
}
