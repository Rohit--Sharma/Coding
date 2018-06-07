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
        int longestUnivaluePath(TreeNode* root) {
            ans = 0;
            arrowLength(root);
            return ans;
        }
        
    private:
        int ans;
        int arrowLength(TreeNode *root) {
            if (root == NULL)
                return 0;

            int left = arrowLength(root->left);
            int right = arrowLength(root->right);

            int arrowLeft = 0, arrowRight = 0;
            if (root->left != NULL && root->left->val == root->val)
                arrowLeft += left + 1;
            if (root->right != NULL && root->right->val == root->val)
                arrowRight += right + 1;
                
            ans = max(ans, arrowLeft + arrowRight);
            return max(arrowLeft, arrowRight);
        }
};