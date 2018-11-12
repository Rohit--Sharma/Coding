#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "NULL";
        string result = to_string(root->val);
        return result + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t pos = 0;

		// Region: Tokenize input with delimiter = ","
		list<string> tokens;
		while ((pos = data.find(",")) != string::npos) {
			tokens.push_back(data.substr(0, pos));
			data.erase(0, pos + 1);
		}
		tokens.push_back(data);
		// Region: Tokenize complete

		return deserialize_helper(tokens);
    }

private:
	TreeNode *deserialize_helper(list<string> &tokens) {
		if (tokens.front().compare("NULL") == 0) {
			tokens.pop_front();
			return NULL;
		}

		TreeNode *root = new TreeNode(stoi(tokens.front()));
		tokens.pop_front();

		root->left = deserialize_helper(tokens);
		root->right = deserialize_helper(tokens);

		return root;
	}
};

void inOrderTraversal(TreeNode *node) {
	if (node != NULL) {
		inOrderTraversal(node->left);
		cout << node->val << " ";
		inOrderTraversal(node->right);
	}
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
	/**
     *                      8
     *              4              10
     *         2        5       9       13
     *      1    3        7           11    
     */
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(13);
    root->right->right->left = new TreeNode(11);

	string serialized = Codec().serialize(root);
	cout << serialized << endl;

	TreeNode *deserialized = Codec().deserialize(serialized);
	inOrderTraversal(deserialized);
	cout << endl;

    return 0;
}