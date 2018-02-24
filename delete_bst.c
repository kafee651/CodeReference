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

Treeptr transplant(Treeptr root, Treeptr u, Treeptr v){

	if(u -> parent == NULL)
		root = v;
	else if(u == u -> parent -> left)
		u -> parent -> left = v;
	else 
		u -> parent -> right = v;
	if(v != NULL)
		v -> parent = u -> parent;
	return(root);
}


Treeptr deletenode(Treeptr root, long int val){
	Treeptr del, replace;
	
	del = tree_search(root, val);
	if(del -> left == NULL){
		root = transplant(root, del, del -> right);
	}
	else if(del -> right == NULL)
		root = transplant(root, del, del -> left);
	else {
		replace = tree_min(del -> right);
		if(replace -> parent != del){
			root = transplant(root, replace, replace -> right);
			replace -> right = del -> right;
			replace -> right -> parent = replace;
		}
		root = transplant(root, del, replace);
		replace -> left = del -> left;
		replace -> left -> parent = replace;
	}
	return(root);
}
