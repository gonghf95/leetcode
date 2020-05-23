#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ) { }
};
namespace hongfu01 {
class Solution {
public:
	ListNode* middleNode( ListNode* head )
	{
		if( head == NULL )
			return NULL;

		if( head->next == NULL )
			return head;

		int length = 1;
		ListNode* ptr = head;
		while( ptr->next != NULL )
		{
			++length;
			ptr = ptr->next;
		}

		int middle = length / 2 + 1;
		
		ptr = head;
		length = 1;
		while( length++ < middle )
			ptr = ptr->next;
		return ptr;
	}
}; /* class Solution */
} /* namespace hongfu01 */

namespace hongfu02 {
class Solution {
public:
	ListNode* middleNode( ListNode* head )
	{
		ListNode* fast = head;
		ListNode* slow = head;

		while( fast != NULL && fast->next != NULL )
		{
			fast = fast->next->next;
			slow = slow->next;
		}
			
		return slow;
	}
}; /* class Solution */
} /* namespace hongfu02  */

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 2 );
	ListNode* n3 = new ListNode( 3 );
	ListNode* n4 = new ListNode( 4 );
	ListNode* n5 = new ListNode( 5 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	hongfu01::Solution s;
	ListNode* ret = s.middleNode( n1 );

	while( ret != NULL )
	{
		cout << ret->val;
		if( ret->next != NULL )
			cout << "->";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}
