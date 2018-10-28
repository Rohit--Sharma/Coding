#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// A helper method which returns 'n'th ancestor of node 'node' in the parent vector
int helper_get_nth_ancestor(vector<int> parent, vector<vector<int>> &ancestors_dp, int node, int n)
{
    int ancestor = -1;
    if (ancestors_dp[node][n] != -1)
        return ancestors_dp[node][n];
    
    int n_1th_ancestor = helper_get_nth_ancestor(parent, ancestors_dp, parent[node], n - 1);
    ancestors_dp[parent[node]][n - 1] = n_1th_ancestor;
    return n_1th_ancestor;
}

// Google interview Question
// Parent vector stores the index of parent node for each node.
//    Returns a vector of dth ancestor of every node with an index in the parent vector
vector<int> dth_ancestor(vector<int> parent, int d)
{
    vector<int> result;
    vector<vector<int>> ancestors_dp(parent.size(), vector<int>(d + 1, -1));
    for (int i = 0; i < parent.size(); i++) 
        ancestors_dp[i][1] = parent[i];
    
    for (int i = 0; i < parent.size(); i++) {
        if (ancestors_dp[i][d] != -1) 
            result.push_back(ancestors_dp[i][d]);
        else
            result.push_back(helper_get_nth_ancestor(parent, ancestors_dp, i, d));
    }
    return result;
}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
 * Bruteforce
 */
/*
int dth_ancestor(int node, int D, vector<int> A) {
    for (int i = 0; i < D; i++) {
        if (A[node] == -1)
            return -1;
        node = A[node];
    }
    return node;
}

vector<int> solution(int D, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result;
    for (unsigned int i = 0; i < A.size(); i++) {
        result.push_back(dth_ancestor(i, D, A));
    }    
    return result;
}
*/

// DP approach

int store_nth_ancestor_and_return(vector<int> A, vector<vector<int>> &dp, int node, int n) {
    if (dp[node][n] != -2) {
        return dp[node][n];
    }
    
    if (A[node] == -1) {
        dp[node][n] = -1;
        return -1;
    }
    
    int res = store_nth_ancestor_and_return(A, dp, A[node], n - 1);
    dp[A[node]][n - 1] = res;
    return res;
}

vector<int> solution(int D, vector<int> &A) {
    vector<int> result;
    
    vector<vector<int>> dp(A.size(), vector<int>(D + 1, -2));
    for (unsigned int i = 0; i < A.size(); i++) {
        dp[i][1] = A[i];
        if (A[i] == -1) {
            for (unsigned int j = 2; (int)j < D + 1; j++) {
                dp[i][j] = -1;
            }    
        }
    }
    
    for (unsigned int i = 0; i < A.size(); i++) {
        //cout << dp[i][D] << endl;
        if (dp[i][D] != -2) {
            result.push_back(dp[i][D]);
        }
        else {
            result.push_back(store_nth_ancestor_and_return(A, dp, i, D));
        }
    }
    
    return result;
}

int main()
{
    vector<int> input {1, 3, 4, 5, 7, 3, 7, 5, 2, 1};
    vector<int> dth_ancestors = dth_ancestor(input, 2);
    for (int ancestor : dth_ancestors)
        cout << ancestor << " ";
    cout << endl;
    return 0;
}