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

Treeptr insertnode_iterative(Treeptr root, long int val){
	Treeptr pre, temp, new;

	new = (Treeptr)malloc(sizeof(Treenode));
	assert(new != NULL);
	new -> key = val;
	new -> left = NULL;
	new -> right = NULL;
	new -> parent = NULL;
	if(root == NULL)
		return(new);
	temp = root;
	while(temp != NULL){
		pre = temp; 
		if(val <= temp -> key)
			temp = temp -> left;
		else
			temp = temp -> right;
	}
	if(pre -> key >= val){
		pre -> left = new;
		new -> parent = pre;
	}
	else{
		pre -> right = new;
		new -> parent = pre;
	}
	return(root);
}	

Treeptr insertnode(Treeptr root, long int val){
	Treeptr new, temp;
			
	if(root == NULL){
		new = (Treeptr)malloc(sizeof(Treenode));
		assert(new != NULL);
		new -> key = val;
		new -> left = NULL;
		new -> right = NULL;
		new -> parent = NULL;
		return(new);
	}
	temp = root;
	if(temp -> key >= val){
		temp -> left = insertnode(temp -> left, val);
		temp -> left -> parent = temp;
	}
	else{
		temp -> right = insertnode(temp -> right, val);
		temp -> right -> parent = temp;
	}
	return(root);
}
		
