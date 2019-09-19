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
    // O(n^2) time complexity, O(1) space complexity
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            int curr_sum = 0;
            for(int j = i; j < nums.size(); j++) {
                curr_sum += nums[j];
                if(curr_sum == k) {
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> inp {1, 1, 1};
    cout << Solution().subarraySum(inp, 2) << endl;
    
    return 0;
}
