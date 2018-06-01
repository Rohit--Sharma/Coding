#include <cstdio>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int secondMin(TreeNode *root, int& minimum, int& secMin);

int findSecondMinimumValue(TreeNode *root)
{
    int minimum = INT_MAX, secMin = INT_MAX;
    
    return secondMin(root, minimum, secMin);
}

int secondMin(TreeNode *root, int& minimum, int& secMin)
{
    if (root == NULL)
        return -1;
    
    if (root->val < minimum) {
        secMin = minimum;
        minimum = root->val;
    }
    else if (root->val > minimum && root->val < secMin)
        secMin = root->val;

    secondMin(root->left, minimum, secMin);
    secondMin(root->right, minimum, secMin);

    return secMin == INT_MAX ? -1 : secMin;
}

int main()
{
    TreeNode *input = new TreeNode(2);
    input->left = new TreeNode(2);
    input->right = new TreeNode(5);
    input->right->left = new TreeNode(5);
    input->right->right = new TreeNode(7);

    cout << findSecondMinimumValue(input) << endl;

    input = new TreeNode(2);
    input->left = new TreeNode(2);
    input->right = new TreeNode(2);

    cout << findSecondMinimumValue(input) << endl;

    return 0;
}