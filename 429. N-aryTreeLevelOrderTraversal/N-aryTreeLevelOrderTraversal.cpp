#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
	int val;
	std::vector<Node*> children;

	Node() {}
	Node(int val)
	{
		this->val = val;
	}
	Node(int val, std::vector<Node*> children)
	{
		this->val = val;
		this->children = children;
	}
};

class Solution {
public:
	std::vector<std::vector<int>> levelOrder(Node* root) {
		std::vector<std::vector<int>> result;
		if (!root)
			return result;
		std::queue<Node*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			int size = queue.size();
			std::vector<int> level;
			for (int i = 0; i < size; i++)
			{
				Node* node = queue.front();
				queue.pop();
				level.emplace_back(node->val);
				for (Node*& child : node->children) // use the reference of the pointer to avoid copying and make it faster.
				{
					if (child)
						queue.push(child);
				}
			}
			result.emplace_back(level);
		}
		return result;
	}
};