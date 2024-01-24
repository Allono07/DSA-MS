#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next, *prev;
};

struct node * head = NULL;

void traverse(){
    if(head == NULL){
        printf("List is Empty");
        return;
    }
struct node * temp = head;
while(temp!=NULL){
    printf("%d", temp->data);
    temp=temp->next;
}
}

void insertAtFront(){
    int data;
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value that needs to be entered");
    scanf("%d", &data);
    temp->data =data;
    temp->next= head;
    temp->prev=NULL;
    head = temp;
    
}

void insertAtEnd(){
    int data;
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    struct node * last = head;
    temp->data=data;
    temp->next= NULL;

    if(head==NULL){
      head = temp;
    }
    else{
    while(last->next!= NULL){
        last=last->next;
    }
    temp->prev=last;
    last->next = temp;
}
}


void insertAtPosition(){
    int data, pos, i=1;
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    struct node * temp = head;
    newNode->data = data;


    printf("Enter the position");
    scanf("%d",&pos);

    if(head == NULL){
        head = newNode;
        newNode->next= NULL;
        newNode->prev= NULL;
    }

      else if(temp == NULL || temp->next == NULL){
    printf("The entered position is invalid");
}

    else if(pos== 1){
        insertAtFront();
    }

    else {
        printf("Enter the number to be inserted ");
        scanf("%d", &data);
        newNode->data = data;
        while(i<pos-1){
            temp = temp ->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        temp->next->prev = newNode;
    }
}

void deleteFirst(){
     struct node * temp;
    if(head== NULL){
        printf("The list is empty");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteAtEnd(){
    struct node * ptr = head;
    struct node * last = head->next;
    if (head == NULL){
        printf("The linked list is empty");
    }
    if(last == NULL){
       head=NULL;
       free(ptr);

    }
    else{
 while(last->next!=NULL){
        last=last->next;
        ptr = ptr->next;
    }
    free(last);
    ptr->next= NULL;
    }
   
   
}

void deleteAtPostion(){
int pos,i=1;
struct node * ptr = head;
struct node* toDelete;
if(head==NULL){
    printf("The linked list is empty");
    return;
}
printf("Enter the position that you want to delete");
scanf("%d",&pos);


if(pos==1){
    deleteFirst();
}

else{
    while(i<pos-1 && ptr!=NULL){
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL || ptr->next == NULL){
    printf("The entered position is invalid");
}

else{
    toDelete = ptr->next;
    ptr->next = toDelete->next;
    if(toDelete->next!=NULL){
        toDelete->next->prev=ptr;
    }

    free(toDelete);
}
}




}

void main(){
    int choice;
   

    while(1){
         printf("\n 1.Insert into linkedlist \n 2.Insert first \n 3.insert last \n 4.insert random \n 5.delete from first \n 6.deleteAtEnd \n7.Display linkedlist \n 8.Delete Random\n");
    scanf("%d", &choice);
        switch(choice){
            case 1:
                insertAtFront();
                break;
             case 2: 
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4: 
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                traverse();
                break;
            case 8:
                deleteAtPostion();
                break;    
            default:
                printf("Entered option is incorrect");         
                break;
        }
    }
}