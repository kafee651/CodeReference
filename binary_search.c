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

Treeptr tree_search(Treeptr root, long int k){
	
	if((root == NULL) || (root -> key == k))
		return(root);
	if(k < root -> key)
		return(tree_search(root -> left, k));
	else
		return(tree_search(root -> right,k));

}

Treeptr tree_search_iterative(Treeptr root, long int k){
	
	while((root != NULL) || (root -> key != k)){
		if(root -> key > k)
			root = root -> left;
		else
			root = root -> right;
	}
	return(root);

}
