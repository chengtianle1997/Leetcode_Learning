#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursion Approach
class Solution_Recursion {
public:
    void traversal(TreeNode* root, std::vector<int>& result)
    {
        if (root == nullptr)
            return;
        traversal(root->left, result);
        traversal(root->right, result);
        result.emplace_back(root->val);
    }

	std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr)
            return result;
        traversal(root, result);
        return result;
	}
};

// Non-Recursion Approach
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr)
            return result;
        std::stack<TreeNode*> stack;
        TreeNode* node = root;
        stack.push(node);
        // preorder: root, left, right -> swap left and right: root, right, left -> reverse: left, right, root
        while (!stack.empty())
        {
            node = stack.top();
            stack.pop();
            result.emplace_back(node->val);
            // swap left and right: left in first, right out first!
            if (node->left)
                stack.push(node->left);
            if (node->right)
                stack.push(node->right);
        }
        std::reverse(result.begin(), result.end());
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
    PrintResult(solution.postorderTraversal(root));
    std::vector<int> nodes = { 1, NULL, 2, NULL, NULL, 3 };
    root = CreateTree(nodes);
    PrintResult(solution.postorderTraversal(root));
}