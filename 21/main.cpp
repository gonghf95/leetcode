#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

namespace hongfu01 {
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;

        ListNode *head = l1;        
        ListNode *tail = l1;
        while (tail->next!=NULL)
            tail = tail->next;
        tail->next = l2;

        ListNode *ptr1 = l1;
        ListNode *ptr2 = l1;
        while (ptr1!=NULL)
        {
            ptr2 = ptr1;
            while(ptr2!=NULL)
            {
                if(ptr1->val > ptr2->val)
                {
                    int tmp = ptr2->val;
                    ptr2->val = ptr1->val;
                    ptr1->val = tmp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        
        return head;
    }
}; /* class Solution */
} /* namespace hongfu01 */

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    // l1->next->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(0);
    l2->next = new ListNode(0);
    l2->next->next = new ListNode(0);

    hongfu01::Solution s;
    clock_t beginTime = clock();
    ListNode *ret = s.mergeTwoLists( l1, l2);
    cout << "time: " << clock() - beginTime << endl;
    while (ret!=NULL)
    {
        cout << " " << ret->val;
        ret = ret->next;
    }
    cout << endl;
    return 0;
}