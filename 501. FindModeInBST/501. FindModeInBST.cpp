#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursion Solution
class Solution {
public:
    int maxCount = 0;
    int counter = 0;
    TreeNode* pre = nullptr;
    std::vector<int> result;
    void traversal(TreeNode* root) {
        if (!root)
            return;
        traversal(root->left);

        if (pre == nullptr)
            counter = 1;
        else if (root->val == pre->val)
            counter++;
        else
            counter = 1;

        if (counter == maxCount)
            result.push_back(root->val);
        if (counter > maxCount)
        {
            result.clear();
            maxCount = counter;
            result.push_back(root->val);
        }

        pre = root;

        traversal(root->right);
    }
    std::vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }
};

// Non-Recursion Solution
class Solution {
public:
    std::vector<int> findMode(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        std::stack<TreeNode*> stack;
        int counter = 0;
        int maxCount = 0;
        while (cur != nullptr || !stack.empty())
        {
            if (cur != nullptr)
            {
                stack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stack.top();
                stack.pop();

                // counter
                if (pre == nullptr)
                {
                    counter = 1;
                }
                else if (cur->val == pre->val)
                {
                    counter++; 
                }
                else
                {
                    // different value
                    counter = 1;
                }

                if (counter == maxCount)
                {
                    result.push_back(cur->val);
                }
                if (counter > maxCount)
                {
                    result.clear();
                    maxCount = counter;
                    result.push_back(cur->val);
                }

                pre = cur;

                cur = cur->right;
            }
        }
        return result;
    }
};