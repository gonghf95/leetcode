#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};

class Solution
{
public:
	int minDepth( TreeNode* root )
	{
		if( root == NULL )
			return 0;
		if( root->left == NULL )
			return 1 + minDepth( root->right );
		if( root->right == NULL )
			return 1 + minDepth( root->left );
		return 1 + min( minDepth( root->left ), minDepth( root->right ) );
	}
};

int main( int argc, char* argv[] )
{
	TreeNode* n1 = new TreeNode( 3 );
	TreeNode* n2 = new TreeNode( 9 );
	TreeNode* n3 = new TreeNode( 20 );
	TreeNode* n4 = new TreeNode( 15 );
	TreeNode* n5 = new TreeNode( 7 );
	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;

	Solution s;
	cout << s.minDepth( n1 ) << endl;
	return 0;
}
