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
    int openLock(vector<string>& deadends, string target) {
		set<string> deadends_set;
		set<string> visited;
		for(string deadend: deadends) {
			deadends_set.insert(deadend);
		}

		// BFS over the set of states expanding to next one in each iteration
		queue<string> states;
		states.push("0000");
		visited.insert("0000");

		int res = 0;
		int prev_level_size = 1;
		while(!states.empty()) {
			int curr_level_size = 0;
			while(prev_level_size--) {
				string curr_state = states.front();
				states.pop();
				if(curr_state == target) {
					return res;
				}
				if(deadends_set.find(curr_state) != deadends_set.end()) {
					continue;
				}
				// cout << res << endl;
				// generate successors and add to the queue
				vector<string> successors = get_successors(curr_state);
				for(string succ: successors) {
					if(visited.find(succ) == visited.end()) {
						// cout << succ << endl;
						states.push(succ);
						visited.insert(succ);
						curr_level_size++;
					}
				}
			}
			res++;
			prev_level_size = curr_level_size;
		}

        return -1;
    }

private:
	vector<string> get_successors(string state) {
		vector<string> successors;
		for(int i = 0; i < state.size(); i++) {
			string curr = state;
			if(curr[i] == '0') {
				string succ_1 = curr;
				succ_1[i] = '9';
				string succ_2 = curr;
				succ_2[i] = '1';
				successors.push_back(succ_1);
				successors.push_back(succ_2);
			}
			else if(curr[i] == '9') {
				string succ_1 = curr;
				succ_1[i] = '8';
				string succ_2 = curr;
				succ_2[i] = '0';
				successors.push_back(succ_1);
				successors.push_back(succ_2);
			}
			else {
				string succ_1 = curr;
				succ_1[i]++;
				string succ_2 = curr;
				succ_2[i]--;
				successors.push_back(succ_1);
				successors.push_back(succ_2);
			}
		}
		return successors;
	}
};

int main() {
	vector<string> deadends {"0201","0101","0102","1212","2002"};
	string target = "0202";
	cout << Solution().openLock(deadends, target) << endl;

	deadends = vector<string> {"8888"};
	target = "0009";
	cout << Solution().openLock(deadends, target) << endl;

	deadends = vector<string> {"8887","8889","8878","8898","8788","8988","7888","9888"};
	target = "8888";
	cout << Solution().openLock(deadends, target) << endl;

	deadends = vector<string> {"0000"};
	target = "8888";
	cout << Solution().openLock(deadends, target) << endl;

	deadends = vector<string> {};
	target = "1234";
	cout << Solution().openLock(deadends, target) << endl;

	return 0;
}
