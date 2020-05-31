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
	ListNode* insertionSortList( ListNode* head )
	{
		if( head == NULL || head->next == NULL )
			return head;

		ListNode* dummy = new ListNode( 0 );
		dummy->next = head;

		ListNode* cur = head;
		ListNode* move = NULL;
		ListNode* save = NULL;
		while( cur != NULL )
		{
			move = dummy;
			while( move->next != NULL && move->next != cur && move->next->val < cur->val )
				move = move->next;
			if( move->next == NULL ||  move->next != cur )
			{
				save = cur->next;
				cur->next = move->next;
				move->next = cur;
				cur = save;
			}
			else
			{
				save = cur;
				cur = cur->next;
				save->next = NULL;
			}
		}
		cur = dummy->next;
		delete dummy;
		return cur;
	}
};


int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( -1 );
	ListNode* n2 = new ListNode( 5 );
	ListNode* n3 = new ListNode( 3 );
	ListNode* n4 = new ListNode( 4 );
	ListNode* n5 = new ListNode( 0 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution s;
	ListNode* ret = s.insertionSortList( n1 );
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
