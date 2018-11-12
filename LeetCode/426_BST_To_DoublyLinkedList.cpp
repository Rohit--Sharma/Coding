#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        
        Node *dummy = new Node(-1, NULL, NULL);
        head = dummy;
        inOrderTraversal(root);
        
        head->right = dummy->right;
        dummy->right->left = head;
        
        head = dummy->right;
        return head;
    }
    
private:
    Node *head = NULL;
    void inOrderTraversal(Node *root) {
        if (root == NULL)
            return;
        
        inOrderTraversal(root->left);
        
        head->right = root;
        head->right->left = head;
        head = head->right;
        
        inOrderTraversal(root->right);
    }
};

int main() {

    return 0;
}
