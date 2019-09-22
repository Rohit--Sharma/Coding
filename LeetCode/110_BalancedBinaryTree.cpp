#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

// Top down solution, not very efficient O(n^2) worst case, O(n lgn) average case
class Solution_TopDown {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int left_dep = max_depth(root->left);
        int right_dep = max_depth(root->right);
        
        return isBalanced(root->left) && isBalanced(root->right) && abs(left_dep - right_dep) <= 1;
    }
    
private:
    int max_depth(TreeNode* root) {
        if(!root)
            return 0;
        
        return max(max_depth(root->left), max_depth(root->right)) + 1;
    }
};

// Keeps checking the bottom up property in bottom up manner
// Complexity: O(n)
class Solution_BottomUp {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root) != -1;
    }

private:
    // Keeps checking the balanced tree property for each call based on left and right
    //   child depths. If the property is violated, it returns -1. Else returns max depth.
    int isBalancedHelper(TreeNode* root) {
        if(!root)
            return 0;
        
        int left_height = isBalancedHelper(root->left);
        if(left_height == -1)
            return -1;
        int right_height = isBalancedHelper(root->right);
        if(right_height == -1)
            return -1;
        
        if(abs(left_height - right_height) > 1)
            return -1;
        
        return max(left_height, right_height) + 1;
    }
};

int main() {

    return 0;
}