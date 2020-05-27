#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};

class Solution {
public:
	vector< vector< int > > levelOrder( TreeNode* root )
	{
		if( root == NULL )
			return {};

		vector< vector< int > > ans;
		queue< TreeNode* > que;
		TreeNode* tmp = NULL;
		int nums = 0;

		que.push( root );
		while( !que.empty() )
		{
			vector<int> level;
			level.clear();
			nums = que.size();
			while( nums-- )
			{
				tmp = que.front();
				que.pop();
				level.push_back( tmp->val );
				if( tmp->left != NULL )
					que.push( tmp->left );
				if( tmp->right != NULL )
					que.push( tmp->right );
			}
			if( level.size() > 0 )
				ans.push_back( level );
		}
		return ans;
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
	vector< vector< int > > ret = s.levelOrder( n1 );
	
	unsigned int i = 0;
	unsigned int j = 0;
	cout << "[\n";
	for( i = 0; i < ret.size(); i++ )
	{
		cout << " [";
		vector< int > tmp = ret[i];
		for( j = 0; j < tmp.size(); j++ )
		{
			cout << tmp[j];
			if( j != tmp.size() - 1 )
				cout << ',';
		}
		if( i != ret.size() - 1 )
			cout << "],\n";
		else
			cout << "]\n";
	}
	cout << "]\n";
	return 0;
}
