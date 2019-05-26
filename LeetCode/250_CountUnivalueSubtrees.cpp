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
	int countUnivalSubtrees(TreeNode* root) {
		if(!root)
			return 0;
		isUnivalTree(root);
		return count;
	}

private:
	int count = 0;

	bool isUnivalTree(TreeNode* root) {
		if(!root || (!root->left && !root->right)) {
			count++;
			return true;
		}
        
		bool is_unival = true;
        if(root->left)
            is_unival = isUnivalTree(root->left) && is_unival && root->left->val == root->val;
        if(root->right)
            is_unival = isUnivalTree(root->right) && is_unival && root->right->val == root->val;
        
        if(!is_unival)
            return false;
        count++;
        return true;
	}
};

int main() {
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(5);
	root->right = new TreeNode(5);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(5);

	cout << Solution().countUnivalSubtrees(root) << endl;
	return 0;
}
