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
    int knightDialer(int N) {
        vector<vector<int>> numHops(10, vector<int>(N + 1, -1));

        int res = 0;
        for(int i = 0; i < 10; i++) {
            res += dp(numHops, i, N) % 1000000007;
        }

        return res;
    }

private:
    vector<vector<int>> moves {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};

    int dp(vector<vector<int>>& numHops, int start, int N) {
        // cout << "dp(" << start << ", " << N << ")\n";
        if(numHops[start][N] > 0)
            return numHops[start][N];
        if(N == 1) {
            numHops[start][N] = 1;
            return 1;
        }

        int res = 0;
        for(int next: moves[start]) {
            res += dp(numHops, next, N - 1) % 1000000007;
        }
        numHops[start][N] = res;
        return res;
    }
};

int main() {
    
    cout << "1: " << Solution().knightDialer(1) << endl;

    cout << "2: " << Solution().knightDialer(2) << endl;

    cout << "500: " << Solution().knightDialer(500) << endl;

    return 0;
}
