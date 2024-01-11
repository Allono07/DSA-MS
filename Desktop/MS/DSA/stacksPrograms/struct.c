#include<stdio.h>
struct student {
    int rollno;
    char name[5];
    float marks;
};

void main(){
    struct student s1= {1,"Allen",12.2};
    struct student s2;
    printf("%s",s1.name);
    printf("\nPrinting the information for s\n");
    printf("%d %s %d \n",s1.rollno,s1.name,s1.marks);
    printf("Enter the roll no for s2");
    scanf("%d",&s2.rollno);
    printf("The roll no: for s2 is %d",s2.rollno);

}               