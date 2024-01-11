#include <stdio.h>
#include <stdlib.h> 



void main(){


int a = 5;
int *p=&a;
int **q=&p;
int ***r=&q;
printf("a=%d\n",a);
printf("a= %d\n",*p);
printf("address of  a= %d\n",p);
printf("address of a =%d\n",*q);
printf("a= %d\n",**q);
printf("address of p =%d\n",q);
printf("address of q=%d\n",r);
printf("a=%d\n",***r);
}