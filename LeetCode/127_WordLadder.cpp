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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // If endWord not in wordList, return 0
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        queue<string> frontier;
        frontier.push(beginWord);

        int res = 0;
        while(!frontier.empty()) {
            res++;
            int size = frontier.size();
            while(size--) {
                string curr = frontier.front();
                frontier.pop();
                visited[curr] = true;
                if(curr == endWord)
                    return res;
                for(string successor: successors(curr, wordList)) {
                    frontier.push(successor);
                }
            }
        }
        return res;
    }

private:
    unordered_map<string, bool> visited;

    vector<string> successors(string curr_state, vector<string> wordList) {
        vector<string> succ;
        for(string word: wordList) {
            if(visited.find(word) == visited.end()) {
                int dist = 0;
                for(int i = 0; i < word.size(); i++) {
                    if(curr_state[i] != word[i])
                        dist++;
                    
                    if(dist > 1)
                        break;
                }
                if(dist == 1)
                    succ.push_back(word);
            }
        }
        return succ;
    }
};

int main() {
    string begin = "hit";
    string end = "dog";
    vector<string> word_list {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(begin, end, word_list) << endl;
    
    return 0;
}
