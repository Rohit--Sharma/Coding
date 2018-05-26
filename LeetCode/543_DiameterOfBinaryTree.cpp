#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    
    int currentDiameter;
    if (root->left != NULL && root->right != NULL)
        currentDiameter = maxDepth(root->left) + maxDepth(root->right) + 2;
    else if (root->left != NULL && root->right == NULL)
        currentDiameter = maxDepth(root->left) + 1;
    else if (root->left == NULL && root->right != NULL)
        currentDiameter = maxDepth(root->right) + 1;
    else if (root->left == NULL && root->right == NULL)
        currentDiameter = 0;
    
    return max(currentDiameter, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int main()
{
    // Construct input tree
    TreeNode *input = new TreeNode(1);
    input->left = new TreeNode(2);
    input->left->left = new TreeNode(4);
    input->left->left->left = new TreeNode(8);
    input->left->left->left->left = new TreeNode(12);
    input->left->left->right = new TreeNode(9);
    input->left->right = new TreeNode(5);
    input->left->right->left = new TreeNode(10);
    input->left->right->right = new TreeNode(11);
    input->left->right->right->right = new TreeNode(13);
    input->right = new TreeNode(3);

    cout << diameterOfBinaryTree(input) << endl;
    return 0;
}