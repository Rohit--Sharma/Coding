#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrderTraversal(TreeNode *root, vector<int>& sorted)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, sorted);
    sorted.push_back(root->val);
    inOrderTraversal(root->right, sorted);
}

int minDiffInBST(TreeNode* root)
{
    vector<int> sorted;
    inOrderTraversal(root, sorted);

    int minDiff = INT_MAX;
    for (int i = 0; i < sorted.size() - 1; i++)
        minDiff = min(minDiff, sorted[i + 1] - sorted[i]);
    return minDiff;
}

int main()
{
    TreeNode *root = new TreeNode(90);
    root->left = new TreeNode(69);
    root->left->left = new TreeNode(49);
    root->left->right = new TreeNode(89);
    root->left->left->right = new TreeNode(52);

    cout << minDiffInBST(root) << endl;

    return 0;
}