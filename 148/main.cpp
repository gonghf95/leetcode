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
	ListNode* Merge( ListNode* n1, ListNode* n2 )
	{
		ListNode* dummy = new ListNode( -1 );
		ListNode* ptr = dummy;
		ListNode* tmp = NULL;
		ListNode* ptr1 = n1;
		ListNode* ptr2 = n2;
		while( ptr1 != NULL && ptr2 != NULL )
		{
			if( ptr1->val < ptr2->val )
			{
				ptr->next = new ListNode( ptr1->val );
				tmp = ptr1;
				ptr1 = ptr1->next;
				delete tmp;
			}
			else
			{
				ptr->next = new ListNode( ptr2->val );
				tmp = ptr2;
				ptr2 = ptr2->next;
				delete tmp;
			}
			ptr = ptr->next;
		}

		while( ptr1 != NULL )
		{
			ptr->next = new ListNode( ptr1->val );
			ptr = ptr->next;
			tmp = ptr1;
			ptr1 = ptr1->next;
			delete tmp;
		}

		while( ptr2 != NULL )
		{
			ptr->next = new ListNode( ptr2->val );
			ptr = ptr->next;
			tmp = ptr2;
			ptr2 = ptr2->next;
			delete tmp;
		}

		ptr1 = dummy->next;
		delete dummy;
		return ptr1;
	}

	ListNode* GetMiddleNode( ListNode* head )
	{
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* prev = head;
		while( fast != NULL && fast->next != NULL )
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		return prev;
	}

	ListNode* MergeSort( ListNode* head )
	{
		if( head == NULL || head->next == NULL )
			return head;

		ListNode* prev = GetMiddleNode( head );
		ListNode* middle = prev->next;
		prev->next = NULL;

		ListNode* left = sortList( head );
		ListNode* right = sortList( middle );

		return Merge( left, right );
	}

	ListNode* sortList( ListNode* head )
	{
		return MergeSort( head );
	}
};

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 4 );
	ListNode* n2 = new ListNode( 2 );
	ListNode* n3 = new ListNode( 1 );
	ListNode* n4 = new ListNode( 3 );
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	Solution s;
	ListNode* ret = s.sortList( n1 );
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
