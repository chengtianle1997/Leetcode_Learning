#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void getPath(TreeNode* node, int targetSum, std::vector<int> path, std::vector<std::vector<int>>& result) {
		int newTarget = targetSum - node->val;
		path.push_back(node->val);
		if (!node->left && !node->right && newTarget == 0)
		{
			result.push_back(path);
			return;
		}
		if (node->left)
		{
			getPath(node->left, newTarget, path, result);
		}
		if (node->right)
		{
			getPath(node->right, newTarget, path, result);
		}
	}
	std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
		std::vector<std::vector<int>> result;
		if (!root)
			return result;
		std::vector<int> path;
		getPath(root, targetSum, path, result);
		return result;
	}
};

// Non-Recursion Solution
#include <stack>
#include <tuple>
class Solution {
public:
	std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
		std::vector<std::vector<int>> result;
		if (!root)
			return result;
		std::stack<std::tuple<TreeNode*, int, std::vector<int>>> stack;
		std::vector<int> path = { root->val };
		stack.push({ root, root->val, path });
		while (!stack.empty())
		{
			auto tuple = stack.top();
			stack.pop();
			TreeNode* node = std::get<0>(tuple);
			int pathSum = std::get<1>(tuple);
			std::vector<int> nodePath = std::get<2>(tuple);
			if (!node->left && !node->right && pathSum == targetSum)
			{
				result.push_back(nodePath);
				continue;
			}
			if (node->left)
			{
				nodePath.push_back(node->left->val);
				stack.push({ node->left, pathSum + node->left->val, nodePath });
				nodePath.pop_back();
			}
			if (node->right)
			{
				nodePath.push_back(node->right->val);
				stack.push({ node->right, pathSum + node->right->val, nodePath });
				nodePath.pop_back();
			}
		}
		return result;
	}
};