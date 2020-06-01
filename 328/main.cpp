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
    ListNode* oddEvenList( ListNode* head )
    {
        if( head == NULL || head->next == NULL )
            return head;
        
        ListNode* ohead = head;
        ListNode* ehead = head->next;
        ListNode* odd = head;
        ListNode* event = head->next;
        ListNode* otail = head;
        while( odd != NULL && event != NULL )
        {
            otail = odd;
            odd->next = event->next;
            odd = odd->next;
            if( odd == NULL )
                break;
            event->next = odd->next;
            event = event->next;
        }
        if( odd == NULL )
            otail->next = ehead;
        else
            odd->next = ehead;
        return ohead;
    }
};

int main( int argc, char* argv[] )
{
    // ListNode* n1 = new ListNode( 1 );
    // ListNode* n2 = new ListNode( 2 );
    // ListNode* n3 = new ListNode( 3 );
    // ListNode* n4 = new ListNode( 4 );
    // ListNode* n5 = new ListNode( 5 );
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;

    ListNode* n1 = new ListNode( 2 );
    ListNode* n2 = new ListNode( 1 );
    ListNode* n3 = new ListNode( 3 );
    ListNode* n4 = new ListNode( 5 );
    ListNode* n5 = new ListNode( 6 );
    ListNode* n6 = new ListNode( 4 );
    ListNode* n7 = new ListNode( 7 );
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    Solution s;
    ListNode* ret = s.oddEvenList( n1 );
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