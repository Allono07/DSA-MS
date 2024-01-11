#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    /* data */
};
 void linkedlistTraversal(struct Node *ptr)
 {
    while(ptr!=NULL){
        printf("%d\n ",ptr->data);
        ptr=ptr->next;
    }
 }

 void main(){
    struct Node * head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=7;
    second->next=third;
    third->data=12;
    third->next=fourth;
    fourth->data=23;
    fourth->next=NULL;

    linkedlistTraversal(head);
   
 }
 


