#include <stdio.h> 
#include <assert.h>

/* Variables*/
typedef struct node {
        int value; 
        struct node *next; 
}mynode; /* Globals. */

mynode *head, *tail, *temp; 
/* Functions */
void add(int value); 
void reverse_recurse(mynode *root); 
void print_list(); 

/* The main() function */
int main() {
     head=(mynode *)0; 
     
     /* Construct the linked list. */
     add(1); 
     add(2); 
     add(3); 
     add(4);
     add(5);
     /*Print it*/ 
     print_list(); 
     /* Reverse it. */
     if(head != (mynode *)0) { 
             reverse_recurse(head); 
             /*temp->next = (mynode *)0; */
     } 
     /*Print it again */
     print_list(); 
     getch();
     return(0); 
} 
/* Reverse the linked list recursively 
   This function uses the power of the stack to make this 
   *magical* assignment
   node->next->next=node; // // :)*/ 
void reverse_recurse(mynode *root) {
         if(root->next!=(mynode *)0) {
                                reverse_recurse(root->next); 
                                root->next->next=root; 
                                root -> next = NULL;
         } else { 
                  head=root; 
         } 
} 

/* Function to add new nodes to the linked list.*/ 
void add(int value) { 
     
     temp = (mynode *) malloc(sizeof(struct node));
     assert(temp != NULL);
     temp->next=(mynode *)0; 
     temp->value=value; 
     if(head==(mynode *)0) { 
                      head=temp; 
                      tail=temp; 
     }
     else {
          tail->next=temp; 
          tail=temp; 
     } 
} 

/* Function to print the linked list.*/ 
void print_list() { 
     printf("\n\n"); 
     for(temp=head;temp!=(mynode *)0;temp=temp->next){ 
                      printf("[%d]->",(temp->value));
     } 
                      printf("[NULL]\n\n"); 
}
