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

// First find all the gates, then expand the whole rooms array outwards from each gate.
class SolutionBruteForce {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		vector<vector<int>> gate_locations = getGateLocs(rooms);

		for(auto gate_loc: gate_locations) {
			expand(rooms, gate_loc);
		}
	}

private:
	int INF = 2147483647;
	vector<int> succ_r {-1, 0, 1, 0};
	vector<int> succ_c {0, 1, 0, -1};

	vector<vector<int>> getGateLocs(vector<vector<int>> rooms) {
		vector<vector<int>> gate_locations;
		for(int i = 0; i < rooms.size(); i++) {
			for(int j = 0; j < rooms[i].size(); j++) {
				if(rooms[i][j] == 0) {
					vector<int> curr_loc {i, j};
					gate_locations.push_back(curr_loc);
				}
			}
		}
		return gate_locations;
	}

	// BFS to expand all the nodes around the gate root
	void expand(vector<vector<int>> &rooms, vector<int> root) {
		queue<vector<int>> search_space;
		set<vector<int>> visited;
		int dist = -1;
		search_space.push(root);
		visited.insert(root);
		while(!search_space.empty()) {
			dist++;
			int size = search_space.size();
			for(int i = 0; i < size; i++) {
				vector<int> curr = search_space.front();
				if(rooms[curr[0]][curr[1]] != -1 || rooms[curr[0]][curr[1]] != 0) {
					rooms[curr[0]][curr[1]] = min(rooms[curr[0]][curr[1]], dist);

					// add successors to queue
					for(int j = 0; j < 4; j++) {
						if(curr[0] + succ_r[j] >= 0 && curr[0] + succ_r[j] < rooms.size() && curr[1] + succ_c[j] >= 0 && curr[1] + succ_c[j] < rooms[0].size()) {
							if(rooms[curr[0] + succ_r[j]][curr[1] + succ_c[j]] != -1 && rooms[curr[0] + succ_r[j]][curr[1] + succ_c[j]] != 0) {
								vector<int> succ {curr[0] + succ_r[j], curr[1] + succ_c[j]};
								if (visited.find(succ) == visited.end()) {
									search_space.push(succ);
									visited.insert(succ);
								}
							}
						}
					}
				}
				search_space.pop();
			}
		}
	}
};

// More compact implementation of the above approach: Expand outwards from each gate at once
class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		int m = rooms.size();
		if(m == 0) return;
		int n = rooms[0].size();
		queue<vector<int>> search_space;

		// Push all the gates locations in the search space (open list) of the queue so that each iteration of bfs expands all the queues at once. 
		//   Therefore, one pass should be able to fill in the rooms array.
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(rooms[i][j] == 0) {
					search_space.push(vector<int> {i, j});
				}
			}
		}

		while(!search_space.empty()) {
			vector<int> curr = search_space.front();
			search_space.pop();
			for(int dir = 0; dir < 4; dir++) {
				int r = curr[0] + succ_r[dir];
				int c = curr[1] + succ_c[dir];
				// We only need one pass, so we can directly compare with INF. Also because of this, we don't need to maintain which nodes are visited.
				if(r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != INF)
					continue;
				rooms[r][c] = rooms[curr[0]][curr[1]] + 1;
				search_space.push(vector<int> {r, c});
			}
		}
	}

private:
	int INF = 2147483647;
	vector<int> succ_r {-1, 0, 1, 0};
	vector<int> succ_c {0, 1, 0, -1};
};

int main() {
	int INF = 2147483647;
	vector<vector<int>> rooms {{INF, -1, 0, INF}, {INF, INF, INF, -1}, {INF, -1, INF, -1}, {0, -1, INF, INF}};
	Solution().wallsAndGates(rooms);
	// cout << endl;
	for(int i = 0; i < rooms.size(); i++) {
		for(int j = 0; j < rooms[i].size(); j++) {
			cout << rooms[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
