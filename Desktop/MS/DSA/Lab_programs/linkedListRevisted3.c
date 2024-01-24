#include<stdio.h>

struct node {
    int data;
    struct node * next;
};

struct node * head = NULL;

void insertFirst();
void insertAtEnd();

int main()
{
printf("Enter the choide");
int choice;
scanf("%d", &choice);

while(1){
    switch(choice){
        case 1:
            insertFirst();
            break;
         case 2:
            insertAtEnd();
            break;
          case 0:
            exit(1);
            break;
          default:
          printf("Wrong choice");       
    }
}

return 0;
}

void insertFirst(){
    int data;
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value that needs to be inserted");
    scanf("%d",&data);
    newNode ->data= data;
    newNode->next = head;
    head = newNode;

}

void insertAtEnd(){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    struct node * last= head;
    int data;
    printf("Insert the data that needs to be insterted");
    scan("%d", &data);
    newNode->data= data;
    newNode->next = NULL;
    if(head == NULL){
      head= newNode;
    }

    else{
        while(last->next!=NULL){
            last = last->next;
        }
        last->next = newNode;
    }
}

void insertAtPosition(){
    int data, position,i;
    

}