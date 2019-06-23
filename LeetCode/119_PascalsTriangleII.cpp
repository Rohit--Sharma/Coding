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
	vector<int> getRow(int rowIndex) {
		pascal = vector<vector<int>>(rowIndex + 1, vector<int>(rowIndex + 1, -1));

		for(int j = 0; j <= rowIndex; j++) {
			get_pascal(rowIndex, j);
		}

		return pascal[rowIndex];
	}

private:
	vector<vector<int>> pascal;

	void get_pascal(int i, int j) {
		if(pascal[i][j] != -1)
			return;
		if(j == 0 || i == j) {
			pascal[i][j] = 1;
			return;
		}
		get_pascal(i - 1, j - 1);
		get_pascal(i - 1, j);
		pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
	}
};


int main() {
	vector<int> res = Solution().getRow(22);

	cout << "Res: ";
	for(int i = 0; i < res.size(); i++) 
		cout << res[i] << " ";
	cout << endl;

	return 0;
}


		// for(int i = 0; i < pascal.size(); i++) {
		// 	for(int j = 0; j < pascal[i].size(); j++) {
		// 		cout << pascal[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }