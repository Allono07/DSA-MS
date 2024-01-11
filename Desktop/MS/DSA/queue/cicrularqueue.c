#include <stdio.h>
#define N 5
int queue[N];
int front,rear = -1;
void enqueue(int x){
    if (rear == -1 && front ==-1 ){
       front=rear=0;
       queue[rear]=x;
    }
    else if(((rear+1)%N)==front){
        printf("\n The queue is full");
    }
    else{
        rear = (rear+1)%N;
        queue[rear]=x;
    }
}

void dequeue(){
    if(rear,front==-1){
        printf("Underflow condition");
    }
    else if(rear==front){
        rear=front=-1;
    }
    else{
        printf("The dequeued element is %d",queue[front]);
        front = (front+1)%N;
    }

}

void main(){
    int y = 1%5;
    printf("%d",y);
}