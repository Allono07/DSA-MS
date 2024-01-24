#include<stdio.h>
#include<stdlib.h>
struct Node * f=NULL;
    struct Node * r= NULL;

struct Node{
    int data;
    struct Node * next;
};
void linkedlistTraversal(struct Node* ptr){
    printf("printing the elements of the linked list\n");
    while(ptr!=NULL){
        printf("The element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is full");
    }

    else{
        n->data=val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else {
            r->next = n;
            r=n;
        }
    }
    
    }

    int dequeue(){
        int val=-1;
    struct Node *ptr;
    if(f==NULL){
        printf("Queue is Empty");
        return -1;
    }

    else{
        f=f->next;
        val = ptr->data;
        free(ptr);
    }

    return val;
    
    }
void isEmpty(){
    if (f == r){
        printf("the queue is empty");
    }

    else {
        printf("the queue is not empty");
    }
}

int main()
{
    
    linkedlistTraversal(f);
    printf("Dequeing element %d\n",dequeue());  
    isEmpty();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    linkedlistTraversal(f);

return 0;
}