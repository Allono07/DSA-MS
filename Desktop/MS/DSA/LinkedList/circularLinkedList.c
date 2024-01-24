#include<stdio.h>

struct  Node {
    int data;
    struct Node *next;

};

void linkedListTraversal(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("%d",ptr->data);
        ptr=ptr->next;
    }while(ptr->next!=head);
}

 struct Node * createNode(int data){
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next= NULL;
    head->data = data;

    return head; 
    }
    
int main()
{
   

return 0;
}