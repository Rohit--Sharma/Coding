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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size() == 0) {
			return nullptr;
		}

		TreeNode *root = new TreeNode(preorder[0]);
		if(preorder.size() == 1) {
			return root;
		}

		vector<int> left_sub_inorder, right_sub_inorder;
		splitInorderList(inorder, preorder[0], left_sub_inorder, right_sub_inorder);
		vector<int> left_sub_preorder, right_sub_preorder;
		for(int i = 1; i < preorder.size(); i++) {
			if(i <= left_sub_inorder.size()) {
				left_sub_preorder.push_back(preorder[i]);
			}
			else {
				right_sub_preorder.push_back(preorder[i]);
			}
		}
		root->left = buildTree(left_sub_preorder, left_sub_inorder);
		root->right = buildTree(right_sub_preorder, right_sub_inorder);
		return root;
	}

private:
	void splitInorderList(vector<int>& traversal, int val, vector<int>& left_half, vector<int>& right_half) {
		bool insert_left = true;
		for(int i = 0; i < traversal.size(); i++) {
			if(insert_left && traversal[i] != val) {
				left_half.push_back(traversal[i]);
			}
			else if(traversal[i] == val) {
				insert_left = false;
				continue;
			}
			else if(!insert_left) {
				right_half.push_back(traversal[i]);
			}
		}

	}
};

int main() {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	TreeNode *root = Solution().buildTree(preorder, inorder);
	return 0;
}
