#include <iostream>
#include <vector>

// Definition for single-linked list
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		// two pointers: p and q
		ListNode* p = head;
		ListNode* q = head->next;
		while (q)
		{
			ListNode* temp = q->next;
			q->next = p;
			p = q;
			q = temp;
		}
		head->next = nullptr;
		return p;
	}
};

ListNode* CreateList(std::vector<int> list)
{
	ListNode* head = new ListNode;
	if (list.size() <= 0)
		return head;
	head = new ListNode(list[0]);
	ListNode* p_head = head;
	for (int i = 1; i < list.size(); i++)
	{
		ListNode* node = new ListNode(list[i]);
		p_head->next = node;
		p_head = node;
	}
	return head;
}

void DeleteList(ListNode* head)
{
	ListNode* p_head = head;
	while (p_head)
	{
		ListNode* node = p_head;
		p_head = node->next;
		delete node;
	}

}

void PrintList(ListNode* head)
{
	ListNode* node = head;
	while (node != nullptr)
	{
		std::cout << node->val;
		node = node->next;
		if (node)
			std::cout << " -> ";
	}
	std::cout << std::endl;
}

int main()
{
	/*ListNode* head_test = CreateList({ 1, 2, 3, 4, 5 });
	PrintList(head_test);
	DeleteList(head_test);*/

	Solution solution;

	// test case 1: empty list
	ListNode* head_a = new ListNode;
	ListNode* head_res_a = solution.reverseList(head_a);
	// test case 2: real list
	ListNode* head_b = CreateList({ 1, 2, 3, 4, 5 });
	PrintList(head_b);
	ListNode* head_res_b = solution.reverseList(head_b);
	PrintList(head_res_b);

	return 0;
}