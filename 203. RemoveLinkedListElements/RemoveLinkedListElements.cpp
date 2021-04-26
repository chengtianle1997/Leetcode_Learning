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
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
			return nullptr;
		// Create a dummy head node for linked list to solve the real head node.
		ListNode* dummyNode = new ListNode(0, head);
		ListNode* pHead = dummyNode;
		while (pHead->next)
		{
			ListNode* temp = pHead->next;
			if (temp->val == val)
			{
				// meet target, delete temp node
				pHead->next = temp->next;
				delete temp;
				// remember do not do: pHead = pHead->next, 
				// which is equal to pHead = pHead->next->next (==nullptr possibly and throw an exception)
			}
			else 
			{
				pHead = pHead->next;
			}
		}
		return dummyNode->next;
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
	// test input and output
	// ListNode* head_test = CreateList({ 1, 2, 6, 3, 4, 5, 6 });
	// PrintList(head_test);

	Solution solution;
	// test case 1: empty list
	ListNode* head_a = CreateList({});
	head_a = solution.removeElements(head_a, 1);
	PrintList(head_a);
	// test case 2: fail remove
	ListNode* head_b = CreateList({ 1, 2, 5, 3, 5, 7, 8 });
	head_b = solution.removeElements(head_b, 9);
	PrintList(head_b);
	// test case 3: success remove (middle element)
	ListNode* head_c = CreateList({ 1, 2, 6, 3, 4, 5, 6 });
	head_c = solution.removeElements(head_c, 6);
	PrintList(head_c);
	// test case 4: success remove (head element, all element)
	ListNode* head_d = CreateList({ 7, 7, 7, 7 });
	head_d = solution.removeElements(head_d, 7);
	PrintList(head_d);
}