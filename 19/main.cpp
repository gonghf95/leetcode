#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    ListNode* removeNthFromEnd( ListNode* head, int n )
    {

	if( head->next == NULL )
		return NULL;

	ListNode* dummy = new ListNode( 0 );
	dummy->next = head;

        ListNode* ptr = dummy;
        ListNode* target = NULL;
	while( n-- > -1 )
		ptr = ptr->next;
		target = dummy;
		
        while( ptr != NULL )
        {
		ptr = ptr->next;
		target = target->next;
        }

	target->next = target->next->next;
	
	ptr = dummy->next;
	delete dummy;
        return ptr;
    }
};

int main( int argc, char *argv[] )
{
    ListNode* head = new ListNode( -1 );
    ListNode* l1 = new ListNode( 1 );
    ListNode* l2 = new ListNode( 2 );
    ListNode* l3 = new ListNode( 3 );
    ListNode* l4 = new ListNode( 4 );
    ListNode* l5 = new ListNode( 5 );
    head->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

	ListNode* tmp = head;
    while( tmp != NULL )
    {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;

    Solution s;
    tmp = s.removeNthFromEnd( head->next, 1 );

    while( tmp != NULL )
    {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
