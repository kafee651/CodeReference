#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <assert.h>

typedef struct linklist *Linklistptr;
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

void pushnode(Linklistptr *destination, Linklistptr *source){
     if(*destination == NULL){
                     *destination = *source;
                     (*destination) -> next = NULL;
     }
     else{
                     (*source) -> next = (*destination) -> next;
                     (*destination) -> next = *source;
     }
     return;
}

void sort3(Linklistptr *headRef, int length){
     Linklistptr current, zerolist, twolist, next;
     Linklistnode dummynode;
     
     dummynode.next = *headRef;
     current = &dummynode;
     zerolist = NULL;
     twolist = NULL;
     while(length--){
                     next = current -> next -> next;
                     if(current -> next -> data == 0){
                                pushnode(&zerolist, &(current -> next));
                                current -> next = next;
                     }
                     else if( current -> next -> data == 2){
                                pushnode(&twolist, &(current -> next));
                                current -> next = next;
                     }
                     else{
                                current = current -> next;
                     }
     }
     current -> next = twolist;
     current = zerolist;
     while(current -> next != NULL)
                   current = current -> next;
     current -> next = dummynode.next;
     *headRef = zerolist;
     return;
}
int main(){
    Linklistptr head = NULL;
    int n, i, e;
    
    printf("\nEnter number of Linklist node:");
    scanf("%d", &n);
    printf("\nEnter nodes:");
    for(i = 1;i <= n;i++){
          scanf("%d", &e);
          push(&head, e);
    }
    sort3(&head, n);
    printnode(head);
    getchar();
    getchar();
    return(0);
}
