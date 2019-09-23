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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        queue<TreeNode*> my_qu;
        my_qu.push(root);
        bool dir = true;
        
        while(!my_qu.empty()) {
            int curr_lvl_sz = my_qu.size();
            vector<int> curr_lvl (curr_lvl_sz);
            
            for(int i = 0; i < curr_lvl_sz; i++) {
                // * Important step
                int idx = dir ? i : curr_lvl_sz - i - 1;
                TreeNode* curr = my_qu.front();
                my_qu.pop();
                curr_lvl[idx] = curr->val;
                
                if(curr->left)
                    my_qu.push(curr->left);
                if(curr->right)
                    my_qu.push(curr->right);
            }
            
            res.push_back(curr_lvl);
            dir = !dir;
        }
        
        return res;
    }
};

int main() {

    return 0;
}