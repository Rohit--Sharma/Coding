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
    // Bottom up DP
    // Time complexity: O(n), Space complexity: O(1)
    int knightDialer(int N) {
        int MOD = 1000000007;

        // dp for only two previous n values to optimize space.
        //   use bitwise operations to access values in each iter
        int dp[2][10];
        for(int i = 0; i < 10; i++)
            dp[0][i] = 1;
        
        for(int hop = 0; hop < N - 1; hop++) {
            for(int i = 0; i < 10; i++)
                dp[~hop & 1][i] = 0;
            
            for(int i = 0; i < 10; i++) {
                for(int next: moves[i]) {
                    dp[~hop & 1][next] += dp[hop & 1][i];
                    dp[~hop & 1][next] %= MOD;
                }
            }
        }

        long ans = 0;
        for(int nhops: dp[~N & 1])
            ans += nhops;
        return ans % MOD;
    }

private:
    vector<vector<int>> moves {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
};

int main() {
    
    cout << "1: " << Solution().knightDialer(1) << endl;

    cout << "2: " << Solution().knightDialer(2) << endl;

    cout << "5000: " << Solution().knightDialer(5000) << endl;

    return 0;
}
