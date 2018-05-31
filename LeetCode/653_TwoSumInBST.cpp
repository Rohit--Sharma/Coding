#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /// Not using the property that the tree is a BST. 
    ///    Another approach is to do an inorder traversal to find a sorted list and then do Binary Search to find the result
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        
        if (myMap.find(k - root->val) != myMap.end())
            return true;
        else
            myMap[root->val] = 1;
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    
private:
    map<int, int> myMap;
};