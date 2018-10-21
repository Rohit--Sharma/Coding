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

int main()
{
    vector<int> input {1, 3, 4, 5, 7, 3, 7, 5, 2, 1};
    vector<int> dth_ancestors = dth_ancestor(input, 2);
    for (int ancestor : dth_ancestors)
        cout << ancestor << " ";
    cout << endl;
    return 0;
}