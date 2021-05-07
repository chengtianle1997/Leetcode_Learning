#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursion Approach
class Solution_Recursion {
public:
    void traversal(TreeNode* node, std::vector<int>& result)
    {
        if (node == nullptr)
            return;
        result.emplace_back(node->val); // emplace_back is much faster than push_back here.
        traversal(node->left, result);
        traversal(node->right, result);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr)
            return result;
        traversal(root, result);
        return result;
    }
};

// Non-Recursion Approach: using stack
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr)
            return result;
        std::stack<TreeNode*> stack;
        TreeNode* node = root;
        stack.push(node);
        while (!stack.empty())
        {
            node = stack.top();
            result.emplace_back(node->val);
            stack.pop();
            // stack is a first in last out (FILO) structure, so push the right node first,
            // and we will pop the left node first.
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }
        return result;
    }
};

TreeNode* CreateTree(std::vector<int> nodes)
{
    TreeNode* root = nullptr;
    if (nodes.size() == 0 || nodes[0] == NULL)
        return root;
    int n = nodes.size();
    root = new TreeNode(nodes[0]);
    std::queue<std::pair<TreeNode*, int>> queue;
    queue.push({ root, 0 });
    while (!queue.empty())
    {
        auto node_info = queue.front();
        TreeNode* node = node_info.first;
        int node_id = node_info.second;
        queue.pop();
        // left child exists
        if (node_id * 2 + 1 < n && nodes[node_id * 2 + 1] != NULL)
        {
            TreeNode* left = new TreeNode(nodes[node_id * 2 + 1]);
            node->left = left;
            queue.push({ left, node_id * 2 + 1 });
        }
        // right child exists
        if (node_id * 2 + 2 < n && nodes[node_id * 2 + 2] != NULL)
        {
            TreeNode* right = new TreeNode(nodes[node_id * 2 + 2]);
            node->right = right;
            queue.push({ right, node_id * 2 + 2 });
        }
    }
    return root;
}

void PrintResult(std::vector<int> result)
{
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}

int main()
{
    Solution solution;
    TreeNode* root = nullptr;
    PrintResult(solution.preorderTraversal(root));
    std::vector<int> nodes = { 1, NULL, 2, NULL, NULL, 3 };
    root = CreateTree(nodes);
    PrintResult(solution.preorderTraversal(root));
}