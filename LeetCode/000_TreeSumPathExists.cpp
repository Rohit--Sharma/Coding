#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

// Was asked to implement this in Bloomberg. 
// Returns true if there exists a leaf node with sum of the values to that leaf node
//    from the root node is equal to k. Else returns false
bool hasPathWithSum(TreeNode *root, int k) {
	if (root == NULL)
		return false;
	if (root->left == NULL && root->right == NULL)
		if (root->val == k)
			return true;
		else
			return false;
	
	return hasPathWithSum(root->left, k - root->val) || hasPathWithSum(root->right, k - root->val);
}

int main() {
	/*
				3
			4		2
		1
	*/
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(1);

	cout << hasPathWithSum(root, 8) << endl;

	return 0;
}