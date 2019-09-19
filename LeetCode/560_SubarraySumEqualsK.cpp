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

class Solution_Optimal {
public:
    // Instead of iterating everytime on j, we can store the 
    //   cumulative sums. For each index, if the cumulative sum at that 
    //   index is sum[i], and if we have already cumulative sum seen sum[i] - k before, 
    //   that means between the index when we saw sum[i] - k and i, the subarray sum is k.
    //   We can store how many times we saw each cumulative sum in a map
    // Time complexity: O(n), Space complexity: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        unordered_map<int, int> cum_sum_counts {{0, 1}};
        int cum_sum = 0;

        for(int num: nums) {
            cum_sum += num;

            if(cum_sum_counts.find(cum_sum - k) != cum_sum_counts.end())
                res += cum_sum_counts[cum_sum - k];

            if(cum_sum_counts.find(cum_sum) == cum_sum_counts.end())
                cum_sum_counts[cum_sum] = 0;
            cum_sum_counts[cum_sum]++;
        }

        return res;
    }
};

int main() {
    vector<int> inp {1, 1, 1};
    cout << Solution().subarraySum(inp, 2) << endl;
    
    return 0;
}
