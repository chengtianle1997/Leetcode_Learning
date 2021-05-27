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