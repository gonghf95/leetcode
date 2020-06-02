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
        queue< ListNode* > gq;
        queue< ListNode* > lq;

        ListNode* ptr = head;
        ListNode* save = NULL;
        while( ptr != NULL )
        {
            save = ptr->next;
            ptr->next = NULL;
            if( ptr->val >=x )
                gq.push( ptr );
            else
                lq.push( ptr );
            ptr = save;
        }

        ListNode* dummy = new ListNode( -1 );
        ptr = dummy;
        while( !lq.empty() )
        {
            save = lq.front();
            lq.pop();
            ptr->next = save;
            ptr = ptr->next;
        }

        while( !gq.empty() )
        {
            save = gq.front();
            gq.pop();
            ptr->next = save;
            ptr = ptr->next;
        }

        ptr = dummy->next;
        delete dummy;
        return ptr;
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