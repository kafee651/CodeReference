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

#define M 100
#define INFINITE M * 2

typedef struct node * Hashptr;

typedef struct node{
	long int key;
	Hashptr ptr;
}Hashnode;

void insert_hash_table(Hashptr hash[], long int val){
	Hashptr new, temp, x;
	long int i, j;

	i = val % M;
	if(hash[i] -> key == INFINITE)
		hash[i] -> key = val;
	else{
		temp = hash[i];
		new = (Hashptr)malloc(sizeof(Hashnode));
		assert(new != NULL);
		new -> ptr = NULL;
	
		x = temp;
		while(temp -> ptr != NULL){
			temp = temp -> ptr;
		}
		temp -> ptr = new;
		new -> key = val;
	}
	return;
}
void search_hash_table(Hashptr hash[], long int val){
	Hashptr new, temp, x;
	long int i, j;

	i = val % M;
	if(hash[i] -> key == INFINITE)
		printf("nNo such number prasent");
	else{
		temp = hash[i];
		while(temp -> ptr != NULL){
			if(temp -> key == val){
				printf("\nNo. is prasent");
				break;
			}
			temp = temp -> ptr;
		}
		if(temp -> key == val)
			printf("\nNo. is prasent");
		else
			printf("\nNo such no is prasent");
	}
	return;
}
int main(){
	int n;
	long int val, i, j;
	Hashptr hash[M], temp;

	for(i = 0;i < M;i++){
		hash[i] = (Hashptr)malloc(sizeof(Hashnode));
		hash[i] -> key = INFINITE;
		hash[i] -> ptr = NULL;
	}  
	printf("\nEnter 1 to insert no. in hash tabe: and 2 to search:");
	scanf("%d", &n);	
	do{
		
		switch(n){
			case 1:
				printf("\nEnter no to be hashed:");
				scanf("%ld", &val);
				insert_hash_table(hash, val);
				break;
			case 2:
				printf("\nEnter no. to be searched:");
				scanf("%ld", &val);
				search_hash_table(hash, val);
				break;
			default:
				exit(0);
		}
		printf("\nEnter 1 to insert no. in hash tabe: and 2 to search:");
		scanf("%d", &n);
	}while(n <= 2);
	return(0);
}
