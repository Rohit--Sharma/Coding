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

// Bruteforce
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		return checkRows(board) && checkCols(board) && checkSubGrids(board);
	}

private:
	bool checkRows(vector<vector<char>> board) {
		for(int r = 0; r < board.size(); r++) {
			vector<int> vals(10);
			for(int c = 0; c < board[r].size(); c++) {
				if(board[r][c] != '.') {
					vals[board[r][c] - '0']++;
					if(vals[board[r][c] - '0'] > 1)
						return false;
				}
			}
		}
		return true;
	}

	bool checkCols(vector<vector<char>> board) {
		for(int c = 0; c < board[0].size(); c++) {
			vector<int> vals(10);
			for(int r = 0; r < board.size(); r++) {
				if(board[r][c] != '.') {
					vals[board[r][c] - '0']++;
					if(vals[board[r][c] - '0'] > 1)
						return false;
				}
			}
		}
		return true;
	}

	bool checkSubGrids(vector<vector<char>> board) {
		vector<int> start {0, 3, 6};
		for(int i = 0; i < start.size(); i++) {
			for(int j = 0; j < start.size(); j++) {
				vector<int> vals(10);
				for(int r = start[i]; r < start[i] + 3; r++) {
					for(int c = start[j]; c < start[j] + 3; c++) {
						if(board[r][c] != '.') {
							vals[board[r][c] - '0']++;
							if(vals[board[r][c] - '0'] > 1)
								return false;
						}
					}
				}
			}
		}
		return true;
	}
};

// Another amazing technique
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		set<string> seen;
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[i].size(); j++) {
				char curr = board[i][j];
				if(curr != '.') {
					if(seen.find(string(1, curr) + " in row " + string(1, i + '0')) != seen.end() || seen.find(string(1, curr) + " in col " + string(1, j + '0')) != seen.end() || seen.find(string(1, curr) + " in grid " + string(1, i/3 + '0') + "-" + string(1, j/3 + '0')) != seen.end()) {
						return false;
					}
					seen.insert(string(1, curr) + " in row " + string(1, i + '0'));
					seen.insert(string(1, curr) + " in col " + string(1, j + '0'));
					seen.insert(string(1, curr) + " in grid " + string(1, i/3 + '0') + "-" + string(1, j/3 + '0'));
				}
			}
		}
		return true;
	}
};

int main() {

	return 0;
}
