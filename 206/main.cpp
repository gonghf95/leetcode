#include <iostream>

#define local

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

namespace hongfu01 {
class Solution
{
public:
    ListNode* reverseList(ListNode *head) 
    {
        // if(head==NULL)
        //     return NULL;
        // if (head->next == NULL)
        //     return head;
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *prev = NULL;
        ListNode *tmp = NULL;
        while(head!=NULL)
        {
            // if(prev==NULL)
            // {
            //     prev = head;
            //     head = head->next;
            //     prev->next = NULL;
            //     continue;
            // }
            tmp = head->next; // save 
            head->next = prev; // reverse pointer
            prev = head; // let prev point to current node
            head = tmp; // next node
        }
        return prev;
    }
}; // class Solution
} // namespace hongfu01

int main(int argc, char *argv[])
{
#ifdef local
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif
    int data;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *l1 = NULL;
    while(cin>>data)
    {
        l1 = new ListNode(data);
        if(head==NULL)
        {
            head = l1;
            tail = head;
        }
        else
        {
            tail->next = l1;
            tail = l1;
        }
    }
    l1 = head;

    hongfu01::Solution s;
    clock_t beginTime = clock();
    ListNode *ret = s.reverseList(l1);
    cout << "time: " << (clock() - beginTime) << endl;
    while(ret!=NULL)
    {
        cout << " " << ret->val;
        ret = ret->next;
    }
    cout << endl;

    while(l1!=NULL)
    {
        ListNode *tmp = l1;
        l1 = l1->next;
        delete tmp;
    }
    return 0;
}