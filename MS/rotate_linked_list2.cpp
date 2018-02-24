// Program to rotate a linked list counter clock wise
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
// This function rotates a linked list counter-clockwise and return new head.
// The function assumes tha k is smaller than size of linked list. It doesn't
// modify the list if k is greater than size
struct node *rotate (struct node *head, int k)
{
    // Let us understand the below code for example k = 4 and
    // list = 10->20->30->40->50->60.
    struct node* current = head;
 
    // current will either point to kth or NULL after this loop.
    //  current will point to node 40 in the above example
    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
 
    // If current is NULL, k is greater than or equal to count
    // of nodes in linked list. Don't change the list in this case
    if (current == NULL)
        return head;
 
    // current points to kth node. Store it in a variable.
    // kthNode points to node 40 in the above example
    struct node *kthNode = current;
 
    // current will point to last node after this loop
    // current will point to node 60 in the above example
    while (current->next != NULL)
        current = current->next;
 
    // Change next of last node to previous head
    // Next of 60 is now changed to node 10
    current->next = head;
 
    // Change head to (k+1)th node
    // head is now changed to node 50
    head = kthNode->next;
 
    // change next of kth node to NULL
    // next of 40 is now NULL
    kthNode->next = NULL;
 
    // Return new head.  Return pointer to 50
    return head;
}
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node1)
{
    int count = 0;
    while (node1 != NULL)
    {
        printf("%d  ", node1->data);
        node1 = node1->next;
        count++;
    }
}
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    printf("Given linked list \n");
    printList(head);
    head = rotate(head, 4);
 
    printf("\nRotated Linked list \n");
    printList(head);
    
    getch();
    return (0);
}
