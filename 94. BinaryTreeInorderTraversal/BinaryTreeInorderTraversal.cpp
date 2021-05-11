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
    void traversal(TreeNode* root, std::vector<int>& result)
    {
        if (!root)
            return;
        traversal(root->left, result);
        result.emplace_back(root->val);
        traversal(root->right, result);
    }

	std::vector<int> inorderTraversal(TreeNode* root)
	{
        std::vector<int> result;
        if (!root)
            return result;
        traversal(root, result);
        return result;
	}
};

// Non-Recursion Approach
// What We can see in Title 144 and 145 (Preorder and Postorder traversal) is that
// we cannot write almost the same code like recursion version code in non-recursion ones,
// because we cannot push_back the node into the result vector and push the node to the stack at the same time.
// Therefore, we have to find a way to mark the node by pushing a NULL to the stack after we pushing it to the stack.

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;
        std::stack<TreeNode*> stack;
        TreeNode* node = root;
        stack.push(node);
        while (!stack.empty())
        {
            node = stack.top();
            // it is a normal node
            if (node)
            {
                stack.pop();
                // we push the right first, and pop the left first.
                if (node->right)
                    stack.push(node->right);
                stack.push(node);
                stack.push(NULL); // push the mark after the node
                if (node->left)
                    stack.push(node->left);
            }
            // we get the mark
            else
            {
                stack.pop(); // pop the mark(NULL)
                node = stack.top();
                stack.pop();
                result.emplace_back(node->val);
            }
        }
        return result;
    }

    // Similarly, we can write the PreorderTraversal and PostTraversal
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;
        TreeNode* node = root;
        std::stack<TreeNode*> stack;
        stack.push(node);
        while (!stack.empty())
        {
            node = stack.top();
            // normal node
            if (node)
            {
                stack.pop();
                // push order: right, left, middle
                // pop order: middle, left, right
                if (node->right)
                    stack.push(node->right);
                if (node->left)
                    stack.push(node->left);
                stack.push(node);
                stack.push(NULL); // push the mark after the node
            }
            // get the mark
            else
            {
                stack.pop();
                node = stack.top();
                stack.pop();
                result.emplace_back(node->val);
            }
        }
        return result;
    }

    
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;
        std::stack<TreeNode*> stack;
        TreeNode* node = root;
        stack.push(node);
        while (!stack.empty())
        {
            node = stack.top();
            stack.pop();
            // normal node
            if (node)
            {
                // pop order: left, right, middle
                // push order: middle, right, left
                stack.push(node);
                stack.push(NULL); // push a mark after node
                if (node->right)
                    stack.push(node->right);
                if (node->left)
                    stack.push(node->left);
            }
            // get the mark
            else
            {
                node = stack.top();
                stack.pop();
                result.emplace_back(node->val);
            }
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
    PrintResult(solution.inorderTraversal(root));
    std::vector<int> nodes = { 1, NULL, 2, NULL, NULL, 3 };
    root = CreateTree(nodes);
    PrintResult(solution.inorderTraversal(root));
}