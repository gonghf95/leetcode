#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ) : val( x ), next( NULL ) { }
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) { }
};

class Solution
{
public:
	TreeNode* sortedListToBST( ListNode* head )
	{
		if( head == NULL )
			return NULL;
		if( head->next == NULL )
			return new TreeNode( head->val );

		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* prev = head;
		while( fast != NULL && fast->next != NULL )
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		while( prev->next->val != slow->val )
			prev = prev->next;

		fast = slow->next;
		prev->next = NULL;
		slow->next = NULL;

		TreeNode* root = new TreeNode( slow->val );
		root->left = sortedListToBST( head );
		root->right = sortedListToBST( fast );
		return root;
	}
};

void PrintTree( TreeNode* root )
{
	if( root != NULL )
	{
		cout << root->val << "\t";
		PrintTree( root->left );
		PrintTree( root->right );
	}
}

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( -10 );
	ListNode* n2 = new ListNode( -3 );
	ListNode* n3 = new ListNode( 0 );
	ListNode* n4 = new ListNode( 5 );
	ListNode* n5 = new ListNode( 9 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution s;
	TreeNode* root = s.sortedListToBST( n1 );

	PrintTree( root );
	cout << endl;
	return 0;
}
