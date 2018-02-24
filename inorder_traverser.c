#include <stdio.h>

typedef struct node * Treeptr;

typedef struct node{
	long int key;
	Treeptr left;
	Treeptr right;
	Treeptr parent;
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

void inorder(Treeptr root){
	
	if(root == NULL)
		return;
	else{
		inorder(root -> left);
		printf("%ld\t", root -> key);
		inorder(root -> right);
	}
	return;
}

void inorder_iterative(Treeptr root){
	Treeptr new;
	
	top = 0;
	if(root == NULL)
		return;
	else
		pushnode(NULL);
	new = root;
lable1:	while(new != NULL){
		pushnode(new);
		new = new -> left;
	}
	new = popnode();
	while(new != NULL){
		printf("%ld\t", new -> key);
		if(new -> right != NULL){
			new = new -> right;
			goto lable1;
		}
		new = popnode();
	}
	return;
}

void inorder_interative2(Treeptr root){
     Treeptr new;
     
     if(root == NULL){
             printf("Tree not present");
     }
     new = root;
     while(new != NULL){
               pushnode(new);
               new = new -> left;
     }
     while(top > 0){
               new = pop();
               printf("%d", new -> data);
               if(new -> right != NULL){
                      new = new -> right;
                      while(new != NULL){
                                pushnode(new);
                                new = new -> left;
                      }
               }
     }
             		
	
