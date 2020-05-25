#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ){}
};

class Solution
{
public:
	ListNode* rotateRight( ListNode* head, int k )
	{
		if( head == NULL || head->next == NULL )
			return head;

		int length = 1;
		ListNode* ptr = head;
		while( ptr->next != NULL )
		{
			length++;
			ptr = ptr->next;
		}
		ptr->next = head;
		
		int step = length - k % length;
		while( step > 0 )
		{
			ptr = ptr->next;
			head = head->next;
			step--;
		}
		ptr->next = NULL;
		return head;
	}
};

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 2 );
	ListNode* n3 = new ListNode( 3 );
	ListNode* n4 = new ListNode( 4 );
	ListNode* n5 = new ListNode( 5 );
	n1->next = n2;
	n2->next = n3;
	//n3->next = n4;
	//n4->next = n5;

	Solution s;
	ListNode* ret = s.rotateRight( n1, 4 );

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
