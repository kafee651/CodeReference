#include <stdio.h>

typedef struct node * Treeptr;

typedef struct node{
	long int key;
	char color;
	Treeptr left;
	Treeptr right;
	Treeptr parent;
}Treenode;

Treeptr Tnil;

Tnil = (Treeptr)malloc(sizeof(Treenode));

Tnil -> key = 0;
Tnil -> color = 'B';
Tnil -> left = NULL;
Tnil -> right = NULL;
Tnil -> parent = NULL;
