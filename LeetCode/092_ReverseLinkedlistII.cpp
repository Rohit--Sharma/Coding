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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(m == n || !head || !head->next)
			return head;
		
		ListNode *prev = NULL, *curr = head;
		int pos = 1;
		// Move till index m
		while(curr && pos < m) {
			pos++;
			prev = curr;
			curr = curr->next;
		}

		// Reverse the list between index m and n
		ListNode *start = prev, *next;
		while(curr && pos <= n) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			pos++;
		}

		// Set all the pointers according to corner cases properly
		if(start) {
			start->next->next = curr;
			start->next = prev;
		}
		else {
			head->next = curr;
			head = prev;
		}

		return head;
	}
};

int main() {
	ListNode* llist = new ListNode(1);
	llist->next = new ListNode(2);
	llist->next->next = new ListNode(3);
	llist->next->next->next = new ListNode(4);
	llist->next->next->next->next = new ListNode(5);
	
	ListNode* res = Solution().reverseBetween(llist, 2, 3);
	while(res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;

	return 0;
}
