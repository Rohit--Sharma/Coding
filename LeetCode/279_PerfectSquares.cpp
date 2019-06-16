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
	int numSquares(int n) {
		if(n <= 0) {
			return 0;
		}

		vector<int> perfectSquares;
		vector<int> cntPerfectSquares(n);

		queue<int> searchSpace;

		for(int i = 1; i*i <= n; i++) {
			perfectSquares.push_back(i*i);
			cntPerfectSquares[i*i - 1] = 1;
			searchSpace.push(i*i);
		}

		int res = 1;
		if(perfectSquares.back() == n)
			return res;
		
		while(!searchSpace.empty()) {
			int currLevelSize = searchSpace.size();
			res++;

			while(currLevelSize--) {
				int curr = searchSpace.front();
				searchSpace.pop();

				for(int succ: perfectSquares) {
					if(succ + curr == n)
						return res;
					else if(succ + curr < n && cntPerfectSquares[succ + curr - 1] == 0) {
						cntPerfectSquares[succ + curr - 1] = res;
						searchSpace.push(succ + curr);
					}
					else if(succ + curr > n) {
						break;
					}
				}
			}
		}

		return 0;
	}
};

int main() {
	cout << Solution().numSquares(12) << endl;
	cout << Solution().numSquares(13) << endl;
	cout << Solution().numSquares(4) << endl;
	return 0;
}
