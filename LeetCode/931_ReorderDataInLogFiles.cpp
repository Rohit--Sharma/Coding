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
		//The order of equal elements is guaranteed to be preserved in stable_sort.
		//Use sort() cannot pass the OJ. 
		stable_sort(logs.begin(), logs.end(), myCompare);
		return logs;
	}

private:
	static bool myCompare(string a, string b){
		int i = a.find(' ');
		int j = b.find(' ');
		if(isdigit(a[i + 1]))
			if(isdigit(b[j + 1]))
				return false;	   // a b are both digit logs, a == b, keep their original order
			else
				return false;	   // a is digit log, b is letter log, a > b
		else
			if(isdigit(b[j + 1]))
				return true;		// a is letter log, b is digit log, a < b
			else {
				if (a.substr(i) == b.substr(j))
					return a.substr(0,i) < b.substr(0,j); //If string part is the same, compare key
				else
					return a.substr(i) < b.substr(j);   // a and b are both letter
			}
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
