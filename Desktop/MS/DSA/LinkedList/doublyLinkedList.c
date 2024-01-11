#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};
struct Node * insertAtBeginning(struct Node * head, int data){
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->prev= NULL;
newNode->next=head;
if(head!=NULL){
    head->prev=newNode;
} 
return newNode;
}
struct Node* insertAtPosition(struct Node* head, int data, int position){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(position == 0){
        newNode->prev=NULL;
        newNode->next=head;
        if(head!=NULL){
            head->prev=newNode;
        }
        return newNode;
    }
    struct Node* temp = head;
    for(int i=0; i<position-1 && temp!=NULL;i++){
temp=temp->next;
    }
    if(temp==NULL){
        return head;
    }

    newNode->prev=temp;
    newNode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
    return head;
}
struct Node* insertAtEnd(struct Node* head,int data){
    struct Node* last = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
if(head==NULL){
    newNode->prev=NULL;
    return newNode;
}
    while(last->next!=NULL){
        last=last->next;
    }
    last->next = newNode;
    newNode->prev=last;
    return head;
}

void printLinkedList(struct Node* head){
    while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
    }
}

int main()
{
struct Node * head = NULL;
head =insertAtBeginning(head, 10);
head = insertAtBeginning(head, 20);
head = insertAtEnd(head, 40);
head = insertAtPosition(head, 50,0);
printLinkedList(head);

return 0;
}