#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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