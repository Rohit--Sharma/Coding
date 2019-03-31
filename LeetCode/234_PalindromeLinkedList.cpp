#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
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

// O(n) space
class Solution_Bruteforce {
public:
	bool isPalindrome(ListNode* head) {
		queue<int> my_queue;
		stack<int> my_stack;

		while (head != NULL) {
			my_queue.push(head->val);
			my_stack.push(head->val);
			head = head->next;
		}

		while (!my_stack.empty()) {
			if (my_stack.top() != my_queue.front()) {
				return false;
			}
			my_stack.pop(); 
			my_queue.pop();
		}

		return true;
	}
};

// O(1) space
// Reverse the first half of list by using fast and slow pointers to find the center. Then compare elements on both sides
class Solution {
public:
	bool isPalindrome(ListNode *head) {
		ListNode *prev = NULL, *temp = NULL;
		ListNode *fast = head, *slow  = head;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			temp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = temp;
		}

		// If odd number of nodes
		if (fast != NULL) {
			slow = slow->next;
		}
		while (slow != NULL) {
			if (prev->val != slow->val) {
				return false;
			}
			prev = prev->next;
			slow = slow->next;
		}
		return true;
	}
};

int main() {
	ListNode *inp = new ListNode(1);
	inp->next = new ListNode(2);
	cout << Solution().isPalindrome(inp) << endl;

	inp = new ListNode(1);
	inp->next = new ListNode(2);
	inp->next->next = new ListNode(2);
	inp->next->next->next = new ListNode(1);
	cout << Solution().isPalindrome(inp) << endl;

	return 0;
}
