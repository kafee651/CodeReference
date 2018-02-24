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

long int graph[M][M], dist[M], pre[M], queue[M], front = 0, end = 0;;
char color[M];

void insert(long int m){
	
	if(end == (M - 1)){
		printf("\nQueue is full :");	
		exit(1);
	}
	else if((front == end) && (end == 0)){
		queue[++front] = m;
		end++;
	}
	else
		queue[++end] = m;
	return;
}

long int delete(){
	long int temp;

	temp = front;
	if(front == 0){
		printf("\nNo any element in queue:");
		exit(1);
	}
	else if(front == end){
		end = front = 0;
		return(queue[temp]);
	}
	else
		return(queue[front++]);
}

void print_path(long int l){
	long int i, j, k;

	if(pre[l] == 0)
		printf("\nNo path");	
	while(pre[l] != 0){
		printf("%ld\t", pre[l]);
		l = pre[l];
	}
	return;
}

void bfs(long int n, long int v){
	long int i, j, k;
	
	for(i = 1;i <= n;i++){
		color[i] = 'W';
		dist[i] = M;
		pre[i] = 0;
	}
	color[v] = 'G';
	dist[v] = 0;
	pre[v] = 0;
	insert(v);
	while(front != 0){
		k = delete();
		printf("%ld\t", k);
		for(i = 1;i <= n;i++){
			if(graph[k][i] == 1 && color[i] == 'W'){
				pre[i] = k;
				dist[i] = dist[k] + 1;
				color[i] = 'G';
				insert(i);
			}
		}
		color[k] = 'B';
	}
	return;
}
	
int main(){
	long int i, j, k, n, m, e, v, l;

	scanf("%ld", &n);
	for(i = 1;i <= n;i++)
		for(j = 1;j <= n;j++)
			scanf("%ld", &graph[i][j]);
	do{
//		printf("\nEnter node form where Breadth first search is started:");
		scanf("%ld", &v);
		bfs(n, v);
//		printf("\nEnter node to which shortest distance is to find");
		scanf("%ld", &l);
		print_path(l);
		if(dist[l] < M)
			printf("\nShortest distance is %ld", dist[l]);
		else
			printf("NO shortest distance ");
		printf("\nWant to again search enter 1 otherwise other:");
		scanf("%ld", &m);
	}while(m == 1);
	return(0);
}
