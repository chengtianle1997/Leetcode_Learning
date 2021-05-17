#include <iostream>
#include <queue>

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Level order traversal 
class Solution_LevelOrder {
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
			for (int i = 0; i < size; i++)
			{
				node = queue.front();
				queue.pop();
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
				if (i == 0)
				{
					pre = node;
				}
				else if (i == size - 1)
				{
					pre->next = node;
					node->next = nullptr;
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

// Recursive approach: only for perfect binary tree.
class Solution {
public:
	Node* connect(Node* root)
	{
		if (root == nullptr || root->left == nullptr)
		{
			return root;
		}
		// connect the left child with right child.
		root->left->next = root->right;
		// connect the right child with the next left child
		if (root->next)
		{
			root->right->next = root->next->left;
		}
		// recursion
		connect(root->left);
		connect(root->right);
		return root;
	}
};