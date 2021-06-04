#include <vector>
#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
		// Step 1: recursion ending
		if (nums.size() == 0)
			return nullptr;

		// Step 2: find the root / maximum
		int rootValue = nums[0];
		int rootIndex = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > rootValue)
			{
				rootValue = nums[i];
				rootIndex = i;
			}
		}
		TreeNode* root = new TreeNode(rootValue);

		// Step 3: devide the vector by root
		std::vector<int> left(nums.begin(), nums.begin() + rootIndex);
		std::vector<int> right(nums.begin() + rootIndex + 1, nums.end());

		// Step 4: build the left subtree and right subtree recursively
		root->left = constructMaximumBinaryTree(left);
		root->right = constructMaximumBinaryTree(right);

		return root;
	}
};

// Avoid vector copying and constructing: better performance, beat 90%+
class Solution {
public:
	TreeNode* traversal(std::vector<int>& nums, int start, int end) {
		// Here, nums[start] is included, while nums[end] is not included.
		// Step 1: Find the root.
		int rootValue = nums[start];
		int rootIndex = start;
		for (int i = start + 1; i < end; i++)
		{
			if (nums[i] > rootValue)
			{
				rootValue = nums[i];
				rootIndex = i;
			}
		}
		TreeNode* root = new TreeNode(rootValue);

		// Step 2: if the left subtree is not empty
		if (rootIndex > start)
		{
			root->left = traversal(nums, start, rootIndex);
			// Remember: nums[rootIndex] is not included, it is a range as [start, rootIndex).
		}

		// Step 3: if the right subtree is not empty
		if (rootIndex < end - 1)
		{
			root->right = traversal(nums, rootIndex + 1, end);
		}

		return root;
	}
	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;
		return traversal(nums, 0, nums.size());
	}
};