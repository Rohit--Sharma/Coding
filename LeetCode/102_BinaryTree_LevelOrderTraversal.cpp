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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionRecursive {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		levelOrderHelper(root, result, 0);
		return result;
	}

private:
	void levelOrderHelper(TreeNode* root, vector<vector<int>> &result, int level) {
		if(root == nullptr)
			return;
		
		if(result.size() <= level)
			result.push_back(vector<int>{});

		result[level].push_back(root->val);
		levelOrderHelper(root->left, result, level + 1);
		levelOrderHelper(root->right, result, level + 1);
	}
};

class SolutionIterative {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if(root == nullptr)
			return result;
		queue<TreeNode *> my_queue;
		my_queue.push(root);

		while(!my_queue.empty()) {
			int curr_level_size = my_queue.size();	// Crucial step: number of nodes in curr level will be size of the queue
			vector<int> curr_level(curr_level_size, 0);
			for(int i = 0; i < curr_level_size; i++) {
				TreeNode *curr = my_queue.front();
				my_queue.pop();
				curr_level[i] = curr->val;
				if(curr->left != nullptr)
					my_queue.push(curr->left);
				if(curr->right != nullptr)
					my_queue.push(curr->right);
			}
			result.push_back(curr_level);
		}

		return result;
	}
};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->left->left = new TreeNode(10);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int>> level_order_traversal = SolutionIterative().levelOrder(root);
	for(int i = 0; i < level_order_traversal.size(); i++) {
		for(int j = 0; j < level_order_traversal[i].size(); j++) {
			cout << level_order_traversal[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
