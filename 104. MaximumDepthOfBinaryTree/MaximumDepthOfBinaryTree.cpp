#include <iostream>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int getDepth(TreeNode* node) {
		if (node == nullptr)
			return 0;
		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);
		int depth = 1 + std::max(leftDepth, rightDepth);
		return depth;
	}
	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	}
};

// Non-Recursion solution: level-order traversal
#include <queue>
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int depth = 0;
		std::queue<TreeNode*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			int size = queue.size();
			depth++;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = queue.front();
				queue.pop();
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}
		}
		return depth;
	}
};

// Use stack to stimulate the post-order traversal
#include <stack>
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		std::stack<TreeNode*> stack;
		int depth = 0;
		int result = 0;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* node = stack.top();
			stack.pop();
			if (node)
			{
				// pop order: post-order (left, right, middle)
				// push order: middle. right, left
				stack.push(node);
				stack.push(NULL);
				depth++;
				if (node->right)
					stack.push(node->right);
				if (node->left)
					stack.push(node->left);
			}
			else
			{
				TreeNode* node = stack.top();
				stack.pop();
				depth--;
			}
			result = std::max(result, depth);
		}
		return result;
	}
};

// In this method: we do 'depth++' when we push an element as a middle node to the stack,
// So we can get the right depth number that meams the number of nodes to reach the node from the root.
// However, when we reach the node after NULL (the middle node) and pop it out, we do 'depth--' 
// to recover the depth number of the previous stack element.