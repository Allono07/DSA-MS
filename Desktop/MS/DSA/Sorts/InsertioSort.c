#include<stdio.h>
#include<stdlib.h>
#define N 5
int main()
{
int arr[N]= {4,1,6,9,2};
for(int i=1;i<N;i++){

int temp=arr[i];
int j=i-1;
while(j>=0 &&arr[j]>temp){
    arr[j+1]=arr[j];
    j--;
}
arr[j+1]=temp;

}
printf("Sorted array is");
for(int i=0;i<N;i++){
    printf("%d", arr[i]);
}
return 0;
}