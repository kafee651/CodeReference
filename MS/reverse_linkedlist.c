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

typedef struct node * Linklistptr;

typedef struct node{
        int key;
        Linklistptr ptr;
}Linklistnode;

Linklistptr insertnode(Linklistptr head){
            Linklistptr temp;
            int val;
            
            temp = (Linklistptr)malloc(sizeof(Linklistnode));
            assert(temp != NULL);
            printf("\nEnter value of linked list:");
            scanf("%d", &(temp -> key));
            temp -> ptr = NULL;
            if(head == NULL)
                    return(temp);
            else{
                    temp -> ptr = head;
                    return(temp);
            }
}
            
void printlinklist(Linklistptr head){
     while(head != NULL){
                printf("%d\t", head -> key);
                head = head -> ptr;
     }
     return;
} 

Linklistptr iterative_reverse(Linklistptr head){
            Linklistptr temp, next;
            
            if(head == NULL){
                    printf("No list is present to reverse");
                    return(head);
            }
            if(head -> ptr == NULL){
                    return(head);
            }
            temp = head;
            head = head -> ptr;
            temp -> ptr = NULL;
            while(head != NULL){
                       next = head -> ptr;
                       head -> ptr = temp;
                       temp = head;
                       head = next;
            }
            return(temp);
}

Linklistptr recursive_reverse(Linklistptr head){
            if(head == NULL)
                    return(head);
            else
                    temp = recursive_reverse(head -> ptr);
                    
int main(){
    Linklistptr head = NULL;
    int i, j, k, n;
    
    printf("\nEnter number of element in linklest:");
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
          head = insertnode(head);
    }
    printf("\nEnter linked list is:");
    printlinklist(head);
    head = iterative_reverse(head);
    printf("\nReverse linked list is:");
    printlinklist(head);
    head = recursive_reverse(head);
    getchar();
    getchar();
    return(0);
}
