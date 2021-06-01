#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool compare(TreeNode* node_a, TreeNode* node_b) {
		if (node_a == nullptr && node_b == nullptr)
			return true;
		else if (node_a == nullptr && node_b != nullptr)
			return false;
		else if (node_a != nullptr && node_b == nullptr)
			return false;
		else if (node_a->val != node_b->val)
			return false;
		return compare(node_a->left, node_b->left) && compare(node_a->right, node_b->right);
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return compare(p, q);
	}
};

// Non-Recursion solution
#include <queue>
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p == nullptr || q == nullptr)
			return false;
		std::queue<TreeNode*> que;
		que.push(p);
		que.push(q);
		while (!que.empty())
		{
			TreeNode* node_a = que.front();
			que.pop();
			TreeNode* node_b = que.front();
			que.pop();
			if (node_a == nullptr && node_b == nullptr)
				continue;
			if (node_a == nullptr || node_b == nullptr || node_a->val != node_b->val)
				return false;
			que.push(node_a->left);
			que.push(node_b->left);
			que.push(node_a->right);
			que.push(node_b->right);
		}
		return true;
	}
};