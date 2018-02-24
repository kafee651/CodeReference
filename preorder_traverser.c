/*Preorder Traverser 
*/

#include <stdio.h>

typedef struct node * Treeptr;

typedef struct node{
	long int key;
	Treeptr left;
	Treeptr right;
}Treenode;

Treeptr s[100];
int top = 0;

void pushnode(Treeptr node){
	
	s[++top] = node;
	return;
}

Treeptr popnode(){
	
	return(s[top--]);
}

void preorder(Treeptr root){
	
	if(root == NULL)
		return;
	else{
		printf("%ld\t", root -> key);
		preorder(root -> left);
		preorder(root -> right);
	}
	return;
}

void preorder_iterative(Treeptr root){
	Treeptr new;
	
	top = 0;
	if(root == NULL){
		printf("\nEmpty Tree");
		return;
	}
	pushnode(root);
	while(top > 0){
		new = popnode();
		while(new != NULL){
			printf("%ld\t", new -> key);
			if(new -> right != NULL)
				pushnode(new -> right);
			new = new -> left;
		}
	}
	return;
}
