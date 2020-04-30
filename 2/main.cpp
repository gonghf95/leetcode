#include <iostream>
#include <map>

#define local

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

namespace hongfu01 {
class Solution
{
public:
	ListNode* AddTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *result=NULL, *tail, *tmp;
		long long num1=0, num2=0, sum=0;
		unsigned short base1=1, base2=1;
		unsigned short digit;
		
		ListNode *p1=l1, *p2=l2;
		while(p1!=NULL)
		{
			num1 += base1*(p1->val);
			base1 *= 10;
			p1 = p1->next;
		}

		while(p2!=NULL)
		{
			num2 += base2*(p2->val);
			base2 *= 10;
			p2 = p2->next;
		}
		sum = num1 + num2;
		cout << num1 << '+' << num2 << '=' << sum << endl;
		while(1)
		{
			digit = sum%10;
			tmp = new ListNode(digit);
			if(result==NULL)
			{
				result = tmp;
				tail = tmp;
			}
			else
			{
				tail->next = tmp;
				tail = tail->next;
			}
			sum /= 10;
			if(sum==0)
				break;
		}
		return result;
	}
};

ListNode* read()
{
	int tmp;
	ListNode *head = NULL, *tail, *p;
	while((cin>>tmp) && tmp!=-1)
	{
		p = new ListNode(tmp);
		if(head==NULL)
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = tail->next;
		}
	}
	return head;
}

void clear(ListNode *head)
{
	ListNode *tmp;
	while(head!=NULL)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void pr_list(ListNode *head)
{
	ListNode *p = head;
	while(p!=NULL)
	{
		cout << p->val << ',';
		p = p->next;
	}
	cout << endl;
}

void test()
{
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;
	Solution solution;
	while(1)
	{
		l1 = read();
		l2 = read();
		if(l1==NULL || l2==NULL)
			break;
		ListNode *result = solution.AddTwoNumbers(l1, l2);
		//pr_list(result);
		clear(l1);
		clear(l2);
		clear(result);
	}

	if(l1!=NULL)clear(l1);
	if(l2!=NULL)clear(l2);
	cout << "done.\n";
}
}

namespace hongfu02 {
class Solution
{
public:
	ListNode* AddTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *head=NULL, *tail, *tmp;
		unsigned short int sum=0, carry=0;
		while(l1!=NULL && l2!=NULL)
		{
			sum = l1->val + l2->val + carry;
			carry = 0;
			if(sum>=10)
			{
				carry = 1;
				sum %= 10;
			}

			tmp = new ListNode(sum);
			if(head == NULL)
			{
				tail = head = tmp;
			}
			else
			{
				tail->next = tmp;
				tail = tail->next;
			}
			
			l1 = l1->next;
			l2 = l2->next;
		}

		while(l1!=NULL)
		{
			sum = l1->val + carry;
			carry = 0;
			if(sum >= 10)
			{
				carry = 1;
				sum %= 10;
			}
			tmp = new ListNode(sum);
			tail->next = tmp;
			tail = tail->next;
			l1 = l1->next;
		}

		while(l2!=NULL)
		{
			sum = l2->val + carry;
			carry = 0;
			if(sum >= 10)
			{
				carry = 1;
				sum %= 10;
			}

			tmp = new ListNode(sum);
			tail->next = tmp;
			tail = tail->next;
			l2 = l2->next;
		}

		if(carry != 0)
		{
			tmp = new ListNode(1);
			tail->next = tmp;
		}

		return head;
	}
};

ListNode* read()
{
	int tmp;
	ListNode *head = NULL, *tail, *p;
	while((cin>>tmp) && tmp!=-1)
	{
		p = new ListNode(tmp);
		if(head==NULL)
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = tail->next;
		}
	}
	return head;
}

void clear(ListNode *head)
{
	ListNode *tmp;
	while(head!=NULL)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void pr_list(ListNode *head)
{
	ListNode *p = head;
	while(p!=NULL)
	{
		cout << p->val << ',';
		p = p->next;
	}
	cout << endl;
}

void test()
{
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;
	Solution solution;
	while(1)
	{
		l1 = read();
		l2 = read();
		if(l1==NULL || l2==NULL)
			break;
		ListNode *result = solution.AddTwoNumbers(l1, l2);
		pr_list(result);
		clear(l1);
		clear(l2);
		clear(result);
	}

	if(l1!=NULL)clear(l1);
	if(l2!=NULL)clear(l2);
	cout << "done.\n";
}
}

int main(int argc, char *argv[])
{
#ifdef local
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif
	hongfu02::test();
	return 0;
}
