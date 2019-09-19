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

// Time limit exceeded
// Time complexity: O(n^2)?
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        size_t n_words = words.size();
        if(n_words == 0)
            return result;

        size_t len = words[0].size();

        for(string word: words)
            word_counts[word]++;

        for(int i = 0; i < s.size(); i++) {
            cout << "i: " << i << endl;
            string curr = s.substr(i, len);
            if(word_counts.find(curr) != word_counts.end()) {
                unordered_map<string, int> word_cts_copy(word_counts);
                int n = n_words;
                int j = i;

                string w = curr;
                bool found = true;
                while(word_cts_copy.find(w) != word_cts_copy.end()) {
                    cout << w << " ";
                    word_cts_copy[w]--;
                    if(word_cts_copy[w] < 0) {
                        found = false;
                        break;
                    }

                    n--;
                    if(n == 0)
                        break;

                    j += len;
                    w = s.substr(j, len);
                }
                cout << endl;

                if(n == 0 && found)
                    result.push_back(i);
            }
        }

        return result;
    }

private:
    unordered_map<string, int> word_counts;
};

int main() {
    string s = "barfoofoobarthefoobarman";
    vector<string> words {"bar", "foo", "the"};

    vector<int> res = Solution().findSubstring(s, words);
    for(int idx: res)
        cout << idx << " ";
    cout << endl;

    return 0;
}
