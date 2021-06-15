
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr || root->val == val)
			return root;
		if (val > root->val)
			return searchBST(root->right, val);
		else
			return searchBST(root->left, val);
	}
};

// Non-Recursion Solution
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr)
			return nullptr;
		TreeNode* node = root;
		while (node != nullptr)
		{
			if (val == node->val)
				return node;
			else if (val > node->val)
				node = node->right;
			else
				node = node->left;
		}
		return nullptr;
	}
};