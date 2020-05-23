#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ) {}
};

class Solution {
public:
	int getDecimalValue( ListNode* head )
	{
		if( head == NULL )
			return 0;
		if( head->next == NULL )
			return head->val;

		int answer = 0;
		ListNode* ptr = head;
		while( ptr != NULL )
		{
			answer = ( answer | ptr->val ) << 1;
			ptr = ptr->next;
		}
		return answer>>1;
	}
};

int main( int argc, char *argv[] )
{
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 0 );
	ListNode* n3 = new ListNode( 1 );
	//n1->next = n2;
	//n2->next = n3;

	Solution s;
	cout << s.getDecimalValue( n1 );

	ListNode* tmp = NULL;
	while( n1 != NULL )
	{
		tmp = n1;
		n1 = n1->next;
		delete tmp;
	}
	return 0;
}
