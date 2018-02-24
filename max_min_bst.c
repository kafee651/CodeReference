#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node * Treeptr;

typedef struct node{
	long int key;
	Treeptr left;
	Treeptr right;
	Treeptr parent;
}Treenode;

long int tree_min(Treeptr root){
	
	while(root -> left != NULL)
		root = root -> left;
	return(root -> key);
}

long int tree_max(Treeptr root){
	
	while(root -> right != NULL)
		root = root -> right;
	return(root -> key);
}
