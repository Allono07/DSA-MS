 #include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("Popped element: %d\n", pop());

    display();

    return 0;
}