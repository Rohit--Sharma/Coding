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

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * O(1) hasNext() and next()
 * O(h) space
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        traverse_tree_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !temp_nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *nxt = temp_nodes.top();
        temp_nodes.pop();
        traverse_tree_left(nxt->right);
        return nxt->val;
    }

private:
    stack<TreeNode *> temp_nodes;

    void traverse_tree_left(TreeNode *root) {
        if (root != NULL) {
            temp_nodes.push(root);
            traverse_tree_left(root->left);
        }
    }
};

/**
 * O(1) hasNext() and next()
 * O(n) space
 */
class BSTIterator_SpaceInefficient {
public:
    BSTIterator_SpaceInefficient(TreeNode *root) {
        traverse_tree(root);
        inorder_it = inorder.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return inorder_it != inorder.end();
    }

    /** @return the next smallest number */
    int next() {
        int val = *inorder_it;
        inorder_it++;
        return val;
    }

private:
    list<int> inorder;
    list<int>::iterator inorder_it;

    void traverse_tree(TreeNode *root) {
        if (root != NULL) {
            traverse_tree(root->left);
            inorder.push_back(root->val);
            traverse_tree(root->right);
        }
    }
};

int main() {
    /**
     *                      8
     *              4              10
     *         2        5       9       13
     *      1    3        7           11    
     */
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(13);
    root->right->right->left = new TreeNode(11);

    BSTIterator iter = BSTIterator(root);
    while (iter.hasNext())
        cout << iter.next();
    cout << endl;
    
    return 0;
}