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
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
 }
//Case1 Deleting the first element from the list
 struct Node * deleteFirst(struct Node* head){
    struct Node* ptr = head;
    head=head->next;
    free(ptr);
    return head;
 }

// Case2 Deleting element at  a given idex
struct Node* linkedlistDeleteAtIndex(struct Node* head, int index){
    struct Node* p =head;
    struct Node*q = head->next;
    int i =0;
    while(i!=index-1){
        q=q->next;
        p=p->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

//case 3 deleting at the end of a linkedList

struct Node * deleteAtEnd(struct Node * head){
    struct Node * p=head;
    struct Node * q=head->next;

    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }

    p->next=NULL;
    free(q);
    return head;
}

//case 4 deleting for a given value

struct Node* deleteAtAGivenValue(struct Node *head, int data) {
    struct Node *q = head->next;
    struct Node *p = head;

    while (q != NULL && q->data != data) {
        q = q->next;
        p = p->next;
    }

    if (q != NULL) {
        p->next = q->next;
        free(q);
    }

    return head;
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

    printf("linkedlist before deletion\n");
    linkedlistTraversal(head);
   // head = deleteFirst(head);

//     printf("linkedlist after deletion\n");
//    linkedlistTraversal(head);

//    head = linkedlistDeleteAtIndex(head,2);
//    printf("linkedlist after deletion at an Index\n");
//    linkedlistTraversal(head);
   
//    head = deleteAtEnd(head);
//    printf("Linkedlist after deletion at the End\n");
//    linkedlistTraversal(head);

   head = deleteAtAGivenValue(head,211);
   printf("LinkedList after deleting the node at a given value\n");
   linkedlistTraversal(head);

 }