#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int maxLen = -1;
	int maxLeftValue = 0;
	void traversal(TreeNode* node, int len) {
		if (!node->left && !node->right)
		{
			// if the node is a deeper child
			if (len > maxLen)
			{
				maxLen = len;
				maxLeftValue = node->val;
			}
			return;
		}
		if (node->left)
			traversal(node->left, len + 1);
		if (node->right)
			traversal(node->right, len + 1);
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 0);
		return maxLeftValue;
	}
};

// Non-Recursion SolutionL: level-order traversal
#include <queue>
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		if (!root)
			return 0;
		std::queue<TreeNode*> queue;
		queue.push(root);
		int result = 0;
		while (!queue.empty())
		{
			int size = queue.size();
			result = queue.front()->val;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = queue.front();
				queue.pop();
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}
		}
		return result;
	}
};