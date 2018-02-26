#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;


void insert(node **root, int val)
{
	node *temp = (node *)malloc(sizeof(node));
	(temp)->left = NULL;
	(temp)->right = NULL;
	(temp)->data = val;
	
	if (*root == NULL) {
		*root = temp;
	} else if (((*root)->data >= val) && ((*root)->left == NULL)) {
		(*root)->left = temp;
	} else if (((*root)->data >= val) && ((*root)->left != NULL)) {
		insert(&((*root)->left), val);
	} else if (((*root)->data < val) && ((*root)->right == NULL)) {
		(*root)->right = temp;
	} else if (((*root)->data < val) && ((*root)->right != NULL)) {
		insert(&((*root)->right), val);
	}
}

void inorder(node *root)
{
	if (root == NULL) {
		return;
	} else {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if (root == NULL) {
		return;
	} else {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if (root == NULL) {
		return;
	} else {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

node *Root = NULL;

int main (int argc, char const* argv[])
{
	cout << "Enter the size of BST: ";
	int n; cin >> n;
	
	int temp;
	for (unsigned int i = 0; i < n; i += 1) {
		cin >> temp;
		insert(&Root, temp);
	}
	
	cout << "In-order traversal: ";
	inorder(Root);
	cout << endl << "Pre-order traversal: ";
	preorder(Root);
	cout << endl << "Post-order traversal: ";
	postorder(Root);
	cout << endl;
	
	return 0;
}
