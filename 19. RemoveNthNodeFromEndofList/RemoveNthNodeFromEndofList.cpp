#include <iostream>
#include <vector>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return nullptr;
		ListNode* dummyHead = new ListNode(0, head);
		ListNode* p = dummyHead;
		ListNode* q = dummyHead;
		// finally, we have q -> nullptr, p -> the last n+1
		while (n > 0 && q)
		{
			q = q->next;
			n--;
		}
		// to keep p the last n+1 node
		q = q->next;
		while (q)
		{
			p = p->next;
			q = q->next;
		}
		// p -> the last n+1
		// remove the last n node behind p
		ListNode* temp = p->next;
		p->next = temp->next;
		delete temp;
		return dummyHead->next;
    }
};

ListNode* CreateList(std::vector<int> list)
{
	ListNode* head = NULL;
	if (list.size() < 1)
		return head;
	head = new ListNode(list[0]);
	ListNode* pHead = head;
	for (int i = 1; i < list.size(); i++)
	{
		ListNode* node = new ListNode(list[i]);
		pHead->next = node;
		pHead = node;
	}
	return head;
}

void PrintList(ListNode* head)
{
	ListNode* pHead = head;
	if (!pHead)
		return;
	std::cout << pHead->val;
	pHead = pHead->next;
	while (pHead)
	{
		std::cout << " -> " << pHead->val;
		pHead = pHead->next;
	}
	std::cout << std::endl;
}

int main()
{
	Solution solution;
	// test case 1: empty linked list
	ListNode* head_a = CreateList({});
	head_a = solution.removeNthFromEnd(head_a, 1);
	PrintList(head_a);
	// test case 2: remove the only element
	ListNode* head_b = CreateList({1});
	head_b = solution.removeNthFromEnd(head_b, 1);
	PrintList(head_b);
	// test case 3: success remove
	ListNode* head_c = CreateList({1, 2, 3, 4, 5 });
	head_c = solution.removeNthFromEnd(head_c, 2);
	PrintList(head_c);
}