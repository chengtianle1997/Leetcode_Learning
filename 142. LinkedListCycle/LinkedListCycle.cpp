#include <iostream>
#include <vector>

// Definition for single-linked list
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		// fast pointer and slow pointer start from head
		ListNode* fast = head;
		ListNode* slow = head;
		// start searching
		while (fast != nullptr && fast->next != nullptr)
		{
			// fast goes for 2 step one time, and slow goes for 1 step
			fast = fast->next->next;
			slow = slow->next;
			// fast pointer is actually chase the slow pointer 1 step for one loop from the back.
			if (fast == slow)
			{
				// fast catch up with slow pointer
				// we do find a cycle
				// Next, we need to find the entrance node

				// start ---(x)--- entrance ---(y)------
				//                   |              meet point
				//                   --------(z)--------	

				// fast pointer distance = x + y + (y + z) * n
				// slow pointer distance = x + y
				// fast pointer distance = 2 * slow pointer distance
				// x + y + (y + z) * n = 2x + 2y
				// n * (y + z) = x + y
				// x = (n - 1) * y + n * z
				// which means when we have a pointer from start and another pointer from the meet point,
				// they goes for the same 1 step for one time, they will definitely meet at entrance node.
				ListNode* start_node = head;
				ListNode* meet_node = fast;
				while (start_node != meet_node)
				{
					start_node = start_node->next;
					meet_node = meet_node->next;
				}
				return start_node;
			}
		}
		return nullptr;
	}
};

ListNode* CreateCycle(std::vector<int> nodes, int pos)
{
	if (nodes.size() < 1)
		return nullptr;
	ListNode* head = new ListNode(nodes[0]);
	ListNode* p_head = head;
	ListNode* entrance = nullptr;
	if (pos == 0)
		entrance = head;
	for (int i = 1; i < nodes.size(); i++)
	{
		ListNode* node = new ListNode(nodes[i]);
		p_head->next = node;
		p_head = node;
		if (i == pos)
		{
			entrance = p_head;
		}
	}
	// link the last node to the entrance node
	p_head->next = entrance;
	return head;
}

void PrintResult(int pos)
{
	std::cout << "tail connects to node index " << pos << std::endl;
}

void PrintResult(ListNode* head, int pos)
{
	if (!head)
		return;
	ListNode* p_head = head;
	int index_counter = 0;
	int end_val = NULL;
	bool exit_signal = false;
	while (!exit_signal && p_head)
	{
		if (index_counter == pos)
		{
			end_val = p_head->val;
		}
		else if (p_head->next && p_head->next->val == end_val)
		{
			exit_signal = true;
		}
		std::cout << p_head->val << " -> ";
		index_counter++;
		p_head = p_head->next;
	}
	if (end_val)
		std::cout << end_val << "(entrance node)" << std::endl;
	else
		std::cout << "There is no cycle in the linked list." << std::endl;
}

void PrintResult(ListNode* head, ListNode* entrance)
{
	if (!head)
	{
		return;
	}
	if (!entrance)
	{
		std::cout << "There is no cycle in the linked list." << std::endl;
		return;
	}
	ListNode* p_head = head;
	int end_val = entrance->val;
	bool entrance_found = false;
	while (p_head)
	{
		if (!entrance_found && end_val == p_head->val)
		{
			entrance_found = true;
		}
		else if (entrance_found && end_val == p_head->val)
		{
			break;
		}
		std::cout << p_head->val << " -> ";
		p_head = p_head->next;
	}
	if(entrance_found)
		std::cout << end_val << "(entrance node)" << std::endl;
	else
		std::cout << "There is no cycle in the linked list." << std::endl;
}

int main()
{
	// test input and output
	/*ListNode* head_test = CreateCycle({ 3, 2, 0, -4 }, 1);
	PrintResult(head_test, 1);
	PrintResult(head_test, &ListNode(2));*/
	
	Solution solution;
	// test case 1
	ListNode* head_a = CreateCycle({ 3, 2, 0, -4 }, 1);
	ListNode* entr_a = solution.detectCycle(head_a);
	PrintResult(head_a, entr_a);

	// test case 2
	ListNode* head_b = CreateCycle({ 1, 2 }, 0);
	ListNode* entr_b = solution.detectCycle(head_b);
	PrintResult(head_b, entr_b);

	// test case 3
	ListNode* head_c = CreateCycle({ 1 }, -1);
	ListNode* entr_c = solution.detectCycle(head_c);
	PrintResult(head_c, entr_c);
	
}