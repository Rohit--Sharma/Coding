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
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++)
        {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++)
            {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end())
                {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else
                    break;
            }
            if (j == num)
                indexes.push_back(i);
        }
        return indexes;
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
