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
#include <sstream>

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
	vector<string> reorderLogFiles(vector<string>& logs) {
		sort(logs.begin(), logs.end(), comparator);
		return logs;
	}

private:
	static bool is_digit_log(string word) {
		for(char ch: word)
			if(ch < '0' || ch > '9')
				return false;
		return true;
	}

	static bool comparator(string log1, string log2) {
		vector<string> log1_tokens = split(log1, ' ');
		vector<string> log2_tokens = split(log2, ' ');

		bool is_log1_digit = is_digit_log(log1_tokens[1]);
		bool is_log2_digit = is_digit_log(log2_tokens[1]);

		if((is_log1_digit && is_log2_digit) || is_log2_digit) {
			return true;
		} else if(is_log1_digit) {
			return false;
		} else {
			string log1_less_id, log2_less_id;

			for(int i = 1; i < log1_tokens.size(); i++) {
				log1_less_id += log1_tokens[i];
			}
			for(int i = 1; i < log2_tokens.size(); i++) {
				log2_less_id += log2_tokens[i];
			}
			cout << log1_less_id << " " << log2_less_id << ' ';

			if(log1_less_id.compare(log2_less_id) == 0) {
				cout << log2.compare(log1) << endl;
				return log2.compare(log1);
			} else {
				cout << log2_less_id.compare(log1_less_id) << endl;
				return log2_less_id.compare(log1_less_id);
			}
		}
	}

	template<typename Out>
	static void split(string& s, char delim, Out result) {
		stringstream ss(s);
		string item;
		while(getline(ss, item, delim))
			*(result++) = item;
	}

	static vector<string> split(string& s, char delim) {
		vector<string> tokens;
		split(s, delim, back_inserter(tokens));
		return tokens;
	}
};

int main() {
	vector<string> logs {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
	vector<string> sorted = Solution().reorderLogFiles(logs);
	for(string sorted_log: sorted) {
		cout << sorted_log << ", ";
	}
	cout << endl;

	return 0;
}
