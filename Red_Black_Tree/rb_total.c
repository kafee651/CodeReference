#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node * Treeptr;

typedef struct node{
	long int key;
	char color;
	Treeptr left;
	Treeptr right;
	Treeptr parent;
}Treenode;

Treeptr Tnil;


Treeptr rb_inorder_traverser(Treeptr root, Treeptr z){
	
	if(z == Tnil)
		return(root);
	root = rb_inorder_traverser(root, z -> left);
	printf("%ld\t", z -> key);
	root = rb_inorder_traverser(root, z -> right);
	
	return(root);
}

Treeptr left_rotate(Treeptr root, Treeptr x){
	Treeptr y;
	
	y = x -> right;
	x -> right = y -> left;
	if(y -> left != Tnil)
		y -> left -> parent = x;
	y -> parent = x -> parent;
	if(x -> parent == Tnil)
		root = y;
	else if(x -> parent -> left == x)
		x -> parent -> left = y;
	else
		x -> parent -> right = y;
	y -> left = x;
	x -> parent = y;
	return(root);
}

Treeptr right_rotate(Treeptr root , Treeptr x){
	Treeptr y;
	
	y = x -> left;
	x -> left = y -> right;
	if(y -> right != Tnil)
		y -> right -> parent = x;
	y -> parent = x -> parent;
	if(x -> parent == Tnil)
		root = y;
	else if(x -> parent -> left = x)
		x -> parent -> left = y;
	else
		x -> parent -> right = y;
	y -> right = x;
	x -> parent = y;
	return(root);
}
		
	
	

Treeptr rb_insert_node_fixup(Treeptr root, Treeptr new){
	Treeptr z, y;
	
	z = new;
	while(z -> parent -> color == 'R'){
		if(z -> parent == z -> parent -> parent -> left){
			y = z -> parent -> parent -> right;
			if(y -> color == 'R'){
				z -> parent -> color = 'B';
				printf("%\nld\n", z -> key);
				y -> color = 'B';
				z -> parent -> parent -> color = 'R';
				z = z -> parent -> parent;
			}
			else if(z -> parent -> right == z){
				z = z -> parent;
				root = left_rotate(root, z);
			}
			z -> parent -> color = 'B';
			z -> parent -> parent -> color = 'R';
			root = right_rotate(root, z -> parent -> parent);
		}
		else{
			y = z -> parent -> parent -> left;
			if(y -> color == 'R'){
				z -> parent -> color = 'B';
				y -> color = 'B';
				z -> parent -> parent -> color = 'R';
				z = z -> parent -> parent;
			}
			else if(z -> parent -> left == z){
				z = z -> parent;
				root = right_rotate(root, z);
			}
			z -> parent -> color = 'B';
			z -> parent -> parent -> color = 'R';
			root = left_rotate(root, z -> parent -> parent);
		}
	}
	root -> color = 'B';
	return(root);
}				

Treeptr rb_insert_node(Treeptr root, long int  val){
	Treeptr new, x, y;

	new = (Treeptr)malloc(sizeof(Treenode));
	assert(new != NULL);
	new -> key = val;
	new -> color = 'R';
	new -> left = Tnil;
	new -> right = Tnil;

	x = root;
	y = root;
	while(x != Tnil){
		y = x;
		if(x -> key >= val)
			x = x -> left;
		else
			x = x -> right;
	}
	new -> parent = y;
	if(y == Tnil)
		root = new;
	else if(y -> key  >= val)
		y -> left = new;
	else
		y -> right = new;
	root = rb_insert_node_fixup(root, new);
	return(root);
}

int main(){
	int n;
	long int val;
	Treeptr root;

Tnil = (Treeptr)malloc(sizeof(Treenode));

Tnil -> key = 0;
Tnil -> color = 'B';
Tnil -> left = NULL;
Tnil -> right = NULL;
Tnil -> parent = NULL;

printf("\nEnter 1 to insert node in rb, 2 to inoder traverser, other  to exit:");
		scanf("%d", &n);

	root = Tnil;
	do{
		
		switch(n){
			case 1:
				printf("\nEnter key of node to be inserted:");
				scanf("%ld", &val);
				root = rb_insert_node(root, val);
				break;
			case 2:
				printf("\nInorder traverser is:");
				root = rb_inorder_traverser(root, root);
				break;
			default:
				return(0);
		}
		printf("\nEnter 1 to insert node in rb, 2 to inoder traverser:");
		scanf("%d", &n);
	}while(n <= 2);
	return(0);
}
