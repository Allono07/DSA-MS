#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* prev, * next;
};

struct node* start = NULL;

struct node* traverse(struct node* start) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return start;
    }

    struct node* temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
    return start;
}

struct node* insertAtFront(struct node* start) {
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;

    temp->next = start;
    if (start != NULL)
        start->prev = temp;

    start = temp;
    return start;
}

struct node* insertAtEnd(struct node* start) {
    int data;
    struct node* temp, * trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    trav = start;

    if (start == NULL) {
        start = temp;
    }
    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
    return start;
}

struct node* insertAtPosition(struct node* start) {
    int data, pos, i = 1;
    struct node* temp, * newnode;

    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (start == NULL) {
        start = malloc(sizeof(struct node));
        start->prev = NULL;
        start->next = NULL;
    }
    else if (pos == 1) {
        start = insertAtFront(start);
    }
    else {
        newnode = malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->prev = NULL;

        printf("\nEnter number to be inserted: ");
        scanf("%d", &data);
        newnode->info = data;
        temp = start;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newnode;
        temp->next = newnode;
    }
    return start;
}

struct node* deleteFirst(struct node* start) {
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
    return start;
}

struct node* deleteEnd(struct node* start) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return start;
    }

    struct node* temp = start;

    if (temp->next == NULL) {
        start = NULL;
        free(temp);
        return start;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);

    return start;
}

struct node* deletePosition(struct node* start) {
    int pos, i = 1;
    struct node* temp;

    if (start == NULL)
        printf("\nList is empty\n");
    else {
        printf("\nEnter position : ");
        scanf("%d", &pos);

        if (pos == 1) {
            start = deleteFirst(start);
        }
        else {
            temp = start;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }

            struct node* position = temp->next;
            if (position->next != NULL)
                position->next->prev = temp;
            temp->next = position->next;

            free(position);
        }
    }
    return start;
}

int main() {
    int choice;
    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            start = traverse(start);
            break;
        case 2:
            start = insertAtFront(start);
            break;
        case 3:
            start = insertAtEnd(start);
            break;
        case 4:
            start = insertAtPosition(start);
            break;
        case 5:

            start = deleteFirst(start);
            break;
        case 6:
            start = deleteEnd(start);
            break;
        case 7:
            start = deletePosition(start);
            break;

        case 8:
            exit(0);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}
