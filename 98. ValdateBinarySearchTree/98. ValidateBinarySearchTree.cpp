#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// inorder traversal and check whether the sequence is increasing.
class Solution {
public:
	std::vector<int> vec;
	void traversal(TreeNode* node) {
		if (node == nullptr)
			return;
		traversal(node->left);
		vec.emplace_back(node->val);
		traversal(node->right);
	}
	bool isValidBST(TreeNode* root) {
		traversal(root);
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] <= vec[i - 1])
				return false;
		}
		return true;
	}
};

// Recursion Approach: inorder traversal
class Solution {
public:
	long long maxVal = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		bool left = isValidBST(root->left);

		if (maxVal < root->val)
			maxVal = root->val;
		else
			return false;

		bool right = isValidBST(root->right);

		return left && right;
	}
};

// Recursion Approach: inorder traversal, without maxVal recording
class Solution {
public:
	TreeNode* pre = nullptr;
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		bool left = isValidBST(root->left);

		if (pre && pre->val >= root->val)
			return false;
		// record the last node instead of the max value
		pre = root;

		bool right = isValidBST(root->right);

		return left && right;
	}
};

// Non-Recursion Solution: inorder traversal
#include <stack>
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		std::stack<TreeNode*> stack;
		while (cur != nullptr || !stack.empty())
		{
			if (cur != nullptr)
			{
				stack.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = stack.top();
				stack.pop();
				if (pre && pre->val >= cur->val)
					return false;
				pre = cur;
				cur = cur->right;
			}
		}
		return true;
	}

};