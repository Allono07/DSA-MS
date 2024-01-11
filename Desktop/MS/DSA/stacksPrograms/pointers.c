#include<stdio.h>
int main(){
    int a =10, b=20;
    int *p, *q;
    p=&a;
    //*q=b; 
    //printf("%d",*q);

    q=&b;
    printf("\n%d",q);
    printf("\n%d",*q);
    *q=*p;
    printf("\n%d", p);
    printf("\n%d",*q);
  printf("The value in p %d",*p);
}
