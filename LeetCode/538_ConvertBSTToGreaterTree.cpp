#include <cstdio>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum = 0;

void createGreaterTree(TreeNode *root)
{
    if (root == NULL)
        return;
    
    createGreaterTree(root->right);
    sum = sum + root->val;
    root->val = sum;
    createGreaterTree(root->left);
}

/// Converts a BST to a Greater Tree where every node's value
///    is added with sum of all the nodes in the tree with value 
///    greater than it
TreeNode* convertBST(TreeNode* root) 
{
    if (root == NULL)
        return NULL;
    sum = 0;
    createGreaterTree(root);
    return root;
}

void inOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main()
{
    // Construct input tree
    TreeNode *input = new TreeNode(5);
    input->left = new TreeNode(2);
    input->right = new TreeNode(13);

    TreeNode *output = convertBST(input);

    // Print inorder traversal of the tree
    cout << "Inorder traversal: ";
    inOrderTraversal(output);
    cout << endl;

    input = new TreeNode(8);
    input->left = new TreeNode(4);
    input->right = new TreeNode(13);
    input->left->left = new TreeNode(1);
    input->left->right = new TreeNode(6);
    input->left->right->left = new TreeNode(5);
    input->right->left = new TreeNode(10);
    input->right->right = new TreeNode(15);

    output = convertBST(input);

    // Print inorder traversal of the tree
    cout << "Inorder traversal: ";
    inOrderTraversal(output);
    cout << endl;

    return 0;
}