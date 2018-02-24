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

#define M 100
#define INFINITE M * 2

typedef struct node * Graphptr;

typedef struct node{
	int key, dist, node_time_d, node_time_f, compo;
	char color;
	Graphptr ptr, pre;
}Graphnode;

int queue[M], front = 0, end = 0, node_time, component, count;

void push(int m){
	
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

int pop(){
	int temp;

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

void breadth_first(Graphptr graph[], int n, int m){
	Graphptr x;	
	int i, j, k;
	
	for(i = 1;i <= n;i++){
		graph[i] -> color = 'W';
		graph[i] -> pre = NULL;
		graph[i] -> dist = M;
	}
	graph[m] -> color = 'G';
	graph[m] -> dist = 0;
	graph[m] -> pre = NULL;
	push(m);
	while(front != 0){
		k = pop();
		x = graph[k];
		x = x -> ptr;
		printf("\t%d", k); 
		while(x != NULL){
			if(graph[x -> key] -> color == 'W'){
				graph[x -> key] -> color = 'G';
				graph[x -> key] -> dist = (graph[k] -> dist) + 1;
				graph[x -> key] -> pre = graph[k];
				push(x -> key);
			}
			x = x -> ptr;
		}
		graph[k] -> color = 'B';
	}
	return;
}	

void print_path(Graphptr graph[], int n, int m, int l){
	
	if(m == l)	
		printf("%d\t", m);
	else if(graph[l] -> pre == NULL)
		printf("\nNo path from %d to %d exists", m, l);
	else{
		print_path(graph, n, m, graph[l] -> pre -> key);
		printf("%d\t", l);
	}
	return;
} 

void dfs_visit(Graphptr graph[], int u, int v){
	Graphptr temp;
	
	node_time++;
	graph[u] -> node_time_d = node_time;
	graph[u] -> color = 'G';
	graph[u] -> compo = component;
	temp = graph[u];
	while(temp -> ptr != NULL){
		if(graph[temp -> ptr -> key] -> color == 'W'){
            if(temp -> ptr -> key == v)
                    count++;
			graph[temp -> ptr -> key] -> pre = graph[temp -> key];
			dfs_visit(graph, temp -> ptr -> key, v);
		}
		else if(graph[temp -> ptr -> key] -> color == 'G'){
            if(temp -> ptr -> key == v)
                    count++;
        }
        else if(graph[temp -> ptr -> key] -> node_time_d > graph[u] -> node_time_d){
                         if(temp -> ptr -> key == v)
                    count++;
        }
        else{
                         if(temp -> ptr -> key == v)
                    count++;
        }
		temp = temp -> ptr; 
	}
	graph[u] -> color = 'B';
	node_time++;
	graph[u] -> node_time_f = node_time;
	return;
}

void depth_first(Graphptr graph[], int n, int p, int v){
	int i, j, k;

	for(i = 1;i <= n;i++){
		graph[i] -> color = 'W';
		graph[i] -> pre = NULL;
	}
	count = 0;
	node_time = 0;
	dfs_visit(graph, p, v);
	printf("%d", count);
	return;
}
/*
void depth_first_iterative(Graphptr graph[], int n){
     int i, j, k;
     
     for(i = 1;i <= n;i++){
             graph[i] -> color = 'W';
             graph[i] -> pre = NULL;
     }
     node_time = 0;
     for(i = 1;i <= n;i++){
           if(graph[i] -> color == 'W'){ 
                       node_time++;
                       graph[i] -> color = 'G';
                       graph[i] -> node_time_d = node_time;
                       temp = graph[i];
                       while(temp -> ptr != NULL){
                                  if(graph[temp -> ptr -> key] -> color == 'W'){
                                          push(temp -> ptr -> key);
                                          graph[graph[i] -> ptr -> key] -> pre = graph[i];
                                  }
                                  temp = temp -> ptr;
                       }*/
int main(){
	int n, k, m, l, p, v;
	long int val, i, j;
	Graphptr graph[M], temp, new, x;

	printf("Enter numbers of node in graph:");
	scanf("%d", &n);
	for(i = 1;i <= n;i++){
		graph[i] = (Graphptr)malloc(sizeof(Graphnode));
		graph[i] -> key = i;
		graph[i] -> ptr = NULL;
		graph[i] -> color = 'W';
		graph[i] -> pre = NULL;
		graph[i] -> dist = M;
		printf("\nEnter number of node which are neighbour to %ldst node:", i);
		scanf("%d", &k);
		printf("\nEnter neighbour nodes:");
		x = graph[i];
		while(k--){
			new = (Graphptr)malloc(sizeof(Graphnode));
			assert(new != NULL);
			scanf("%d", &(new -> key));
			x -> ptr = new;
			new -> ptr = NULL;
			x = new;
		}
	}
	printf("\nEnter 1. for Breadth first search, 2. for Depth first search, and other for otherwise:");
	scanf("%d", &m);
	do{
		switch(m){
			case 1:
				printf("\nEnter node form where Breadth first search is started:");
				scanf("%d", &m);
				breadth_first(graph, n, m);
				printf("\nEnter node to which shortest distance is to find");
				scanf("%d", &l);
				print_path(graph, n, m, l);
				if(graph[l] -> dist < M)
					printf("\nShortest distance is %d", graph[l] -> dist);
				else
					printf("NO shortest distance ");
				break;
			case 2:
				printf("Depth first search is");
				scanf("%d%d", &p, &v);
				depth_first(graph, n, p, v);
				break;
		}
		printf("\nWant to again search enter 1 otherwise other:");
		scanf("%d", &m);
	}while(m <= 2);
	return(0);
}
