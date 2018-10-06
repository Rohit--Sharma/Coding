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

#define MAX 1000

struct TrieNode {
	TrieNode *children[2];
	TrieNode() {
		for (int i = 0; i < 2; i++)
			children[i] = NULL;
	}
};

void printVector(vector<int> vec) {
	for (int num : vec)
		cout << num << " ";
	cout << "$ ";
}

// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1/?track=SP-Trie
void printMat(int M[MAX][MAX], int row, int col) {
	TrieNode *root = new TrieNode();
	TrieNode *curr;

	for (int i = 0; i < row; i++) {
		vector<int> rowVec;
		curr = root;
		bool isUnique = true;
		for (int j = 0; j < col; j++) {
			rowVec.push_back(M[i][j]);
			if (curr->children[M[i][j]] != NULL) {
				curr = curr->children[M[i][j]];
			}
			else {
				isUnique = false;
				curr->children[M[i][j]] = new TrieNode;
				curr = curr->children[M[i][j]];
			}
		}
		if (!isUnique)
			printVector(rowVec);
	}
}

int main() {
	int row, col;
	row = 3, col = 4;
	int mat[MAX][MAX] = {
		{1, 1, 0, 1}, 
		{1, 0, 0, 1}, 
		{1, 1, 0, 1}
	}; 

	printMat(mat, row, col);

    return 0;
}