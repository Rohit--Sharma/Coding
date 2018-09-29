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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode (int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        
        // BFS like algorithm
        queue<TreeLinkNode *> curr_lvl_nodes;
        curr_lvl_nodes.push(root);
        int num_curr_lvl = 1;
        while (!curr_lvl_nodes.empty()) {
            TreeLinkNode *prev = curr_lvl_nodes.front();
            curr_lvl_nodes.pop();
            num_curr_lvl--;
            
            int num_next_lvl = 0;
			if (prev->right != NULL) {
				curr_lvl_nodes.push(prev->right);
				num_next_lvl++;
			}
			if (prev->left != NULL) {
				curr_lvl_nodes.push(prev->left);
				num_next_lvl++;
			}
            
            while (num_curr_lvl--) {
                TreeLinkNode *temp = curr_lvl_nodes.front();
                curr_lvl_nodes.pop();
                
                if (temp->right != NULL) {
                    curr_lvl_nodes.push(temp->right);
                    num_next_lvl++;
                }
                if (temp->left != NULL) {
                    curr_lvl_nodes.push(temp->left);
                    num_next_lvl++;
                }
                
                temp->next = prev;
                prev = temp;
            }
            num_curr_lvl = num_next_lvl;
        }
        
    }
};

int main()
{

    return 0;
}