#include <iostream>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Recursion Approach
class Solution {
public:
	bool compare(TreeNode* left, TreeNode* right)
	{
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr || right == nullptr)
			return false;
		else if (left->val != right->val)
			return false;
		// here, left and right are not nullptr and have the same value.
		bool outside = compare(left->left, right->right);
		bool inside = compare(left->right, right->left);
		return outside && inside;
	}
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return compare(root->left, root->right);
	}
};

// Non-Recursion Approach
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		std::queue<TreeNode*> queue;
		queue.push(root->left);
		queue.push(root->right);
		while (!queue.empty())
		{
			TreeNode* left = queue.front();
			queue.pop();
			TreeNode* right = queue.front();
			queue.pop();

			if (left == nullptr && right == nullptr)
				continue;

			if (left == nullptr || right == nullptr || left->val != right->val)
				return false;

			queue.push(left->left);
			queue.push(right->right);
			queue.push(left->right);
			queue.push(right->left);
		}
		return true;
	}
};