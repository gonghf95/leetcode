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
    ListNode* deleteDuplicates( ListNode* head )
    {
        if( head == NULL || head->next == NULL )
            return head;

        ListNode* dummy = new ListNode( -1 );
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = head->next;
        bool dup = false;
        while( fast != NULL )
        {
            if( slow->next->val != fast->val )
            {
                if( dup )
                {
                    slow->next = fast;
                    dup = false;
                    fast = fast->next;
                }
                else
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            else
            {
                fast = fast->next;
                dup = true;
            }
        }
        if( dup )
            slow->next = fast;
        slow = dummy->next;
        delete dummy;
        return slow;
    }
};

int main( int argc, char* argv[] )
{
    ListNode* n1 = new ListNode( 1 );
    ListNode* n2 = new ListNode( 2 );
    ListNode* n3 = new ListNode( 3 );
    ListNode* n4 = new ListNode( 3 );
    ListNode* n5 = new ListNode( 4 );
    ListNode* n6 = new ListNode( 4 );
    ListNode* n7 = new ListNode( 5 );
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    Solution s;
    ListNode* ret = s.deleteDuplicates( n1 );
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