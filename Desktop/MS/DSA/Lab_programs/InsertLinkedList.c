#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*next;
};

 void linkedlistTraversal(struct Node *ptr)
 {
    while(ptr!=NULL){
        printf("Element %d\n ",ptr->data);
        ptr=ptr->next;
    }
 }
struct Node * insertAfterNode(struct Node* head, struct Node* prevNode, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data= data;
    ptr->next=prevNode->next;
    prevNode->next = ptr;

    return head;

}
struct Node * insertAtEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data= data;
    struct Node* p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

}
 struct Node* inserAtBeginning(struct Node* head, int data){
   struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   ptr->data=data;
   ptr->next=head;
   head=ptr;
   return head;
 }

 struct Node* insertAtIndex(struct Node*head, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->data=data;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    
    ptr->next=p->next;
    p->next=ptr;
    return head;
 }
 

int main(){
     struct Node * head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data=9;
    head->next=second;
    second->data=7;
    second->next=third;
    third->data=12;
    third->next=fourth;
    fourth->data=23;
    fourth->next=NULL;
    printf("Linked List before insertion\n");
    linkedlistTraversal(head);
     printf("Linked list after adding the Node to Node");
    head=insertAfterNode(head,second,44);
    linkedlistTraversal(head);
    printf("Linked List after insertion at the begining\n");
    head = inserAtBeginning(head, 22);
    linkedlistTraversal(head);
     printf("Linked List after insertion at the index\n");
    head = insertAtIndex(head,21,2);
    linkedlistTraversal(head);
    printf("Linked List insertion at the end\n");
    head = insertAtEnd(head,45);
    linkedlistTraversal(head);
   
    return head;
}