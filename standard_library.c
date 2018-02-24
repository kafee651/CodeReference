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

typedef struct linklist * Linklistptr;

typedef struct linklist{
        int data;
        Linklistptr next;
}Linklistnode;

void push(Linklistptr *headRef, int Insert_data){
     Linklistptr newnode;
     
     newnode = (Linklistptr)malloc(sizeof(Linklistnode));
     assert(newnode != NULL);
     newnode -> data = Insert_data;
     newnode -> next = NULL;
     if(*headRef == NULL)
                 *headRef = newnode;
     else{
                 newnode -> next = *headRef;
                 *headRef = newnode;
     }
     return;
}

void printnode(Linklistptr head){
     Linklistptr current;
     
     printf("\n");
     for(current = head;current != NULL;current = current -> next)
                 printf("%d -> ", current -> data);
     printf("\b\b\b\b    ");
     return;
}

int Count(Linklistptr head, int searchfor){
     Linklistptr current;
     int count = 0;
     
     for(current = head;current != NULL;current = current -> next)
                 if(current -> data == searchfor)
                            count++;
     return(count);
}

int GetNth(Linklistptr head, int index){
     Linklistptr current;
     int count = 0;
     
     for(current = head;current != NULL && count < index;current = current -> next, count++);
     return(current -> data);
}

void Deletelist(Linklistptr *headRef){
     Linklistptr current = *headRef;
     Linklistptr next;
     
     while(current != NULL){
                 next = current -> next;
                 free(current);
                 current = next;
     }
     *headRef = NULL;
}

int Pop(Linklistptr *headRef){
    Linklistptr current = *headRef;
    int data_to_return;
    
    if(current == NULL){
               printf("\nNo linklist is present:");
               return(0);
    }
    else{
               data_to_return = current -> data;
               *headRef = current -> next;
               free(current);
               return(data_to_return);
    }
}

void InsertNthPosition(Linklistptr *headRef, int index, int insert_data){
     Linklistptr current = *headRef;
     int count;

     if(index == 0)
              push(headRef, insert_data);
     else{
              for(count = 0;count < index - 1;count++, current = current -> next,assert(current != NULL));
              assert(current != NULL);
              push(&(current -> next), insert_data);
     }
     return;
}
              
void SortedInsert(Linklistptr *headRef, int insert_data){
     Linklistptr current = *headRef;
     
     if(current == NULL || current -> data > insert_data)
                push(headRef, insert_data);
     else{
          while(current -> next != NULL && current -> next -> data < insert_data){
                   current = current -> next;
          }
          push(&(current -> next), insert_data);
     }
     return;
}

void Append(Linklistptr *aref, Linklistptr *bref){
     Linklistptr current = *aref;
     
     if(current == NULL){
                *aref = *bref;
                bref = NULL;
     }
     else{
                while(current -> next != NULL){
                              current = current -> next;
                }
                current -> next = *bref;
                bref = NULL;
     }
     return;
}

void SplitFrontBack(Linklistptr source, Linklistptr *frontRef, Linklistptr *backRef){
     Linklistptr slow, fast;
     
     if(source == NULL || (source -> next) == NULL){
                *frontRef = source;
                *backRef = NULL;
     }
     else{
                slow = source;
                fast = source -> next;
                while(fast != NULL){
                           fast = fast -> next;
                           if(fast != NULL){
                                      fast = fast -> next;
                                      slow = slow -> next;
                           }
                }
                *frontRef = source;
                *backRef = slow -> next;
                slow -> next = NULL;
     }
     return;
}

void RemoveDublicate(Linklistptr head){
     Linklistptr current = head;
     Linklistptr nextnode;
     
     if(current == NULL || current -> next == NULL)
                return;
     else{
                while(current -> next != NULL){
                              if(current -> data == current -> next -> data){
                                         nextnode = current -> next -> next;
                                         free(current -> next);
                                         current -> next = nextnode;
                              }
                              else
                                  current = current -> next;
                }
                return;
     }                 
}

void Movenode(Linklistptr *source, Linklistptr *destination){
     Linklistptr current = *source;
     
     assert(current != NULL);
     *source = current -> next;
     current -> next = *destination;
     *destination = current;
}

void AlternativeSplit(Linklistptr source, Linklistptr *aRef, Linklistptr *bRef){
     Linklistptr current = source;
     
     while(current != NULL){
                   Movenode(&current, aRef);
                   if(current != NULL)
                              Movenode(&current, bRef);
     }
     return;
}

void ReverseBackMiddleFront(Linklistptr *headRef){
     Linklistptr back, middle, front;
     
     if(*headRef != NULL){
                 middle = *headRef;
                 front = middle -> next;
                 back = NULL;
                 
                 while(1){
                          middle -> next = back;
                          back = middle;
                          if(front == NULL)break;
                          middle = front;
                          front = front -> next;
                 }
                 *headRef = middle;
     }
     return;
}

void IterativeReverse(Linklistptr *headRef){
     Linklistptr current, newlist;
     
     newlist = NULL;
     current = *headRef;
     while(current != NULL){
                 Movenode(&current, &newlist);
     }
     *headRef = newlist;
     return;
}
         
void RecursiveReverse(Linklistptr *headRef){
     Linklistptr first, rest;
     
     if(*headRef == NULL)
                 return;
     first = *headRef;
     rest = first -> next;
     if(rest == NULL)
                 return;
     RecursiveReverse(&rest);
     first -> next -> next = first;
     first -> next = NULL;
     *headRef = rest;
}

int main(){
    Linklistptr a, b;
    Linklistptr head = NULL;
    int i, j, k;
    
    a = b = NULL;
    for(i = 1;i <= 20;i++){
          SortedInsert(&head, i);
    }
    AlternativeSplit(head, &a, &b);
    printnode(a);
    printf("\n");
    ReverseBackMiddleFront(&b);
    printnode(b);
    IterativeReverse(&b);
    printnode(b);
    RecursiveReverse(&b);
    printnode(b);
    /*SplitFrontBack(head, &a, &b);
    Movenode(&a, &b);
    printnode(a);
    printf("\n");
    printnode(b);/*
    
    Append(&a, &b);
    printnode(a);/*
    printf("\nCount for 1 is:%d", Count(head, 1));
    printf("\nNth data is:%d", GetNth(head, 1));
    printf("\nPOP data:%d\n", Pop(&head));
    printnode(head);
    SortedInsert(&head, 12);
    InsertNthPosition(&head, 5, 12);
    printnode(head);*/
    getchar();
    return(0);
}
 
