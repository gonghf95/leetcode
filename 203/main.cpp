#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ) {}
};

class Solution {
public:
	ListNode* removeElements( ListNode* head, int val )
	{
		ListNode* dummy = new ListNode( -1 );
		dummy->next = head;

		ListNode* ptr = dummy;
		while( ptr != NULL && ptr->next != NULL )
		{
			if( ptr->next->val == val )
				ptr->next = ptr->next->next;
			else
				ptr = ptr->next;
		}
		
		ptr = dummy->next;
		delete dummy;
		return ptr;
	}
};

int main( int argc, char* argv[] )
{
	// test case 1
	/*ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 2 );
	ListNode* n3 = new ListNode( 6 );
	ListNode* n4 = new ListNode( 3 );
	ListNode* n5 = new ListNode( 4 );
	ListNode* n6 = new ListNode( 5 );
	ListNode* n7 = new ListNode( 6 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;*/

	// test case 2
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 1 );
	n1->next = n2;

	Solution s;
	ListNode* ret = s.removeElements( n1, 2 );

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
