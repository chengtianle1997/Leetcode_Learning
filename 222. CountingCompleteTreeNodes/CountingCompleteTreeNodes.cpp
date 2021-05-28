#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

// Non-Recursion Solution: level-order traversal
#include <queue>
class Solution_A {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		std::queue<TreeNode*> queue;
		queue.push(root);
		int counter = 0;
		while (!queue.empty())
		{
			int size = queue.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = queue.front();
				queue.pop();
				counter++;
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}
		}
		return counter;
	}
};

// Non-Recursion Solution: post-order traversal
#include <stack>
class Solution_B {
public:
	int countNodes(TreeNode* root)
	{
		if (!root)
			return 0;
		int counter = 0;
		std::stack<TreeNode*> stack;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* node = stack.top();
			stack.pop();
			if (node)
			{
				// pop order: left right middle
				// push order: middle, right, left
				stack.push(node);
				stack.push(NULL); // mark
				if (node->left)
					stack.push(node->left);
				if (node->right)
					stack.push(node->right);
			}
			else
			{
				// pop the real node
				node = stack.top();
				stack.pop();
				counter++;
			}
		}
		return counter;
	}
};

// Solution for complete Tree: Simplify the Recursion   O(logN * logN)
#include <cmath>  // power function
class Solution_C {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		// In a complete binary tree, we can find complete subtree,
		// and we can use the formula (nodes = 2^depth - 1) to simplify the counting process
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftDepth = 1;
		int rightDepth = 1;
		while (left)
		{
			left = left->left;
			leftDepth++;
		}
		while (right)
		{
			right = right->right;
			rightDepth++;
		}
		// if a complete subtree is found
		if (leftDepth == rightDepth)
			return pow(2, leftDepth) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

int main()
{
	// there is another way to do power calculation
	std::cout << pow(2, 5) << std::endl;
	std::cout << (2 << (5 - 1)) << std::endl;
	// run this code and try it.
}