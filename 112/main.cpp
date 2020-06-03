#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) { }
};

class Solution
{
public:
    bool hasPathSum( TreeNode* root, int sum )
    {
        if( root == NULL )
            return false;
        
        sum -= root->val;
        if( root->left == NULL && root->right == NULL )
            return sum == 0;
        bool left = hasPathSum( root->left, sum );
        bool right = hasPathSum( root->right, sum );
        return left || right;
    }
};

int main( int argc, char* argv[] )
{
    TreeNode* n1 = new TreeNode( 5 );
    TreeNode* n2 = new TreeNode( 4 );
    TreeNode* n3 = new TreeNode( 8 );
    TreeNode* n4 = new TreeNode( 11 );
    TreeNode* n5 = new TreeNode( 13 );
    TreeNode* n6 = new TreeNode( 4 );
    TreeNode* n7 = new TreeNode( 7 );
    TreeNode* n8 = new TreeNode( 2 );
    TreeNode* n9 = new TreeNode( 1 );
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n4->left = n7;
    n4->right = n8;
    n3->left = n5;
    n3->right = n6;
    n6->right = n9;

    Solution s;
    cout << s.hasPathSum( n1, 22 ) << endl;
    return 0;
}