#include <iostream>
#include <set>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace hongfu01
{
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        set<ListNode *> si;
        ListNode *ptrA = headA;
        while(ptrA!=NULL) {
            si.insert(ptrA);
            ptrA = ptrA->next;
        }

        ListNode *ptrB = headB;
        while(ptrB!=NULL) {
            if(si.count(ptrB) > 0)
                return ptrB;
            ptrB = ptrB->next;
        }
        return NULL;
    }
};
} // namespace hongfu01

int main(int argc, char *argv[])
{

    return 0;
}