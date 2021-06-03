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
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		// Step 1: Recursion ending
		if (preorder.size() == 0 && inorder.size() == 0)
			return nullptr;

		// Step 2: The root is the first element of preorder traversal
		int rootValue = preorder[0];
		TreeNode* root = new TreeNode(rootValue);

		// Step 3: Find the devide point in inorder sequence
		int devideIndex = 0;
		for (devideIndex = 0; devideIndex < inorder.size(); devideIndex++)
		{
			if (inorder[devideIndex] == rootValue)
				break;
		}

		// Step 4: Cut the inorder traversal to left inorder and right inorder
		std::vector<int> leftInorder(inorder.begin(), inorder.begin() + devideIndex);
		std::vector<int> rightInorder(inorder.begin() + devideIndex + 1, inorder.end());

		// Step 5: Cut the preorder traversal to  left preorder and right preorder
		std::vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
		std::vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

		// Step 6: Recursion
		root->left = buildTree(leftPreorder, leftInorder);
		root->right = buildTree(rightPreorder, rightInorder);

		return root;
	}
};