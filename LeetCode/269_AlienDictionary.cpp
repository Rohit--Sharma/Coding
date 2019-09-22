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
    string alienOrder(vector<string>& words) {
        if(words.size() == 0)
            return "";
        if(words.size() == 1)
            return words[0];

        unordered_map<char, vector<char>> adj_list;
        unordered_map<char, bool> visited;

        // Keeping track of recursion stack of nodes to detect a cycle if 
        //   there is a back edge to one of the nodes already in rec stack.
        unordered_map<char, bool> rec_stack;

        for(string word: words)
            for(char ch: word) {
                visited[ch] = false;
                rec_stack[ch] = false;
            }

        for(int i = 1; i < words.size(); i++) {
            for(int idx = 0; idx < min(words[i - 1].size(), words[i].size()); idx++) {
                if(words[i - 1][idx] != words[i][idx]) {
                    if(adj_list.find(words[i - 1][idx]) == adj_list.end())
                        adj_list[words[i - 1][idx]] = vector<char>();
                    adj_list[words[i - 1][idx]].push_back(words[i][idx]);

                    // No need to compare the rest of the characters, only first mismatch is important
                    break;
                }
            }
        }

        // TODO: Can this step be optimized together with topoligical sort?
        // * Handle the corner case when the input is invalid due to a cycle.
        if(is_cyclic(adj_list, visited, rec_stack)) {
            return "";
        }

        // Reset visited to false
        for(string word: words)
            for(char ch: word)
                visited[ch] = false;

        for(auto it = visited.begin(); it != visited.end(); it++)
            if(!it->second)
                topological_sort(adj_list, it->first, visited);

        string res;
        while(!order.empty()) {
            res += order.top();
            order.pop();
        }
        return res;
    }

private:
    stack<char> order;

    // * Inspired from https://www.geeksforgeeks.org/topological-sorting/
    void topological_sort(unordered_map<char, vector<char>> adj_list, char root, unordered_map<char, bool> &visited) {
        visited[root] = true;
        for(char successor: adj_list[root])
            if(!visited[successor])
                topological_sort(adj_list, successor, visited);
        order.push(root);
    }

    bool is_cyclic_helper(unordered_map<char, vector<char>> adj_list, char node, unordered_map<char, bool> &visited, unordered_map<char, bool> &rec_stack) {
        if(!visited[node]) {
            visited[node] = true;
            rec_stack[node] = true;

            for(char successor: adj_list[node]) {
                if(!visited[successor] && is_cyclic_helper(adj_list, successor, visited, rec_stack))
                    return true;
                else if(rec_stack[successor])
                    return true;
            }
        }

        // Current node traversed. Remove it from recursion stack
        rec_stack[node] = false;
        return false;
    }

    // * Inspired from https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    bool is_cyclic(unordered_map<char, vector<char>> adj_list, unordered_map<char, bool> &visited, unordered_map<char, bool> &rec_stack) {
        for(auto it = visited.begin(); it != visited.end(); it++)
            if(is_cyclic_helper(adj_list, it->first, visited, rec_stack))
                return true;

        return false;
    }
};

int main() {
    vector<string> words {"wrt", "wrf", "er", "ett", "rftt"};
    cout << Solution().alienOrder(words) << endl;

    words = vector<string> {"w", "x"};
    cout << Solution().alienOrder(words) << endl;

    words = vector<string> {"z", "x", "z"};
    cout << Solution().alienOrder(words) << endl;

    return 0;
}
