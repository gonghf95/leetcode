#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ) { }
};

namespace hongfu01 {
class Solution {
public:
	bool hasCycle( ListNode* head )
	{
		ListNode* fast = head;
		ListNode* slow = head;
		while( 1 )
		{
			if( fast == NULL || fast->next == NULL )
				return false;
			if( slow == NULL )
				return false;

			fast = fast->next->next;
			slow = slow->next;
			
			if( fast == slow )
				return true;
		}
		return false;
	}
}; /* class Solution */
} /* namespace hongfu01 */

namespace hongfu02 {
class Solution {
public:
	bool hasCycle( ListNode* head )
	{
		if( head == NULL || head->next == NULL )
			return false;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while( fast != slow )
		{
			if( fast == NULL || fast->next == NULL )
				return false;
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
}; /* class Solution */
} /* namespace hongfu02 */

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 3 );
	ListNode* n2 = new ListNode( 2 );
	ListNode* n3 = new ListNode( 0 );
	ListNode* n4 = new ListNode( -4 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	hongfu02::Solution s;
	clock_t beginTime = clock();
	cout << s.hasCycle( n1 ) << endl;
	cout << "time: " << clock() - beginTime << "ms\n";
	return 0;
}
