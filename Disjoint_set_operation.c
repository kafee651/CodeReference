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

typedef struct disjoint_set * Disjoint_listptr;

typedef struct disjoint_set{
        int vertex;
        Disjoint_listptr head, next, tail;
}Disjoint_listnode;

int main(){
    Disjoint_listptr set[M], oldhead, oldtail;
    int i, j, k, n, e, e1, e2, count;
    
    printf("\nEnter numbers of vertices:");
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
          set[i] = (Disjoint_listptr)malloc(sizeof(Disjoint_listnode));
          assert(set[i] != NULL);
          set[i] -> vertex = i;
          set[i] -> head = set[i];
          set[i] -> next = NULL;
          set[i] -> tail = set[i];
    }
    printf("\nEnter numbers of edges:");
    scanf("%d", &e);
    for(i = 1;i <= e;i++){
          printf("\nEnter edge vertices:");
          scanf("%d%d", &e1, &e2);
          if(set[e1] -> head != set[e2] -> head){
                     oldhead = set[e2] -> head;
                     oldtail = set[e1] -> head -> tail;
                     oldtail -> next = oldhead;
                     set[e1] -> head -> tail = oldhead -> tail;
                     while(oldhead != NULL){
                                   oldhead -> head = set[e1] -> head;
                                   oldhead = oldhead -> next;
                     }
          }
    }
    printf("\nNumbers of components are:");
    count = 0;
    for(i = 1;i <= n;i++){
          if(set[i] -> head == set[i])
                    count++;
    }
    printf("%d", count);
    getchar();
    getchar();
    return(0);
}
