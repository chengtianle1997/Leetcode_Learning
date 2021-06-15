#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return nullptr;
		int node_val = 0;
		TreeNode* root1_left = nullptr;
		TreeNode* root1_right = nullptr;
		TreeNode* root2_left = nullptr;
		TreeNode* root2_right = nullptr;
		if (root1)
		{
			node_val += root1->val;
			root1_left = root1->left;
			root1_right = root1->right;
		}

		if (root2)
		{
			node_val += root2->val;
			root2_left = root2->left;
			root2_right = root2->right;
		}
		TreeNode* node = new TreeNode(node_val);
		node->left = mergeTrees(root1_left, root2_left);
		node->right = mergeTrees(root1_right, root2_right);
		return node;
	}
};

// More simple
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr)
			return root2;
		if (root2 == nullptr)
			return root1;
		TreeNode* node = new TreeNode(root1->val + root2->val);
		node->left = mergeTrees(root1->left, root2->left);
		node->right = mergeTrees(root1->right, root2->right);
		return node;
	}
};