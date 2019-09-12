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
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> rotten;
		int num_fresh = 0;
		for(int i = 0; i < grid.size(); i++) {
			for(int j = 0; j < grid[0].size(); j++) {
				if(grid[i][j] == 1)
					num_fresh++;
				else if(grid[i][j] == 2) {
					rotten.push({i, j});
				}
			}
		}

		vector<int> dir_r {1, 0, -1, 0};
		vector<int> dir_c {0, 1, 0, -1};

		int tot_min = 0;

		while(!rotten.empty() && num_fresh > 0) {
			tot_min++;
			int curr_size = rotten.size();
			for(int i = 0; i < curr_size; i++) {
				pair<int, int> curr = rotten.front();
				rotten.pop();

				for(int dir = 0; dir < 4; dir++) {
					int next_r = curr.first + dir_r[dir];
					int next_c = curr.second + dir_c[dir];

					if(next_r >= 0 && next_r < grid.size() && next_c >= 0 && next_c < grid[0].size()) {
						if(grid[next_r][next_c] == 1) {
							grid[next_r][next_c] = 2;
							rotten.push({next_r, next_c});
							num_fresh--;
						}
					}
				}
			}
		}

		return num_fresh > 0 ? -1 : tot_min;
	}
};

int main() {
	vector<vector<int>> inp1 {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
	cout << Solution().orangesRotting(inp1) << endl;

	vector<vector<int>> inp2 {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
	cout << Solution().orangesRotting(inp2) << endl;

	vector<vector<int>> inp3 {{0, 2}};
	cout << Solution().orangesRotting(inp1) << endl;

	return 0;
}
