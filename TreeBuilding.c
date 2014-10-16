#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
} node;

char label[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H'};
int leftChildren[] = {1, 3, 5, -1, 9, -1 , -1, -1, -1, -1};
int rightChildren[] = {2, 4, 6, -1, -1 , -1, -1, -1, -1, -1};

void inorder(node *rt)
{
	if (rt != NULL) {
		inorder(rt->left);
		printf("%c ", rt->data);
		inorder(rt->right);
	}
}

node *buildTree(int i)
{
	node *temp = NULL;
	if (i != -1) {
		temp = malloc(sizeof(node));
		temp->data = label[i];
		temp->left = buildTree(leftChildren[i]);
		temp->right = buildTree(rightChildren[i]);
	}
	return temp;
}

int main (int argc, char *argv[])
{
	node *root = buildTree(0);
	
	printf("Inorder Traversal: ");
	inorder(root);
	printf("\n");
	
	return 0;
}
