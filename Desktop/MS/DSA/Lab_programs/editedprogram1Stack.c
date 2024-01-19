#include <stdio.h>
#include <stdlib.h>

int *stack;  
int top = -1;
int size;

void push() {
    int x;
    printf("Enter the data: ");
    scanf("%d", &x);

    if (top == size - 1) {
        printf("Overflow condition\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow condition\n");
    } else {
        printf("The popped value is %d\n", stack[top]);
        top--;
    }
}

void peak() {
    if (top == -1) {
        printf("There is no topmost element, the stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void isEmpty() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("The stack is not empty\n");
    }
}

void isFull() {
    if (top == size - 1) {
        printf("The stack is full\n");
    } else {
        printf("The stack is not full\n");
    }
}

void getSize() {
    printf("The size of the stack is %d\n", top + 1);
}


int main() {
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));

    int choice;
    printf("\nEnter the choice:\n1. Insert\n2. Delete\n3. Top Element\n4. Display\n5. checkEmpty()\n6. checkFull()\n7. checkSize()\n0. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peak();
                break;
            case 4:
                display();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            case 7:
                getSize();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 0);

    // Free the dynamically allocated memory before exiting
    free(stack);

    return 0;
}

