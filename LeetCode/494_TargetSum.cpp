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
	int findTargetSumWays(vector<int>& nums, int S) {
		if(nums.size() == 0)
			return 0;
		
		int res = 0;
		int curr_sum = 0;
		findTargetSumWays(nums, S, 0, res, curr_sum);
		return res;
	}

private:
	vector<int> operators{-1, 1};

	void findTargetSumWays(vector<int>& nums, int S, int idx, int& accumulator, int& curr_sum) {
		if(idx == nums.size()) {
			if(curr_sum == S)
				accumulator++;
		}

		
	}
};

int main() {

	return 0;
}
