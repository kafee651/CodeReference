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

void pushnode(Treeptr root);
Treeptr popnode();

void postorder(Treeptr root){
	
	if(root == NULL)
		return;
	else{
		inorder(root -> left);
		inorder(root -> right);
		printf("%ld\t", root -> key);
	}
	return;
}

void postorder_iterative(Treeptr root){
	Treeptr new;
	int count;

	top = 0;
	if(root == NULL)
		return;
	new = root;
lable1:	while(new != NULL){
		count = 1;
		if(new -> right != NULL)
			count = -1;
		pushnode(count * (new -> right));
		new = new -> left;
	}
lable2:	new = popnode();
	if(new < 0)
		pushnode( -1 * new);
		new = -new;
		new = new - > right;
		goto lable1;
	}
	else if(new != NULL){
		printf("%ld", new -> key);
		goto lable2;
	}
	return;
}
			
	
