#include <iostream>

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
		// if the left subtree is not a balanced binary tree, return -1.
		if (leftDepth == -1) return -1;
		int rightDepth = getDepth(node->right);
		// if the right subtree is not a balanced binary tree, return -1.
		if (rightDepth == -1) return -1;
		// if it is not an balanced binary tree, return -1.
		int ret = std::abs(leftDepth - rightDepth) > 1 ? -1 : 1 + std::max(leftDepth, rightDepth);
		return ret;
	}
	bool isBalanced(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}
};