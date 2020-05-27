#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ) : val( x ), next( NULL ) { }
};

class Solution
{
public:
	ListNode* swapPairs( ListNode* head )
	{
		if( head == NULL || head->next == NULL )
			return head;

		ListNode* dummy = new ListNode( -1 );
		dummy->next = head;

		ListNode* prev = dummy;
		ListNode* slow = head;
		ListNode* fast = NULL;
		while( slow != NULL && slow->next != NULL)
		{
			fast = slow->next;
			prev->next = fast;
			slow->next = fast->next;
			fast->next = slow;
			prev = slow;
			slow = slow->next;
		}
		prev = dummy->next;
		delete dummy;
		return prev;
	}
};

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 2 );
	ListNode* n3 = new ListNode( 3 );
	ListNode* n4 = new ListNode( 4 );
	n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;

	Solution s;
	ListNode* ret = s.swapPairs( n1 );

	while( ret != NULL )
	{
		cout << ret->val;
		ret = ret->next;
		if( ret != NULL )
			cout << "->";
	}
	cout << endl;
	return 0;
}
