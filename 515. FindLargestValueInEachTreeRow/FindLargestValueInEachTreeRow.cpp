#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            int maxValue = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                maxValue = node->val > maxValue ? node->val : maxValue;
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            result.emplace_back(maxValue);
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
    {

        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;
    TreeNode* root = nullptr;
    PrintResult(solution.largestValues(root));
    std::vector<int> nodes = { 1, 3, 2, 5, 3, NULL, 9 };
    root = CreateTree(nodes);
    PrintResult(solution.largestValues(root));
}