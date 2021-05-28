#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

// Non-Recursion Solution: level-order traversal
#include <queue>
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		std::queue<TreeNode*> queue;
		queue.push(root);
		int counter = 0;
		while (!queue.empty())
		{
			int size = queue.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = queue.front();
				queue.pop();
				counter++;
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}
		}
		return counter;
	}
};

// Non-Recursion Solution: post-order traversal
#include <stack>
class Solution {
public:
	int countNodes(TreeNode* root)
	{
		if (!root)
			return 0;
		int counter = 0;
		std::stack<TreeNode*> stack;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* node = stack.top();
			stack.pop();
			if (node)
			{
				// pop order: left right middle
				// push order: middle, right, left
				stack.push(node);
				stack.push(NULL); // mark
				if (node->left)
					stack.push(node->left);
				if (node->right)
					stack.push(node->right);
			}
			else
			{
				// pop the real node
				node = stack.top();
				stack.pop();
				counter++;
			}
		}
		return counter;
	}
};