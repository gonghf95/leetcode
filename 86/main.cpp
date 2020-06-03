#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int x ) : val( x ), next( NULL ) { }
};

class Solution
{
public:
    ListNode* partition( ListNode* head, int x )
    {
        ListNode* before_head = new ListNode( -1 );
        ListNode* before = before_head;
        ListNode* after_head = new ListNode( -1 );
        ListNode* after = after_head;
        while( head != NULL )
        {
            if( head->val < x )
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = after_head->next;
        delete after_head;
        head = before_head->next;
        delete before_head;
        return head;
    }
};

int main( int argc, char* argv[] )
{
    ListNode* n1 = new ListNode( 1 );
    ListNode* n2 = new ListNode( 4 );
    ListNode* n3 = new ListNode( 3 );
    ListNode* n4 = new ListNode( 2 );
    ListNode* n5 = new ListNode( 5 );
    ListNode* n6 = new ListNode( 2 );
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Solution s;
    ListNode* ret = s.partition( n1, 3 );
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