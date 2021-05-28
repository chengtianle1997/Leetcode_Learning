#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getDepth(TreeNode* node) {
        if (!node)
            return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        // Remember: the minimum depth of a binary tree is the number of nodes 
        // on the route to the nearest leaf node.
        // Important: leaf node means the node have neither a left child nor a right child.
        
        // Deal with the condition that the left child or the right child is not NULL
        if (node->left == NULL && node->right != NULL)
            return 1 + rightDepth;
        if (node->left != NULL && node->right == NULL)
            return 1 + leftDepth;

        return 1 + std::min(leftDepth, rightDepth);
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};

// Simple Recursion
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (root->left == NULL && root->right != NULL)
            return 1 + rightDepth;
        if (root->left != NULL && root->right == NULL)
            return 1 + leftDepth;
        return 1 + std::min(leftDepth, rightDepth);
    }
};

// Non-Recursion Solution: level-order traversal
#include <queue>
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        std::queue<TreeNode*> queue;
        int depth = 0;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
                // find a leaf node, return the depth
                if (node->left == NULL && node->right == NULL)
                    return depth;
            }
        }
        return depth;
    }
};