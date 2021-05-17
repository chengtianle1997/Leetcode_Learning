#include <iostream>
#include <queue>

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
};

// Title 117 is different from 116 that we do not have a perfect binary tree guarantee this time,
// so the recursive approach is invalid. However, we can still use the level order traversal method.

class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
			return nullptr;
		std::queue<Node*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			int size = queue.size();
			Node* pre = nullptr;
			Node* node = nullptr;
			if (node->left)
				queue.push(node->left);
			if (node->right)
				queue.push(node->right);
			for (int i = 0; i < size; i++)
			{
				node = queue.front();
				queue.pop();
				if (i == 0)
				{
					pre = node;
				}
				else
				{
					pre->next = node;
					pre = node;
				}
			}
		}
		return root;
	}
};