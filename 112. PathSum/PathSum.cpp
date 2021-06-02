#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
			return false;
		int newTarget = targetSum - root->val;
		// find a leaf node
		if (!root->left && !root->right && newTarget == 0)
			return true;
		bool existLeft = hasPathSum(root->left, newTarget);
		bool existRight = hasPathSum(root->right, newTarget);
		return existLeft || existRight;
	}
};

// Non-Recursion Solution
#include <stack>
class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
			return false;
		// Use std::pair to restore the node and the pathSum
		std::stack<std::pair<TreeNode*, int>> stack;
		stack.push({ root, root->val });
		while (!stack.empty())
		{
			auto pair = stack.top();
			stack.pop();
			TreeNode* node = pair.first;
			int pathSum = pair.second;
			if (!node->left && !node->right && pathSum == targetSum)
				return true;
			if (node->left)
				stack.push({ node->left, pathSum + node->left->val });
			if (node->right)
				stack.push({ node->right, pathSum + node->right->val });
		}
		return false;
	}
};