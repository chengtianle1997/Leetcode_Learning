#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int getSum(TreeNode* node) {
		int SumCur = 0;
		if (!node)
			return 0;
		// if it has a left leaf child
		if (node->left && node->left->left == nullptr && node->left->right == nullptr)
			SumCur = node->left->val;
		// Recursion
		int SumLeft = getSum(node->left);
		int SumRight = getSum(node->right);
		return SumCur + SumLeft + SumRight;
	}
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;
		return getSum(root);
	}
};

// Non-Recursion Solution
#include <stack>
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;
		std::stack<TreeNode*> stack;
		stack.push(root);
		int sum = 0;
		while (!stack.empty())
		{
			TreeNode* node = stack.top();
			stack.pop();
			// if it has a left leaf child
			if (node->left && !node->left->left && !node->left->right)
			{
				sum += node->left->val;
			}
			if (node->right)
				stack.push(node->right);
			if (node->left)
				stack.push(node->left);
		}
		return sum;
	}
};