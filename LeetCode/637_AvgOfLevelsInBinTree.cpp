#include <cstdio>
#include <algorithm>
#include <vector>

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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> res;
            vector<int> count;
            calculateAverageOfLevels(root, res, count, 0);
            for (int i = 0; i < count.size(); i++)
                res[i] /= count[i];
            return res;
        }

    private:
        void calculateAverageOfLevels(TreeNode *root, vector<double>& res, vector<int>& nodeCountPerLevel, int level) {
            if (root == NULL)
                return;
            
            if (res.size() > level) {
                nodeCountPerLevel[level]++;
                res[level] += root->val;
            }
            else {
                nodeCountPerLevel.push_back(1);
                res.push_back(root->val);
            }
            calculateAverageOfLevels(root->left, res, nodeCountPerLevel, level + 1);
            calculateAverageOfLevels(root->right, res, nodeCountPerLevel, level + 1);
        }
};