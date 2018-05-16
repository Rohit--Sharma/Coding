#include <cstdio>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTreeRec(TreeNode* root) 
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return root;
    
    TreeNode *left = invertTreeRec(root->right);
    TreeNode *right = invertTreeRec(root->left);
    
    root->left = left;
    root->right = right;
    
    return root;
}

TreeNode* invertTreeIter(TreeNode* root)
{
    if (root == NULL)
        return root;
    
    queue<TreeNode *> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()) {
        TreeNode *current = myQueue.front();
        myQueue.pop();
        TreeNode *temp = current->left;
        current->left = current->right;
        current->right = temp;

        if (current->left != NULL)
            myQueue.push(current->left);
        if (current->right != NULL)
            myQueue.push(current->right);
     }
     return root;
}