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
	int rangeSumBST( TreeNode* root, int L, int R )
	{
		if( root != NULL )
		{
			int left = rangeSumBST( root->left, L, R );
			int right = rangeSumBST( root->right, L, R );
			if( root->val >= L && root->val <= R )
				return left + right + root->val;
			else
				return left + right;
		}
		return 0;
	}
};

int main( int argc, char* argv[] )
{
	TreeNode n1( 10 );
	TreeNode n2( 5 );
	TreeNode n3( 15 );
	TreeNode n4( 3 );
	TreeNode n5( 7 );
	TreeNode n6( 18 );
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.right = &n6;

	Solution s;
	cout << s.rangeSumBST( &n1, 7, 15 ) << endl;
	return 0;
}
