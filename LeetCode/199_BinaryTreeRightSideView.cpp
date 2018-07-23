#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        vector<TreeNode *> vec1, vec2;
        vec1.push_back(root);

        while (vec1.size() > 0) {
            res.push_back(vec1[vec1.size() - 1]->val);
            for (int i = 0; i < vec1.size(); i++) {
                if (vec1[i]->left != NULL)
                    vec2.push_back(vec1[i]->left);
                if (vec1[i]->right != NULL)
                    vec2.push_back(vec1[i]->right);
            }
            vec1 = vec2;
            vec2.clear();
        }

        return res;
    }
};

int main()
{
    TreeNode *root;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    auto output = Solution().rightSideView(root);
    for (auto node : output)
        cout << node << " ";
    cout << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    output = Solution().rightSideView(root);
    for (auto node : output)
        cout << node << " ";
    cout << endl;

    return 0;
}