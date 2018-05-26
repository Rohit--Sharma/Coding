#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrderTraversal(TreeNode *root, vector<string>& inOrder)
{
    if (root == NULL) {
        inOrder.push_back("$");
        return;
    }
    
    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(to_string(root->val));
    inOrderTraversal(root->right, inOrder);
}

void preOrderTraversal(TreeNode *root, vector<string>& preOrder)
{
    if (root == NULL) {
        preOrder.push_back("$");
        return;
    }
    
    preOrder.push_back(to_string(root->val));
    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
}

bool isSubVector(vector<string> patternVector, vector<string> superVector)
{
    int i, foundPos = 0;

    while (foundPos < superVector.size()) {
        if (superVector[foundPos] == patternVector[0]) {
            i = 1;
            while (i < patternVector.size() && (foundPos + i) < superVector.size() && superVector[foundPos + i] == patternVector[i])
                i++;
            
            if (i == patternVector.size()) {
                return true;
            }
            else if ((foundPos + i) == superVector.size()) {
                return false;
            }
        }
        foundPos++;
    }

    return false;
}

bool isSubTree(TreeNode *s, TreeNode *t)
{
    vector<string> inOrderSub, preOrderSub, inOrderT, preOrderT;

    inOrderTraversal(t, inOrderSub);
    preOrderTraversal(t, preOrderSub);

    inOrderTraversal(s, inOrderT);
    preOrderTraversal(s, preOrderT);

    return isSubVector(inOrderSub, inOrderT) && isSubVector(preOrderSub, preOrderT);
}

int main()
{
    // Construct s_tree tree
    TreeNode *s_tree = new TreeNode(3);
    s_tree->left = new TreeNode(4);
    s_tree->left->left = new TreeNode(1);
    s_tree->left->right = new TreeNode(2);
    s_tree->right = new TreeNode(5);

    TreeNode *t_tree = new TreeNode(4);
    t_tree->left = new TreeNode(1);
    t_tree->right = new TreeNode(2);

    cout << isSubTree(s_tree, t_tree) << endl;

    s_tree = new TreeNode(3);
    s_tree->left = new TreeNode(4);
    s_tree->left->left = new TreeNode(1);
    s_tree->left->right = new TreeNode(2);
    s_tree->left->right->left = new TreeNode(0);
    s_tree->right = new TreeNode(5);

    cout << isSubTree(s_tree, t_tree) << endl;

    s_tree = new TreeNode(3);
    s_tree->left = new TreeNode(4);
    s_tree->left->left = new TreeNode(1);
    s_tree->left->right = new TreeNode(2);
    s_tree->right = new TreeNode(5);
    s_tree->right->left = new TreeNode(0);

    t_tree = new TreeNode(4);
    t_tree->left = new TreeNode(1);
    //t_tree->right = new TreeNode(2);

    cout << isSubTree(s_tree, t_tree) << endl;

    return 0;
}