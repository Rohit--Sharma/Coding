#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if(!node)
			return nullptr;
		
		Node* cloned = new Node(node->val, vector<Node*>{});
		created[node] = cloned;

		for(Node* child: node->neighbors) {
			if(created.find(child) == created.end()) {
				Node* cloned_child = cloneGraph(child);
				created[child] = cloned_child;
			}
			cloned->neighbors.push_back(created[child]);
		}

		return cloned;
	}

private:
	// A map from old nodes to newly created nodes.
	unordered_map<Node*, Node*> created;
};


int main() {
	Node *one = new Node(1, vector<Node*>{});
	Node *two = new Node(2, vector<Node*>{});
	Node *three = new Node(3, vector<Node*>{});
	Node *four = new Node(4, vector<Node*>{});

	one->neighbors.push_back(two); one->neighbors.push_back(four);
	two->neighbors.push_back(one); two->neighbors.push_back(three);
	three->neighbors.push_back(two); three->neighbors.push_back(four);
	four->neighbors.push_back(one); four->neighbors.push_back(three);

	Node* clone = Solution().cloneGraph(one);

	return 0;
}
