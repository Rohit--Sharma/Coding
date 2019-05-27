#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
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

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return root;
		
		if (root == p || root == q)
			return root;
		
		TreeNode *lca_left = lowestCommonAncestor(root->left, p, q);
		TreeNode *lca_right = lowestCommonAncestor(root->right, p, q);
		if (lca_left != NULL && lca_right != NULL)
			return root;
		else if (lca_left != NULL)
			return lca_left;
		else if (lca_right != NULL)
			return lca_right;
		else
			return NULL;
	}
};

int main() {

	return 0;
}
