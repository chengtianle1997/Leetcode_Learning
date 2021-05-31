#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void traversal(TreeNode* node, std::string path, std::vector<std::string>& result) {
		path += std::to_string(node->val);
		// leaf node
		if (node->left == nullptr && node->right == nullptr) {
			result.push_back(path);
			return;
		}
		if (node->left)
			traversal(node->left, path + "->", result);
		if (node->right)
			traversal(node->right, path + "->", result);
	}
	std::vector<std::string> binaryTreePaths(TreeNode* root) {
		std::vector<std::string> result;
		if (!root)
			return result;
		std::string path;
		traversal(root, path, result);
		return result;
	}
};

// Non-Recursion Solution
#include <stack>
class Solution {
public:
	std::vector<std::string> binaryTreePaths(TreeNode* root) {
		std::vector<std::string> result;
		if (!root)
			return result;
		std::stack<std::string> pathStk;
		std::stack<TreeNode*> nodeStk;
		nodeStk.push(root);
		pathStk.push(std::to_string(root->val));
		while (!nodeStk.empty())
		{
			TreeNode* node = nodeStk.top();
			nodeStk.pop();
			std::string path = pathStk.top();
			pathStk.pop();
			// leaf node
			if (node->left == nullptr && node->right == nullptr)
			{
				result.push_back(path);
			}
			if (node->left)
			{
				nodeStk.push(node->left);
				pathStk.push(path + "->" + std::to_string(node->left->val));
			}
			if (node->right)
			{
				nodeStk.push(node->right);
				pathStk.push(path + "->" + std::to_string(node->right->val));
			}
		}
		return result;
	}
};