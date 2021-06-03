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
	TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
		// Step 1: if there is nothing left in the vector, the node is nullptr.
		if (postorder.size() == 0 || inorder.size() == 0)
			return nullptr;

		// Step 2: the last element of postorder traversal is the root.
		int rootValue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootValue);

		// Step 3: find the deviding point in inorder traversal
		int devide_index = 0;
		for (devide_index = 0; devide_index < inorder.size(); devide_index++)
		{
			if (inorder[devide_index] == rootValue)
				break;
		}

		// Step 4: Cut inorder traversal and get inorder left vector and inorder right vector
		// inorder left:
		std::vector<int> leftInorder(inorder.begin(), inorder.begin() + devide_index);
		// inorder right:
		std::vector<int> rightInorder(inorder.begin() + devide_index + 1, inorder.end());

		// Step 5: Cut postorder traversal and get postorder left and postorder right
		// left: the size of postorder left equals to the size ot inorder left
		std::vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		// Remember, postorder.begin() + leftInorder.size() element is not included here.
		// right: the size of postorder right equals to the size ot inorder right
		std::vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);
		// Remember, postorder.begin() + leftInorder.size() element is included here.

		// Step 6: Recursion for left range and right range
		root->left = buildTree(leftInorder, leftPostorder);
		root->right = buildTree(rightInorder, rightPostorder);

		return root;
	}
};