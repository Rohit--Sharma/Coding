#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    if (root == NULL)
        return result;
    
    stack<TreeNode *> myStack;
    // myStack.push(root);

    // while (!myStack.empty()) {
    //     TreeNode *lCh = myStack.top()->left;
    //     while (lCh != NULL) {
    //         cout << lCh->val << " ";
    //         myStack.push(lCh);
    //         lCh = lCh->left;
    //     }
    //     // while (myStack.top()->left != NULL)
    //     //     myStack.push(myStack.top()->left);
    //     result.push_back((myStack.top())->val);
    //     TreeNode *rCh = (myStack.top())->right;
    //     myStack.pop();
    //     if (rCh != NULL)
    //         myStack.push(rCh);
    // }

    TreeNode *curr = root;
    while (curr != NULL || !myStack.empty()) {
        while (curr != NULL) {
            myStack.push(curr);
            curr = curr->left;
        }
        curr = myStack.top();
        myStack.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }

    return result;
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);

    auto res = inorderTraversal(tree);

    for (int v : res)
        cout << v << " ";
    cout << endl;

    return 0;
}