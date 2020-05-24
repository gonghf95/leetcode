#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode( int x ): val( x ), next( NULL ) {}
};

class Solution {
public:
	bool isPalindrome( ListNode* head )
	{
		ListNode* fast = head;
		ListNode* slow = head;
		while( fast != NULL && fast->next != NULL )
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* tmp = NULL;
		ListNode* prev = NULL;
		while( slow != NULL )
		{
			tmp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = tmp;
		}

		slow = prev;
		fast = head;
		while( fast != NULL && slow != NULL )
		{
			if( fast->val != slow->val )
				return false;
			fast = fast->next;
			slow = slow->next;
		}
		return true;
	}
};

int main( int argc, char* argv[] )
{
	ListNode* n1 = new ListNode( 1 );
	ListNode* n2 = new ListNode( 2 );
	n1->next = n2;

	Solution s;
	cout << s.isPalindrome( n1 ) << endl;

	return 0;
}
