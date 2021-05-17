#include <iostream>
#include <algorithm>
#include <stack>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// We can use both recursive approach and non-recursive approach for this title,
// and we can use both preorder traversal and postorder traversal method.
// However, we cannot use the inorder traversal for we may swap some nodes twice.
// In fact, we can also use level order traversal.

// Recursive approach
class Solution_Recursive {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return root;
		invertTree(root->left);
		invertTree(root->right);
		/*TreeNode* swap = root->left;
		root->left = root->right;
		root->right = swap;*/
		std::swap(root->left, root->right); // we can swap before or after invertTree();
		return root;
	}
};

// Non-Recursive approach
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return root;
		std::stack<TreeNode*> stack;
		stack.push(root);
		TreeNode* node = nullptr;
		while (!stack.empty())
		{
			node = stack.top();
			stack.pop();
			if (node)
			{
				// stack is a FILO structure:
				// input order: right, left, middle
				// output order: middle, left, right (preorder traversal)
				if (node->right)
					stack.push(node->right);
				if (node->left)
					stack.push(node->left);
				stack.push(node);
				stack.push(NULL); // mark
			}
			else
			{
				node = stack.top();
				stack.pop();
				std::swap(node->left, node->right);
			}
		}
		return root;
	}
};