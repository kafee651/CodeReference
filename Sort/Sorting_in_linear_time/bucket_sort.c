#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define M 600

typedef struct lnode * pnode;

struct lnode {
	float info;
	pnode ptr;
}node;

void insert_in_sortted(float a[], pnode b[], long int i, long int n){
	pnode ptr1, new, preptr;
	long int temp;
	
	temp = n * a[i];
	ptr1 = b[temp]; 
	new = (pnode)malloc(sizeof(node));
	assert(new != NULL);
	new -> info = a[i];
	new -> ptr = NULL;
	if(ptr1 == NULL){
		b[temp] = new;
		return;
	}
	if(ptr1 -> ptr == NULL && ptr1 -> info >= a[i]){
		new -> ptr = ptr1;
		b[temp] = new;
		return;
	}
	preptr = ptr1;
	while(ptr1 -> ptr != NULL  &&  ((ptr1 -> info) <= a[i])){
		preptr = ptr1;
		ptr1 = ptr1 -> ptr;
	}
	if(ptr1 -> ptr == NULL && ptr1 -> info >= a[i]){
		new -> ptr = ptr1;
		preptr -> ptr = new;
	}else if(ptr1 -> ptr == NULL){
		ptr1 -> ptr = new;
	}
	else{
		new -> ptr = ptr1 -> ptr;
		preptr -> ptr = new;
	}
	return;
}

void display_b(pnode a){
	pnode ptr1;

	if(a == NULL)
		return;
	else{
		ptr1 = a;
		while(ptr1 != NULL){
			printf("%f\t", ptr1 -> info);
			ptr1 = ptr1 -> ptr;
		}
	}
	return;
}

void display(pnode b[], long int n){
	long int i;

	for(i = 0;i < n;i++)
		display_b(b[i]);
	return;
}		
		
	
void bucket_sort(float a[], long int n){
	pnode b[M];
	long int i, j;
	
	for(i = 0;i < n;i++)
		b[i] = NULL;
	for(i = 1;i <= n;i++)
		insert_in_sortted(a, b, i, n);
	display(b, n);	

	return;
}
int main(){
	long int n, i, j;
	float a[M];

	scanf("%ld", &n);
	for(i = 1;i <= n;i++)
		scanf("%f", &a[i]);
	bucket_sort(a, n);

	return(0);
}
