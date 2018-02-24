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
#include <time.h>
#include "TNIL.h"

Treeptr left_rotate(Treeptr root, Treeptr x){
	Treeptr y;
	
	y = x -> right;
	x -> right = y -> left;
	y -> left -> parent = x;
	if(x -> parent == Tnil){
		root = y;
		y -> parent = Tnil;
	}
	else if(x -> parent -> left == x){
		x -> parent -> left = y;
		y -> parent = x -> parent;
	}
	else{
		x -> parent -> right = y;
		y -> parent = x -> parent;
	}
	x -> parent = y;
	y -> left = x;
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
				y -> color = 'B';
				z -> parent -> parent -> color = 'R';
				z = z -> parent -> parent;
			}
			else if(z -> parent -> right == z){
				z = z -> parent;
				root = left_rotate(root, z);
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
	while(root != Tnil){
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
