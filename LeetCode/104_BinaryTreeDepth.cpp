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

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

// Top Down approach: Like Preorder Traversal
class SolutionTopDown {
public:
	int maxDepth(TreeNode* root) {
		topDownHelper(root, 1);
		return result;
	}

private:
	int result = 0;

	void topDownHelper(TreeNode *root, int depth) {
		if(root == nullptr)
			return;
		if(root->left == nullptr && root->right == nullptr) {
			result = max(result, depth);
			return;
		}
		topDownHelper(root->left, depth + 1);
		topDownHelper(root->right, depth + 1);
	}
};

// Bottom Up approach: Like Postorder Traversal
class SolutionBottomUp {
public:
	int maxDepth(TreeNode* root) {
		if(!root)
			return 0;
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		return max(left_depth, right_depth) + 1;
	}
};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->left->left = new TreeNode(10);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	cout << SolutionBottomUp().maxDepth(root) << endl;

	return 0;
}
