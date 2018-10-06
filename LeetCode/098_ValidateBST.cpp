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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Iterative in-order traversal, while checking with previously traversed value if strictly increasing
        //    Can also be done using recursive in-order traversal
        
        int prev_val;
        bool prev_assigned = false;
        stack<TreeNode *> nodes;
        TreeNode *curr = root;
        while (curr != NULL || !nodes.empty()) {
            while (curr != NULL) {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            if (!prev_assigned) {
                prev_assigned = true;
            } else {
                if (prev_val >= curr->val)
                    return false;
            }
            prev_val = curr->val;
            curr = curr->right;
        }
        
        return true;
    }
};

// Another elegant and simple solution. Just check if each node's value lies 
//   within valid range. Range is determined from the parent node. 
class Solution_Simple {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		return isValidBSTHelper(root->left, INT_MIN, root->val) &&
			isValidBSTHelper(root->right, root->data, INT_MAX);
	}

private:
	bool isValidBSTHelper(TreeNode* root, int min, int max) {
		if (root == NULL)
			return true;
		if (root->val < min || root->val > max)
			return false;
		return isValidBSTHelper(root->left, min, root->val) &&
			isValidBSTHelper(root->right, root->val, max);
	}
};

int main()
{

    return 0;
}

bool isBSTHelper(Node *root, int min, int max) {
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    
    return isBSTHelper(root->left, min, root->data) && isBSTHelper(root->right, root->data, max);
}

bool isBST(Node* root) {
    if (root == NULL)
        return true;
    // Your code here
    return isBSTHelper(root->left, INT_MIN, root->data) && isBSTHelper(root->right, root->data, INT_MAX);
}