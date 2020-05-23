#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ) {}
};

namespace hongfu01 {
class Solution {
public:
	ListNode* deleteDuplicates( ListNode* head )
	{
		if( head == NULL )
			return NULL;
		if( head->next == NULL )
			return head;

		ListNode* first = head;
		ListNode* second = NULL;
		while( first != NULL )
		{
			second = first->next;
			while( second != NULL && first->val == second->val )
				second = second->next;

			if( second == NULL )
			{
				first->next = NULL;
				break;
			}
			else
			{
				first->next = second;
				first = second;
			}
		}
		return head;
	}
};
}

namespace hongfu02 {
class Solution {
public:
	ListNode* deleteDuplicates( ListNode* head )
	{
		ListNode* cur = head;
		while( cur != NULL && cur->next != NULL )
		{
			if( cur->val == cur->next->val )
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}
		return head;
	}
};
}

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 1 );
	ListNode* n3 = new ListNode( 2 );
	ListNode* n4 = new ListNode( 3 );
	ListNode* n5 = new ListNode( 3 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	hongfu01::Solution s;
	clock_t beginTime = clock();
	ListNode* ret = s.deleteDuplicates( n1 );
	cout << "time: " << clock() - beginTime << "ms\n";

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
