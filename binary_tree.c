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



Treeptr insert(Treeptr root){
	Treeptr new, save;
	long int temp, key_new;
	
	temp = 0;
	new = (Treeptr)malloc(sizeof(Treenode));
	assert(new);
	new -> left = NULL;
	new -> right = NULL;
	printf("\nEnter key of node:");
	scanf("%ld", &key_new);
	new -> key = key_new;
	save = root;
	if(root == NULL)
		return(new);
	else
		while(1){
			if(root -> key >= key_new)
				if(root -> left == NULL){
					root -> left = new;
					temp = 1;
				}
				else
					root = root -> left;
			else	
				if(root -> right == NULL){
					root -> right = new;
					temp = 1;
				}
				else
					root = root -> right;
			if(temp == 1)
				break;
		}
	return(save);
}

void display(Treeptr parent){
	
	
	if(parent -> left != NULL)
		display(parent -> left);
	printf("%ld\t", parent -> key);
	if(parent -> right != NULL)
		display(parent -> right);
	return;
}


int main(){
	int n;
	long int k, val;
	Treeptr root, find;
	
	root = NULL;
	printf("\nEnter 1 to insert in tree, 2 to display, 3 to search, 4 for max and min and  5 to exit:");
		scanf("%d", &n);
	do{
		switch(n){
			case 1:
				printf("\nEnter value to be inseted:");
				scanf("%ld", &val);
				root =  insertnode(root, val);
				break;
			case 2:
				inorder_iterative(root);//display(root);
				break;
			case 3:
				printf("\nEnter value to search");
				scanf("%ld", &k);
				find = tree_search(root, k);
				printf("%p", find); 
				break;
			case 4:
				printf("Maximum:%ld\tMinimum:%ld", tree_max(root), tree_min(root));
				break;
			case 5: 
				printf("\nEnter value to be deleted:");
				scanf("%ld", &val);
				root = deletenode(root, val);
				break;
			case 6:
				return(0);
		}
		printf("\nEnter 1 to insert in tree, 2 to display and 3 to exit:");
		scanf("%d", &n);
	}while(n <= 5);
	return(0);
}	
		
		
