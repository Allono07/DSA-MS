/Program to accept the details of vehicles implementing priority queue using singly linked list/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct node // node of queue to store vehicle details
{
    char vname[25], regno[10];
    int priority;
    struct node* next;
};

struct queue // queue to store vehicle details
{
    struct node* front;
};

void init(struct queue* q) // to initialise queue
{
    q->front = NULL;
}

int isEmpty(struct queue* q) // to check if the queue is empty
{
    return q->front == NULL;
}

void enqueue(struct queue* q, char vname[25], char regno[10], int priority) // to insert values into queue
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // dynamically allocating node
    if (!newNode)
    {
        printf("\nMemory allocation failed!");
        return;
    }
    strcpy(newNode->vname, vname);
    strcpy(newNode->regno, regno);
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmpty(q) || priority < q->front->priority) // if queue is empty or the node to be inserted has lower priority than the one in the queue, it is added to the beginning
    {
        newNode->next = q->front;
        q->front = newNode;
    }
    else // if there are elements in the queue, traversal takes place to insert the new node at the right priority place after comparison
    {
        struct node* current = q->front;
        while ((current->next != NULL) && (current->next->priority <= priority))
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeue(struct queue* q) // to delete elements from the queue
{
    if (isEmpty(q))
    {
        printf("\nQueue is already empty!");
    }
    else
    {
        struct node* temp = q->front;
        printf("\nPriority : %d\nVehicle Name : %s\nVehicle Registration Number: %s\n", temp->priority, temp->vname, temp->regno);
        q->front = q->front->next;
        free(temp);
        printf("\nElement Deleted!");
    }
}

void display(struct queue* q) // to display all elements inside the queue
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty!");
    }
    else
    {
        struct node* current = q->front;
        while (current != NULL)
        {
            printf("\nPriority : %d\nVehicle Name : %s\nVehicle Registration Number: %s\n", current->priority, current->vname, current->regno);
            current = current->next;
        }
    }
}

void highpriority(struct queue* q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty!");
    }
    else
    {
        struct node* highPriorityElement = q->front; // the highest priority queue is stored in the first node
        printf("\nThe Most Prioritised Vehicle : ");
        printf("\nPriority : %d\nVehicle Name : %s\nVehicle Registration Number: %s\n", highPriorityElement->priority, highPriorityElement->vname, highPriorityElement->regno);
    }
}

void splitAndDisplay(struct queue* q)
{
    struct queue highQ, lowQ;
    init(&highQ);
    init(&lowQ);
    if (isEmpty(q))
    {
        printf("\nQueue is empty!");
    }
    else
    {
        struct node* current = q->front;
        while (current != NULL)
        {
            if (current->priority < 10)
                enqueue(&highQ, current->vname, current->regno, current->priority);
            else
                enqueue(&lowQ, current->vname, current->regno, current->priority);
            current = current->next;
        }

        printf("\nThe High Priority Queue : ");
        display(&highQ);
        printf("\nThe Low Priority Queue : ");
        display(&lowQ);
    }
}

void main()
{
    int priority;
    int i, choice;
    char vecname[25], vecrno[10];
    struct queue vehiclequeue;
    init(&vehiclequeue);
    do
    {
        printf("\n*** Vehicle Management Module ***\n");
        printf("\n1. Enter Vehicle Details\n2. Display Vehicle Details\n3. Display The Most Prioritised Vehicle\n4. Split into Two and Display\n5. Exit\nEnter your Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the Vehicle Details : ");
            for (i = 1; i <= 20; i++)
            {
                printf("\nEnter the Vehicle Name : ");
                scanf("%s", &vecname);
                printf("\nEnter the Vehicle Registration Number : ");
                scanf("%s", &vecrno);
                printf("\nEnter the Priority : ");
                scanf("%d", &priority);

                if (priority >= 1 && priority <= 20)
                {
                    enqueue(&vehiclequeue, vecname, vecrno, priority);
                }
                else
                {
                    printf("\nInvalid Priority!");
                }
            }
            break;
        case 2:
            printf("\nVehicle Details : ");
            display(&vehiclequeue);
            break;
        case 3:
            highpriority(&vehiclequeue);
            break;
        case 4:
            splitAndDisplay(&vehiclequeue);
            break;
        case 5:
            break;
        default:
            printf("\nEnter valid choice!");
            break;
        }
    } while (choice != 5);
}