#include <iostream>
#include <algorithm>
#include <vector>

struct Node {
	int val;
	std::vector<Node*> children;

	Node(int x) {
		val = x;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		if (!root)
			return 0;
		int depth = 0;
		for (int i = 0; i < root->children.size(); i++)
		{
			depth = std::max(depth, maxDepth(root->children[i]));
		}
		return depth + 1;
	}
};

// Non-Recursion solution: level-order traversal
#include <queue>
class Solution {
public:
	int maxDepth(Node* root) {
		if (!root)
			return 0;
		int depth = 0;
		std::queue<Node*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			int size = queue.size();
			depth++;
			for (int i = 0; i < size; i++)
			{
				Node* node = queue.front();
				queue.pop();
				for (int j = 0; j < node->children.size(); j++)
				{
					if (node->children[j])
						queue.push(node->children[j]);
				}
			}
		}
		return depth;
	}
};
