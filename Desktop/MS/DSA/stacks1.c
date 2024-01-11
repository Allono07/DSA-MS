#include <stdio.h>
#include <stdlib.h> 
#define N 5
int stack[N];
int top =-1;
void push();
void pop();
void peak();
void display();
void isEmpty();
void isFully();
void size();

int main(){
int choice;
printf("Enter the choice: \n 1. Insert \n2.Delete \n3.Top Element \n4. Display\n5. checkEmpty() \n6. checkFull() \n7. checkSize(); ");
scanf("%d",&choice);
while (choice!=0){
switch (choice)
{
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
    isFully();
    break;
case 7: 
    size();
    break;           
default:
    printf("Invalid choice");
    break;
}

}

}

void push(){
    int x;
    printf("Enter the data");
    scanf("%d",& x);
    if(top == N-1){
        printf("Over flow condition");
    }
    else{
        top++;
        stack[top]=x;
        main();
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("Unerflow condition");
        
    }
    else 
    {
        item = stack[top];
        top--;
        printf("The popped value is %d", item);
    }
}

void peak(){
    if (top==-1)
    {
        printf("There is no topmost element, the stack is empty");

    }
    else{
        printf("%d",top);
    }
    
}

void display(){
        int i;
        for(i=top;i>=0;i--){
            printf("%d",top);
        }
}

void isEmpty(){
    if(top==-1){
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
}
void isFully(){
    if(top==N-1)
    {
        printf("The stack is full");
    }
    else 
    {
        printf("The stack is not full");
    }
}

void size(){
    int size = top-1;
    printf("The size of the stack is %d",size);

}