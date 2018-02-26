#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
} node;

typedef struct hashtable {
	int size;
	node **table;
} hashtable;

hashtable *hashTable = NULL;

node *createNode()
{
	node *newNode = (node *) malloc(sizeof(node));
	newNode->data = 0;
	return newNode;
}

void build(int n)
{
	hashTable->table = (node **)malloc(sizeof(node *) * n);
	
	for (int i = 0; i < n; i += 1) {
		node *newNode = createNode();
		newNode->data = i;
		hashTable->table[i] = newNode;
	}
}

void display(int n)
{
	for (int i = 0; i < n; i += 1) {
		printf("%d:", i);
		node *temp = hashTable->table[i];
		while (temp != NULL) {
			printf(" %d", temp->data);
			temp = temp->next;
		}
		putchar('\n');
	}
}

void move(string operation, int x, int y)
{
	int swtch = (operation == "over") ? 1 : 2;
	switch (swtch) {
		case 1: {
			
			break;
		}
		case 2: {
			
			break;
		}
	}
	return;
}

void pile(string operation, int x, int y)
{
	int swtch = (operation == "over") ? 1 : 2;
	switch (swtch) {
		case 1: {
			
			break;
		}
		case 2: {
			
			break;
		}
	}
	return;
}

int main (int argc, char const* argv[])
{
	int n; scanf("%d", &n);
	
	hashTable = (hashtable *)malloc(sizeof(hashtable));
	
	build(n);
	
	string command; cin >> command;
	int swtch = (command == "move") ? 1 : 2;
	while (command != "quit") {
		int a, b;
		string subCommand;
		switch (swtch) {
			case 1: {
				scanf("%d", &a);
				cin >> subCommand;
				scanf("%d", &b);
				move(subCommand, a, b);
				break;
			}
			case 2: {
				scanf("%d", &a);
				cin >> subCommand;
				scanf("%d", &b);
				pile(subCommand, a, b);
				break;
			}
		}
		cin >> command;
	}
	
	display(n);
	
	return 0;
}
