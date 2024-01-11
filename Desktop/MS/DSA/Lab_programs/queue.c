#include <stdio.h>
#define N 5
int queue[N];
int front=-1,rear = -1;
void enqueue(int x){
    if(rear == N-1){
        printf("\n Overflow condition");
    }
    else if(rear==-1 && front ==-1){
        rear = front = 0;
        queue[rear]=x;
        printf("%d",queue[rear]);
    }
    else {
        rear++;
        queue[rear]=x;
        printf("%d",queue[rear]);
    }
}
void isEmpty(){
 if(front==rear){
    printf("The queue is Empty\n");
 }   
 else
 {
    printf("The queue is not Empty\n");
 }
}
void dequeue(){
    if(rear == -1 && front == -1){
        printf("\nUnderflow condition");
    }
    else if(rear==front){
        rear = front= -1;
    }
    else {
        printf("\nThe dequeued element is %d", queue[front]);
        front++;
    }
   
}
void display(){
    if( front == -1 && rear ==-1){
        printf("\n Underflow condition");
    }
    else {
        printf("\n");
        for(int i=front;i<rear+1;i++){
            printf("%d",queue[i]);
        }
    }
}
void peak(){
    if (front ==-1 && rear ==-1){
        printf("\n This is a underflow condition");
    }
    else {
        printf("\n%d",queue[front]);
    }
}

void isFull(){
    if(rear==N-1){
        printf("The queueu is full\n");
    }
}
void main(){
    isEmpty();
    for(int i=0;i<5;i++){
        enqueue(i);
    }
    isFull();
    dequeue();
    display();

    peak();
}