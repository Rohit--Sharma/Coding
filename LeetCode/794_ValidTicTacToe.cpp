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
    // # Xs = # Os or # Os + 1
    // If X wins, # Xs = # Os + 1
    // If O wins, # Xs = # Os
    bool validTicTacToe(vector<string>& board) {
        int numX = 0, numO = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 'X')
                    numX++;
                else if(board[i][j] == 'O')
                    numO++;
            }
        }

        if((numX != numO) && (numX != numO + 1)) {
            return false;
        }

        if(isWinState(board, 'X'))
            return numX == numO + 1;
        if(isWinState(board, 'O'))
            return numX == numO;
        
        if((numX == numO) || (numX == numO + 1))
            return true;
        else
            return false;
    }

private:
    bool isWinState(vector<string> board, char player) {
        bool win = false;
        // Check rows
        for(int i = 0; i < 3; i++) {
            win = true;
            for(int j = 0; j < 3; j++) {
                if(board[i][j] != player) {
                    win = false;
                    break;
                }
            }
            if(win)
                return win;
        }

        // Check columns
        for(int i = 0; i < 3; i++) {
            win = true;
            for(int j = 0; j < 3; j++) {
                if(board[j][i] != player) {
                    win = false;
                    break;
                }
            }
            if(win)
                return win;
        }

        // Check diagonal
        win = true;
        for(int i = 0; i < 3; i++) {
            if(board[i][i] != player) {
                win = false;
                break;
            }
        }
        if(win)
            return win;

        // Check anti-diagonal
        win = true;
        for(int i = 0; i < 3; i++) {
            if(board[i][2 - i] != player) {
                win = false;
                break;
            } 
        }

        return win;
    }
};

int main() {

    return 0;
}
