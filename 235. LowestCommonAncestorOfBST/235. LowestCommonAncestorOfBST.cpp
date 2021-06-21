#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// The solution for Lowest common ancestor of binary tree is different from the common ancestor of binary search tree.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

// Non-Recursion Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root)
        {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};