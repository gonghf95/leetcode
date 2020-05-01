#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

namespace hongfu01 {
class Solution
{
public:
	Solution():head(NULL)
	{
		head = new ListNode(4);
		ListNode *l2 = new ListNode(1);
		ListNode *l3 = new ListNode(5);
		ListNode *l4 = new ListNode(9);
		head->next = l2;
		l2->next = l3;
		l3->next = l4;
	}

	virtual ~Solution()
	{
		ListNode *ptr = NULL;
		while(head!=NULL)
		{
			ptr = head;
			head = head->next;
			delete ptr;
		}
	}

	ListNode* GetHead() const
	{
		return head;
	}

	void deleteNode(ListNode *node)
	{
		if(node==NULL)
			return;
		
		ListNode *HEAD = new ListNode(0);
		HEAD->next = head;

		ListNode *ptr = HEAD;
		while(ptr->next!=NULL && ptr->next->val!=node->val)
			ptr = ptr->next;
		if(ptr->next!=NULL)
		{
			ListNode *tmp = ptr->next;
			ptr->next = tmp->next;
			delete tmp;
		}
		head = HEAD->next;
	}

private:
	ListNode *head;
};
}

namespace hongfu02 {
class Solution
{
public:
	void deleteNode(ListNode *node)
	{
		ListNode *tmp = node->next;
		node->val = tmp->val;
		node->next = tmp->next;
		delete tmp;
	}
};
}

int main(int argc, char *argv[])
{
	hongfu01::Solution s;
	ListNode *ptr = NULL;
	ptr = s.GetHead();
	while(ptr!=NULL)
	{
		cout << " " << ptr->val;
		ptr = ptr->next;
	}
	cout << endl;

	ListNode *tmp = new ListNode(5);
	s.deleteNode(tmp);
	delete tmp;
	ptr = s.GetHead();
	while(ptr!=NULL)
	{
		cout << " " << ptr->val;
		ptr = ptr->next;
	}
	cout << endl;

	return 0;
}
