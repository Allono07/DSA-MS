#include <stdio.h>
#include <stdlib.h>


void enqueue();
void dequeue();
void show();
void isEmpty();
void isFull();
void size();
void peek();

int *inp_array;
int rear = -1;
int front = -1;
int size1;



int main()
{
    printf("Enter the size of the queue ");
    scanf("%d", &size1);

    inp_array = (int *)malloc(size1 * sizeof(int));

    int choice;

    while (1)
    {
        printf("\n Select the operation you want to perform for Stack \n\n");
        printf("Press 1 - inserting a value using enqueue() function \n");
        printf("Press 2 - deleting a value using dequeue() function \n");
        printf("Press 3 - To view all the elements in the queue using show() function \n");
        printf("Press 4 - checking if the queue is empty using isEmpty() function \n");
        printf("Press 5 - checking if the queue is full using isFull() function \n");
        printf("Press 6 - checking the size of queue using size() function \n");
        printf("Press 7 - To check the value at rear in the queue \n");
        printf("Press 8 - Exit the program \n");

        printf("Enter the choice here : ");
        scanf("%d", &choice);
        int value;

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            show();
            break;

        case 4:
            isEmpty();
            break;

        case 5:
            isFull();
            break;

        case 6:
            size();
            break;
        case 7:
            peek();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("You have entered a wrong choice \n");
            break;
        }
    }
}




void enqueue()
{
    int element;
    if (rear == size1-1)
    {
        printf("\n Overflow happened");
    }
    else
    {

        if (front == -1)
            front = 0;

            printf("\n Enter the element to be inserted in the queue :");
            scanf("%d", &element);
            rear = rear + 1;
            inp_array[rear] = element;
        
    }
}

void dequeue()
{

    if (front == -1)
    {
        printf("\n Underflow happened");
    }
    else
    {
            printf("\n \n Element deleted from the queue : %d", inp_array[front]);
            front = front + 1;
            if (front > rear)
            {
                front = -1;
                rear = -1;
            }
        
    }
}


void show(){

    if(front == -1){
        printf("\n\n Queue is no elements and is empty \n");
    }
    else {
       printf("\n All queue elements are : \n");
       for( int i = front; i <= rear; i++){
        printf("\n %d", inp_array[i]);
       }
    }
}

void isEmpty()
{
    if (rear == -1)
    {
        printf("\n Queue is empty");
    } 
    else {
         printf("\n Queue has some elements");
    }
}

void isFull()
{
    if (rear == size1-1)
    {
        printf("\n Queue is full");
    }
     else {
         printf("\n Queue have space for elements to be stored ");
    }
}

void peek()
{
    if (rear == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n Queue last element is %d", inp_array[rear]);
    }
}

void size()
{
    printf("\n Queue size is : %d", size1);
}