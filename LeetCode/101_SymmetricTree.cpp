#include <cstdio>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursive utility function for isSymmetricRecursive
bool isMirror(TreeNode *t1, TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

/// Returns if the two children of the root node are mirror images of each other recursively
bool isSymmetricRecursive(TreeNode* root)
{
    return isMirror(root, root);
}

/// Returns if the two children of the root node are mirror images of each other iteratively
///     A modification of BFS
bool isSymmetricIterative(TreeNode* root)
{
    queue<TreeNode *> q;

    q.push(root);
    q.push(root);

    while (!q.empty()) {
        TreeNode *t1 = q.front();
        q.pop();
        TreeNode *t2 = q.front();
        q.pop();

        if (t1 == NULL && t2 == NULL)
            continue;
        if (t1 == NULL || t2 == NULL)
            return false;
        if (t1->val != t2->val)
            return false;
        
        q.push(t1->left);
        q.push(t2->right);

        q.push(t1->right);
        q.push(t2->left);
    }
    
    return true;
}

int main()
{
    
    return 0;
}