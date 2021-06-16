#include <vector>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursion Solution: inorder traversal sequence analysing
class Solution {
public:
	std::vector<int> vec;
	void traversal(TreeNode* node) {
		if (!node)
			return;
		traversal(node->left);
		vec.emplace_back(node->val);
		traversal(node->right);
	}
    int getMinimumDifference(TreeNode* root) {
		if (!root)
			return 0;
		int result = INT_MAX;
		// Get inorder traversal sequence in vector.
		traversal(root);
		for (int i = 1; i < vec.size(); i++)
		{
			result = std::min(vec[i] - vec[i - 1], result);
		}
		return result;
    }
};

// Recursion Solution: inorder traversal recursion
class Solution {
public:
	int result = INT_MAX;
	TreeNode* pre = nullptr;
	void traversal(TreeNode* node) {
		if (!node)
			return;
		traversal(node->left);
		if (pre)
			result = std::min(result, node->val - pre->val);
		pre = node;
		traversal(node->right);
	}
	int getMinimumDifference(TreeNode* root) {
		if (!root)
			return 0;
		traversal(root);
		return result;
	}
};

// Non-Recursion version
#include <stack>
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		if (!root)
			return 0;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		int result = INT_MAX;
		std::stack<TreeNode*> stack;
		while (!stack.empty() || cur != nullptr)
		{
			if (cur)
			{
				stack.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = stack.top();
				stack.pop();
				if (pre)
				{
					result = std::min(result, cur->val - pre->val);
				}
				pre = cur;
				cur = cur->right;
			}
		}
		return result;
	}
};