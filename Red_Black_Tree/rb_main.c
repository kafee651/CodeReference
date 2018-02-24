#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TNIL.h"

int main(){
	int n;
	long int val;
	Treeptr root;

	root = Tnil;
	do{
		printf("\nEnter 1 to insert node in rb, 2 to inoder traverser, other  to exit:");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("\nEnter key of node to be inserted:");
				scanf("%ld", val);
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
